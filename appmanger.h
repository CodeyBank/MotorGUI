#ifndef APPMANGER_H
#define APPMANGER_H

#include <QObject>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include "memorymodel.h"
#include "udpworker.h"
#include <QValidator>
#include <QProcess>
#include <QSettings>
#include <QDir>
#include <QIntValidator>


class AppManger : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool heartbeat READ getHeartBeat NOTIFY remoteHeartBeatChanged FINAL)
    Q_PROPERTY(QList<QString> localinterfaces READ getLocalInterfaces NOTIFY localinterfacesChanged FINAL)
    Q_PROPERTY(QString localIPAddress READ getlocalIPaddress WRITE setLocalIPaddress NOTIFY localIPAddressChanged FINAL) //remove
    Q_PROPERTY(qint16 localPort  READ getlocalPort WRITE setlocalPort NOTIFY localPortChanged FINAL)
    Q_PROPERTY(QString remoteIPAddress READ getRemoteIPAddr WRITE setRemoteIPAddr NOTIFY remoteIPAddressChanged FINAL)
    Q_PROPERTY(qint16 remotePort READ getremotePort WRITE setRemotePort NOTIFY remotePortChanged FINAL)

    QTimer pingTimer;
    QProcess *pingProcess;
    bool alive = false;
    bool settingsSaved =false;
    QList<QString> interfaces;
    QString localIPAddr, remoteIPAddr;
    qint16 localPort, remotePort;

    // model for the tables
    MemoryModel *m_model;

   void ping();
public:
    explicit AppManger(QObject *parent = nullptr, MemoryModel * model = nullptr);

    QString readVariableValue(QString var_name);
    void writeVariableValue(QString var_name);

    UDPWorker *udp;
    QThread * udpWorkerThread;


    // getters and setters for QPROPERTY
    bool getHeartBeat(void);

    void setLocalIPaddress(const QString ip_addr); // remove
    QString getlocalIPaddress(void)const ;

    QString getRemoteIPAddr() const;
    void setRemoteIPAddr(const QString &newRemoteIPAddr);

    qint16 getremotePort(void)const;
    qint16 getlocalPort(void)const;

    void setlocalPort(const qint16 newport);
    void setRemotePort(const qint16 newport);



signals:
    void remoteHeartBeatChanged(QVariant status);
    void localinterfacesChanged(void);
    void localIPAddressChanged();
    void localPortChanged(void);
    void remoteIPAddressChanged();
    void remotePortChanged();



public slots:
    void startUdpCommunication(void);
    void stopUdpCommunication(void);
    void loadInterfaces(void);

    bool isValidPort(QString str_port);
    bool isValidIPAddress(QString str_ipAddr);
    void testRemoteDevice(QString ip_addr);
    QList<QString> getLocalInterfaces(void);
    QString getIpAddressByInterfaceName(const QString &interfaceName);
    bool loadSettings();
    void saveSettings();
    void setAllAddressAndPorts(QList<QList<QString>> config_addresses);
    void disconnect();

};

#endif // APPMANGER_H
