#include "appmanger.h"

#include <QCoreApplication>
#include <QRegularExpressionValidator>

QString AppManger::getRemoteIPAddr() const
{
    return remoteIPAddr;
}

void AppManger::setRemoteIPAddr(const QString &newRemoteIPAddr)
{
    remoteIPAddr = newRemoteIPAddr;
}

qint16 AppManger::getremotePort() const
{
    return remotePort;
}

qint16 AppManger::getlocalPort() const
{
    return localPort;
}

void AppManger::setlocalPort(const qint16 newport)
{
    localPort = newport;
}

void AppManger::setRemotePort(const qint16 newport)
{
    remotePort = newport;
}


AppManger::AppManger(QObject *parent, MemoryModel *model) :QObject(parent), m_model(model) {

    qInfo()<<"App manager instantiated";
    pingProcess = new QProcess(this);

    connect(&pingTimer, &QTimer::timeout, this, [=](){testRemoteDevice(remoteIPAddr);});
    pingTimer.setSingleShot(true);

    connect(pingProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this,[=](int exitCode, QProcess::ExitStatus exitStatus){
        alive = (exitStatus == QProcess::NormalExit && exitCode == 0);

        // qDebug() << "Ping process exited with code:" << pingProcess->exitCode();
        // qDebug() << "Output:";
        // qDebug() << pingProcess->readAllStandardOutput();

        emit remoteHeartBeatChanged(alive);

        pingTimer.start(1000);
    });

}


void AppManger::loadInterfaces()
{
    interfaces.clear();
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for(auto &intAddr : list){
        // qInfo()<< intAddr.humanReadableName();
        interfaces.append(intAddr.humanReadableName());
    }
    emit localinterfacesChanged();
}

QString AppManger::getIpAddressByInterfaceName(const QString &interfaceName) {
    qInfo()<<interfaceName;
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    foreach (const QNetworkInterface &local, interfaces) {
        if (local.humanReadableName() == interfaceName) {
            foreach (const QNetworkAddressEntry &entry, local.addressEntries()) {
                if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                    qInfo()<< "Found IP :"<< entry.ip().toString();
                    localIPAddr = entry.ip().toString();
                    return localIPAddr;
                }
            }
        }
    }

    // Return an empty string if the interface is not found or doesn't have an IPv4 address
    return QString();
}

void AppManger::setAllAddressAndPorts(QList<QList<QString>> config_addresses)
{
    for(auto &s: config_addresses){
        qInfo()<<s;
    }
    QList<QString>local, remote;
    local = config_addresses.at(0);
    remote = config_addresses.at(1);

    // set the local address
    localIPAddr = local.at(0);
    localPort = local.at(1).toInt();

    //set the remote addresses
    remoteIPAddr = remote.at(0);
    remoteIPAddr = remote.at(1);

    // start the UDP thread
    startUdpCommunication();
}

void AppManger::ping()
{
    testRemoteDevice(remoteIPAddr);
}

void AppManger::updateMemoryTable()
{

}

void AppManger::updateVariableView(QString record_name)
{

}


bool AppManger::isValidPort(QString str_port)
{
     int pos = 0;
     QValidator *portValidator = new QIntValidator(1,65535,this);
    bool result = false;
     if(portValidator->validate(str_port,pos)==2)
     {
         qInfo()<<"Valid port";
         result = true;
     }
     delete portValidator;
    return result;
}

bool AppManger::isValidIPAddress(QString str_ipAddr)
{

    bool valid=true;
    int pos;
    QString IpRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegularExpression IpRegex ("^" + IpRange
                               + "(\\." + IpRange + ")"
                               + "(\\." + IpRange + ")"
                               + "(\\." + IpRange + ")$");
    QRegularExpressionValidator *ipValidator = new QRegularExpressionValidator(IpRegex, this);

    if(ipValidator->validate(str_ipAddr,pos) ==2){
        valid=true;
    };
    delete ipValidator;
    return valid;
}

void AppManger::testRemoteDevice(QString ip_addr)
{
    qInfo()<<ip_addr;

    QStringList arguments;
    arguments << "-n" << "1"<<"-l" << "1" << ip_addr;
    pingProcess->start("ping", arguments);


}

QList<QString> AppManger::getLocalInterfaces()
{
    return interfaces;
}


QString AppManger::readVariableValue(QString var_name)
{
    return "";
}

void AppManger::writeVariableValue(QString var_name)
{

}

bool AppManger::getHeartBeat()
{
    return this->alive;
}

QString AppManger::getlocalIPaddress() const
{
    return localIPAddr;
}

void AppManger::setLocalIPaddress(QString ip_addr)
{
    localIPAddr = ip_addr;
}

void AppManger::startUdpCommunication()
{
    udpWorkerThread = new QThread();
    udpWorkerThread->setObjectName("UDP worker thread");

    udp = new UDPWorker();
    udp->moveToThread(udpWorkerThread);
    QObject::connect(udpWorkerThread, &QThread::started, udp, &UDPWorker::start);
    connect(udpWorkerThread, &QThread::finished, udp, &UDPWorker::stop);

    // copy the set IP address and ports
    udp->localIPAddr = localIPAddr;
    udp->remoteIPAddr = remoteIPAddr;
    udp->remotePort = remotePort;
    udp->udpPort = localPort;

    qInfo()<<"Sending data to "<<remoteIPAddr<<" and port "<<remotePort<<"from IP: "<<localIPAddr<<" and port "<<localPort<<"\n";
    // qInfo()<<"Sending data to "<<udp->remoteIPAddr<<" and port "<<udp->remotePort<<"from IP: "<<udp->localIPAddr <<" and port "<<udp->udpPort<<"\n";
    udpWorkerThread->start();

}

void AppManger::stopUdpCommunication()
{
    udpWorkerThread->exit(0);
}


void AppManger::saveSettings()
{
    QString filename = QCoreApplication::applicationDirPath() + "/settings.ini";
    QSettings settings(filename, QSettings::Format::IniFormat,this);

    settings.setValue("localPort",QVariant(localPort));
    settings.setValue("localIPAddr",QVariant(localIPAddr));
    settings.setValue("remoteIPAddr",QVariant(remoteIPAddr));
    settings.setValue("remotePort",QVariant(remotePort));

    int result = settings.status();
    if (result ==QSettings::NoError && !settingsSaved ){
        settingsSaved = true;
        qInfo()<<"Saved settings";

    }
}

bool AppManger::loadSettings()
{
    /*
        Checks if there are any settings saved already.
        returns: True if at five values are saved setting is saved;
    */
    QMap<QString, QString> returnValue;
    QString filename = QCoreApplication::applicationDirPath() + "/settings.ini";
    QSettings settings(filename, QSettings::Format::IniFormat,this);
    // retrieve the keys
    QStringList keys=settings.allKeys();
    // if (keys.size()<5)
    //     return false;
    foreach(auto key,keys)
        returnValue[key]=settings.value(key).toString();

    localIPAddr = returnValue["localIPAddr"];
    remoteIPAddr = returnValue["remoteIPAddr"];
    localPort = returnValue["localPort"].toInt();
    remotePort = returnValue["remotePort"].toInt();

    return true;

}
