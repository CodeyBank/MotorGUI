
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "logger.h"
#include "modelmanager.h"
#include "udpworker.h"
#include "appmanger.h"
#include "memorymodel.h"
#include "bindingmodel.h"
// #include "QtWebEngine"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    // QtWebEngine::initialize();
    //Register a type in QML
    qmlRegisterType<UDPWorker>("com.futureelctronics.udpworker",1,0,"UDPWorker");
    qmlRegisterType<AppManger>("com.futureelctronics.appmanager",1,0,"AppManger");
    qmlRegisterType<MemoryModel>("com.futureelctronics.memorymodel",1,0,"MemoryModel");
    qmlRegisterType<ModelManager>("com.futureelctronics.modelmanager",1,0,"ModelManager");
    qmlRegisterType<BindingModel>("com.futureelctronics.bindingmodel",1,0,"BindingModel");


    QGuiApplication app(argc, argv);
    Logger::attach();
    Logger::logging = true;
    QQmlApplicationEngine engine;

    // MemoryModel
    // MemoryModel * model = new MemoryModel();
    // AppManger * appmanager = new AppManger(model);

    // engine.rootContext()->setContextProperty("memorymodel", model);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
    // delete model;

}
