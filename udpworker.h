#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QBasicTimer>
#include <QDateTime>
#include <QNetworkDatagram>
#include <QUdpSocket>
#include <QThread>
#include <QEventLoop>
#include <QMap>
#include "seprotocol.h"
#include "memorymodel.h"
#include "customdatamodel.h"
/*
    Responsible for listen to UDP datagrams on a socket and sending
    packets to the MCU
*/



class UDPWorker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString localIPAddress READ getlocalIPaddress WRITE setLocalIPaddress NOTIFY localIPAddressChanged FINAL) //remove
    Q_PROPERTY(qint16 localPort  READ getlocalPort WRITE setlocalPort NOTIFY localPortChanged FINAL)
    Q_PROPERTY(QString remoteIPAddress READ getRemoteIPAddr WRITE setRemoteIPAddr NOTIFY remoteIPAddressChanged FINAL)
    Q_PROPERTY(qint16 remotePort READ getremotePort WRITE setRemotePort NOTIFY remotePortChanged FINAL)
    Q_PROPERTY(QList<QString> variablelist READ variable NOTIFY variableListChanged FINAL)
    Q_PROPERTY(QVariantMap vmap READ vmap NOTIFY vmapChanged FINAL)


    // Map between variable name and data models
    QMap<QString, CustomDataModel*> m_data_models;
    QList<QString> m_variable_names;
    QVariantMap m_variableValueMap;

public:
    explicit UDPWorker(QObject *parent = nullptr, MemoryModel *memorymodel=nullptr);
    //Key is the variable name since it is unique
    QMap<QString, mem_record_t>memory_table;
    QMap<qint32, mem_record_t>memory_table_addr;
    QMap<qint32, MemValue_S>memory_addr_val_map;
    QUdpSocket * udp_socket;
    QString localIPAddr, remoteIPAddr;
    quint16 remotePort;
    quint16 udpPort = 1234;
    MemoryModel *model;
    QMap<QString, QString> m_data_map;
    QMap<QString, command_t *> m_obj_sendcmd_map;

    QList<QString> variable(void){return m_variable_names;}


    void setLocalIPaddress(const QString ip_addr); // remove
    QString getlocalIPaddress(void)const ;

    QString getRemoteIPAddr() const;
    void setRemoteIPAddr(const QString &newRemoteIPAddr);

    qint16 getremotePort(void)const;
    qint16 getlocalPort(void)const;

    void setlocalPort(const qint16 newport);
    void setRemotePort(const qint16 newport);

    QVariantMap vmap(void);



signals:
    void newDataReceived(const QVariantMap &data);
    void remoteHeartBeatChanged(QVariant status);
    void localinterfacesChanged(void);
    void localIPAddressChanged();
    void localPortChanged(void);
    void remoteIPAddressChanged();
    void remotePortChanged();
    void variableListChanged(void);
    void modifiedDataReceived(const QVariantMap &data);
    void vmapChanged();

    // ------------test
    void newVariableRecieved(QString variable);
    void updateVariableData(QString variable, QVariant value);
public slots:
    /*
        @brief : send out broadcasts
    */
    void start();
    /*
        @brief : send out broadcasts
    */
    void stop();
    /*
        @brief : send out broadcasts
    */
    void timeout();
    /*
        @brief : send out broadcasts
    */
    void readyread();
    /*
        @brief : send out broadcasts
    */
    QVariant fetch(const QString &variableName);

    /*
        @brief : send out broadcasts
    */
    void request_memory_table();


    void memory_poll(void);

    // update the command map and set the bindings
    void addCommand(const QString &variablenName,
                    const QString &objectName,
                    const QString commandType);

    void sendCommandToMCU(const QString &objectName, const QVariant &data);


    /*
        @brief : Reads the value of an address in the table
        @params : address-> address of the value
                  data_type-> data type of the value
    */
    void read_memory_value(qint32 address, dt_map data_type);
    bool configure(QString localIPAddress, QString localPort, QString remoteIPAddress, QString remotePort);

    void setTimerStatus(bool status);

    void dummyTimeout();

    // ~UDPWorker();
private:

    QTimer *udp_timer;
    QTimer * dummy;
    QEventLoop *udp_event_loop;


};

#endif // UDPWORKER_H
