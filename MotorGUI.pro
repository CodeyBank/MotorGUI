QT += quick gui core

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        appmanger.cpp \
        bindingitem.cpp \
        bindingmodel.cpp \
        customdatamodel.cpp \
        main.cpp \
        memorymodel.cpp \
        modelmanager.cpp \
        #pingmanager.cpp \
        se_memoryrecord.cpp \
        seprotocol.cpp \
        udpworker.cpp

RESOURCES += qml.qrc

CONFIG += qtquickcompiler

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    appmanger.h \
    bindingitem.h \
    bindingmodel.h \
    customdatamodel.h \
    memorymodel.h \
    modelmanager.h \
    #pingmanager.h \
    se_memoryrecord.h \
    seprotocol.h \
    udpworker.h


