#include "udpworker.h"
#include <QRandomGenerator>


UDPWorker::UDPWorker(QObject *parent, MemoryModel *memorymodel)
    : QObject{parent}
{
    model=memorymodel;

    // //add a dummy model to the list
    // m_data_models["dummy"] = new CustomDataModel();

}

void UDPWorker::start()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();

    udp_timer = new QTimer();
    // dummy = new QTimer();
    udp_socket = new QUdpSocket();
    udp_event_loop  = new QEventLoop();

    // Perform all signal slot connections
    connect(udp_timer, &QTimer::timeout, this, &UDPWorker::timeout);
    // connect(dummy, &QTimer::timeout, this, &UDPWorker::dummyTimeout);

    connect(udp_socket, &QUdpSocket::readyRead, this, &UDPWorker::readyread);
    udp_timer->setInterval(100);

    //TODO expose this to the GUI so that it can be changed in real time
    if(udp_socket->isOpen()){
        udp_socket->close();
    }
    if(!udp_socket->bind(QHostAddress(localIPAddr), udpPort)){
        qInfo()<<udp_socket->errorString();
        // return;
    }
    qInfo()<< "Started UDP on"<<udp_socket->localAddress() <<":"<<udp_socket->localPort();


    request_memory_table();
    emit newVariableRecieved("dummy");
    // dummy->start(100);
}

void UDPWorker::stop()
{
    if(udp_timer->isActive())udp_timer->stop();
    if(udp_socket->isOpen()) udp_socket->close();
//    m_variableValueMap.clear();
//    m_variable_names.clear();

    qInfo()<<"Closed socket and stopped timer";
}

// send the command data structures from time to time
void UDPWorker::timeout()
{
    memory_poll();
}

void UDPWorker::readyread()
{
    while(udp_socket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udp_socket->receiveDatagram();
        // reconstruct bytes
        QByteArray by = datagram.data();
        // qInfo()<<datagram.data();
        char cmd_type = by.at(0);


        switch (cmd_type) {
        case START_SYMBOL_MEM_RECORD:{
            mem_record_t mem_rec={};
            rebuild_memory_record(by, mem_rec);
            // QString s(mem_rec.name);
            // qInfo()<<"Received memory record: "<<s;
            memory_table[mem_rec.name] = mem_rec;
            memory_table_addr[mem_rec.address] = mem_rec; // for searching by address


            // create a memory model correponding to this data point
            // m_data_models[mem_rec.name] = new CustomDataModel();


            // prepare the qvariant required to update the table on the GUI
            QVariantMap recordMap;
            recordMap["name"]=QString::fromUtf8(mem_rec.name);
            recordMap["size"]=mem_rec.size;
            recordMap["type"]=(quint8)mem_rec.data_type;
            recordMap["attribute"]=(quint8)mem_rec.attribute;
            recordMap["address"]=mem_rec.address;

            // notify all objects bound to this model to call the model's update method
            emit newDataReceived(recordMap);

            // used for the tag bind page to populate the list of items
            m_variable_names.push_back(mem_rec.name);
            emit variableListChanged();

            // m_variableValueMap[mem_rec.name] = "";
            // emit vmapChanged();

            // ---- single data points check-----------------
            // m_data_models[mem_rec.name] = new CustomDataModel();
            // emit newVariableRecieved(mem_rec.name);
            // ----------------------------------------------



            break;
        }
        case START_SYMBOL_CMD:{

            // qInfo()<<"Received Command data";
            command_t input_command = rebuild_data(by);
            mem_record_t mem_rec = memory_table_addr[input_command.address];
            memory_addr_val_map[input_command.address].size = input_command.txrx_size;

            for(int i=0; i<input_command.txrx_size; i++){
                memory_addr_val_map[input_command.address].data[i] = input_command.data[i];
            }

            // convert the buffer to value
            QVariant value = convertBufferToString(input_command.data, input_command.txrx_size, mem_rec.data_type);

            // update the model
            // m_data_models[mem_rec.name]->setData(value);

            // ------ included this for control bindings ----
            m_variableValueMap[mem_rec.name] = value;
            emit vmapChanged();
            // ----------------------------------------------
            qInfo()<<mem_rec.name<<": "<<value;


            // update the tagtable
            QVariantMap recordMap;
            recordMap["name"]=QString::fromUtf8(mem_rec.name);
            recordMap["size"]=mem_rec.size;
            recordMap["type"]=(quint8)mem_rec.data_type;
            recordMap["attribute"]=(quint8)mem_rec.attribute;
            recordMap["address"]=mem_rec.address;
            recordMap["value"] = value;

            // notify all objects bound to this model to call the model's update method
            emit modifiedDataReceived(recordMap);

            emit updateVariableData(mem_rec.name, value);
            break;
        }
        default:
            qInfo()<<by<< " Invalid data received. dropping...";
            break;
        }

    }
}

QVariant UDPWorker::fetch(const QString &variableName)
{
    return m_data_models[variableName]->data();

}

void UDPWorker::request_memory_table()
{

    // prepare a command to be sent to the MCU
    command_t load_table_cmd={};
    char buffer[sizeof(load_table_cmd)];
    load_table_cmd.header.command_type = load;
    load_table_cmd.header.transaction_id =QRandomGenerator::global()->bounded(35567);

    serialize_cmd_struct(&load_table_cmd, (uint8_t *)buffer);
    QByteArray bf_bytearray (buffer, get_required_buffsize_from_cmdsize(load_table_cmd));
    QNetworkDatagram datagram(bf_bytearray,QHostAddress(remoteIPAddr),remotePort);
    qInfo() << "Requesting to load table \nCMD:" << bf_bytearray;
    qInfo()<<"Sending data to "<<remoteIPAddr<<" and port "<<remotePort<<"from IP: "<<localIPAddr<<" and port "<<udpPort<<"\n";
    udp_socket->writeDatagram(datagram);
}

void UDPWorker::memory_poll()
{
    static auto record_itr = memory_table.constBegin();
    // loop through the memory table

    if(record_itr !=memory_table.constEnd()){
        // prepare the corresponding read command
        mem_record_t record = record_itr.value();
        command_t cmd {};
        cmd.address = record.address,
        cmd.header.command_type = read;
        cmd.header.transaction_id = QRandomGenerator::global()->bounded(INT32_MAX);; /// randomize this next time
        memset((void *)cmd.data, 0, MAX_TXRX_SIZE);

        dt_map data_type = record.data_type;
        data_type == sU8 ? cmd.txrx_size=1: data_type == sU16 ? cmd.txrx_size=2 : data_type == sU32 ? cmd.txrx_size=4: cmd.txrx_size =8 ;

        // serialize the command
        char buffer[MAX_TXRX_SIZE];
        serialize_cmd_struct(&cmd, (uint8_t *)buffer);
        QByteArray bf_bytearray (buffer, get_required_buffsize_from_cmdsize(cmd));
        QNetworkDatagram datagram(bf_bytearray,QHostAddress(remoteIPAddr),remotePort);

        // qInfo()<<"Sending data to "<<remoteIPAddr<<" and port "<<remotePort<<"from IP: "<<localIPAddr<<" and port "<<udpPort<<"\n";
        udp_socket->writeDatagram(datagram);
        qInfo()<<"Polling "<< QByteArray(record.name) << "from MCU";

        record_itr++;
    }
    else{

        // qInfo("Sent polled all the data in the map\n");
        record_itr = memory_table.constBegin();
    }

}

void UDPWorker::addCommand(const QString &variablenName, const QString &objectName, const QString commandType)
{
    qInfo()<<"received binding request to add command for "<<objectName;

    if(objectName == "") return;

    mem_record_t mem_rec = memory_table[variablenName];
    Q_UNUSED(commandType)
    // prepare the command
    command_t *cmd = new command ();
    cmd->address = static_cast<qint32>(mem_rec.address),
    cmd->header.command_type = write;
    cmd->txrx_size = mem_rec.size;

    m_obj_sendcmd_map[objectName] = cmd;
}

//send command to MCU
void UDPWorker::sendCommandToMCU(const QString &objectName, const QVariant &data)
{
    if(m_obj_sendcmd_map.find(objectName) == m_obj_sendcmd_map.end()) return;

    command_t * cmd = m_obj_sendcmd_map[objectName];
    cmd->header.transaction_id = QRandomGenerator::global()->bounded(INT32_MAX);; /// randomize this next time
    memset((void *)cmd->data, 0, MAX_TXRX_SIZE);
    qInfo()<<"Sending "<<data.toInt()<< "to MCU *********";
    float d = data.toFloat();
    memcpy((void*)cmd->data, (void *)&d, cmd->txrx_size);

    // serialize the command
    char buffer[MAX_TXRX_SIZE];
    serialize_cmd_struct(cmd, (uint8_t *)buffer);
    QByteArray bf_bytearray (buffer, get_required_buffsize_from_cmdsize(*cmd));
    QNetworkDatagram datagram(bf_bytearray,QHostAddress(remoteIPAddr),remotePort);

    // qInfo()<<"Sending data to "<<remoteIPAddr<<" and port "<<remotePort<<"from IP: "<<localIPAddr<<" and port "<<udpPort<<"\n";
    udp_socket->writeDatagram(datagram);

}

void UDPWorker::read_memory_value(qint32 address, dt_map data_type)
{

    Q_UNUSED(address)
    // address=0;
    switch (data_type) {
    case sU8:{

        break;}
    case sU16:

        break;
    case sU32:

        break;
    case sDFLT:

        break;
    case sFLT:

        break;

    default:
        break;
    }
}

bool UDPWorker::configure(QString localIPAddress, QString localPort, QString remoteIPAddress, QString remotePort)
{
    this->localIPAddr = localIPAddress;
    this->udpPort = localPort.toInt();
    this->remoteIPAddr = remoteIPAddress;
    this->remotePort = remotePort.toInt();
    return true;
}

void UDPWorker::setTimerStatus(bool status)
{
    if(status){
        qInfo()<<"Starting timer";
          udp_timer->start();
    }else{
          udp_timer->stop();
        qInfo()<<"Stopping timer";
    }
}

void UDPWorker::dummyTimeout()
{
    // update a model
    int d = QRandomGenerator::global()->bounded(100);
    // m_data_models["dummy"]->setData(d);
    emit updateVariableData("dummy", d);
    // qInfo()<< "Updating model to "<<d;

}



QString UDPWorker::getRemoteIPAddr() const
{
    return remoteIPAddr;
}

void UDPWorker::setRemoteIPAddr(const QString &newRemoteIPAddr)
{
    remoteIPAddr = newRemoteIPAddr;
}

qint16 UDPWorker::getremotePort() const
{
    return remotePort;
}

qint16 UDPWorker::getlocalPort() const
{
    return udpPort;
}

void UDPWorker::setlocalPort(const qint16 newport)
{
    udpPort = newport;
}

void UDPWorker::setRemotePort(const qint16 newport)
{
    remotePort = newport;
}

QVariantMap UDPWorker::vmap(){
    return m_variableValueMap;
}

QString UDPWorker::getlocalIPaddress() const
{
    return localIPAddr;
}

void UDPWorker::setLocalIPaddress(QString ip_addr)
{
    localIPAddr = ip_addr;
}
