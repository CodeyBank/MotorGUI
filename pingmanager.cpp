
#include "pingmanager.h"
#include <QProcess>

PingManager::PingManager(QObject *parent) : QObject(parent) {
    connect(&timer, &QTimer::timeout, this, &PingManager::ping);
    timer.setInterval(5000); // Adjust the interval as needed
    timer.start();
    connect(pingProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &PingManager::processFinished);
}

void PingManager::ping() {
    pingProcess = new QProcess(this);
    QStringList arguments;
#ifdef Q_OS_WIN
    arguments << "-n" << "1"; // Windows
#else
    arguments << "-c" << "1"; // Unix-like systems (including macOS and Linux)
#endif
    arguments << "-W" << "1"; // Wait for up to 1 second for a response
    arguments << "example.com"; // Adjust "example.com" to the desired destination address

    pingProcess->start("ping", arguments);
}

void PingManager::processFinished(int exitCode, QProcess::ExitStatus exitStatus) {
    alive = (exitStatus == QProcess::NormalExit && exitCode == 0);
    emit hostAlive(alive);
}

bool PingManager::status()
{
    return alive;
}
