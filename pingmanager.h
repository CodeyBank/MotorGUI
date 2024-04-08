#ifndef PINGMANAGER_H
#define PINGMANAGER_H

#include <QCoreApplication>
#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QTimer>

class PingManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool status READ status NOTIFY hostAlive FINAL)

public:
    explicit PingManager(QObject *parent = nullptr);

signals:
    void hostAlive(bool);

public slots:
    void ping();
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
    bool status(void);

private:
    QTimer timer;
    QProcess *pingProcess;
    bool alive;

};

#endif // PINGMANAGER_H
