/****************************************************************************
** Meta object code from reading C++ file 'appmanger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../appmanger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appmanger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppManger_t {
    QByteArrayData data[33];
    char stringdata0[518];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppManger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppManger_t qt_meta_stringdata_AppManger = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AppManger"
QT_MOC_LITERAL(1, 10, 22), // "remoteHeartBeatChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "status"
QT_MOC_LITERAL(4, 41, 22), // "localinterfacesChanged"
QT_MOC_LITERAL(5, 64, 21), // "localIPAddressChanged"
QT_MOC_LITERAL(6, 86, 16), // "localPortChanged"
QT_MOC_LITERAL(7, 103, 22), // "remoteIPAddressChanged"
QT_MOC_LITERAL(8, 126, 17), // "remotePortChanged"
QT_MOC_LITERAL(9, 144, 21), // "startUdpCommunication"
QT_MOC_LITERAL(10, 166, 20), // "stopUdpCommunication"
QT_MOC_LITERAL(11, 187, 14), // "loadInterfaces"
QT_MOC_LITERAL(12, 202, 11), // "isValidPort"
QT_MOC_LITERAL(13, 214, 8), // "str_port"
QT_MOC_LITERAL(14, 223, 16), // "isValidIPAddress"
QT_MOC_LITERAL(15, 240, 10), // "str_ipAddr"
QT_MOC_LITERAL(16, 251, 16), // "testRemoteDevice"
QT_MOC_LITERAL(17, 268, 7), // "ip_addr"
QT_MOC_LITERAL(18, 276, 18), // "getLocalInterfaces"
QT_MOC_LITERAL(19, 295, 14), // "QList<QString>"
QT_MOC_LITERAL(20, 310, 27), // "getIpAddressByInterfaceName"
QT_MOC_LITERAL(21, 338, 13), // "interfaceName"
QT_MOC_LITERAL(22, 352, 12), // "loadSettings"
QT_MOC_LITERAL(23, 365, 12), // "saveSettings"
QT_MOC_LITERAL(24, 378, 21), // "setAllAddressAndPorts"
QT_MOC_LITERAL(25, 400, 22), // "QList<QList<QString> >"
QT_MOC_LITERAL(26, 423, 16), // "config_addresses"
QT_MOC_LITERAL(27, 440, 9), // "heartbeat"
QT_MOC_LITERAL(28, 450, 15), // "localinterfaces"
QT_MOC_LITERAL(29, 466, 14), // "localIPAddress"
QT_MOC_LITERAL(30, 481, 9), // "localPort"
QT_MOC_LITERAL(31, 491, 15), // "remoteIPAddress"
QT_MOC_LITERAL(32, 507, 10) // "remotePort"

    },
    "AppManger\0remoteHeartBeatChanged\0\0"
    "status\0localinterfacesChanged\0"
    "localIPAddressChanged\0localPortChanged\0"
    "remoteIPAddressChanged\0remotePortChanged\0"
    "startUdpCommunication\0stopUdpCommunication\0"
    "loadInterfaces\0isValidPort\0str_port\0"
    "isValidIPAddress\0str_ipAddr\0"
    "testRemoteDevice\0ip_addr\0getLocalInterfaces\0"
    "QList<QString>\0getIpAddressByInterfaceName\0"
    "interfaceName\0loadSettings\0saveSettings\0"
    "setAllAddressAndPorts\0QList<QList<QString> >\0"
    "config_addresses\0heartbeat\0localinterfaces\0"
    "localIPAddress\0localPort\0remoteIPAddress\0"
    "remotePort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppManger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       6,  128, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    0,  102,    2, 0x06 /* Public */,
       5,    0,  103,    2, 0x06 /* Public */,
       6,    0,  104,    2, 0x06 /* Public */,
       7,    0,  105,    2, 0x06 /* Public */,
       8,    0,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  107,    2, 0x0a /* Public */,
      10,    0,  108,    2, 0x0a /* Public */,
      11,    0,  109,    2, 0x0a /* Public */,
      12,    1,  110,    2, 0x0a /* Public */,
      14,    1,  113,    2, 0x0a /* Public */,
      16,    1,  116,    2, 0x0a /* Public */,
      18,    0,  119,    2, 0x0a /* Public */,
      20,    1,  120,    2, 0x0a /* Public */,
      22,    0,  123,    2, 0x0a /* Public */,
      23,    0,  124,    2, 0x0a /* Public */,
      24,    1,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   13,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    0x80000000 | 19,
    QMetaType::QString, QMetaType::QString,   21,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,

 // properties: name, type, flags
      27, QMetaType::Bool, 0x00495801,
      28, 0x80000000 | 19, 0x00495809,
      29, QMetaType::QString, 0x00495803,
      30, QMetaType::Short, 0x00495803,
      31, QMetaType::QString, 0x00495803,
      32, QMetaType::Short, 0x00495903,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void AppManger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppManger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->remoteHeartBeatChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->localinterfacesChanged(); break;
        case 2: _t->localIPAddressChanged(); break;
        case 3: _t->localPortChanged(); break;
        case 4: _t->remoteIPAddressChanged(); break;
        case 5: _t->remotePortChanged(); break;
        case 6: _t->startUdpCommunication(); break;
        case 7: _t->stopUdpCommunication(); break;
        case 8: _t->loadInterfaces(); break;
        case 9: { bool _r = _t->isValidPort((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->isValidIPAddress((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->testRemoteDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: { QList<QString> _r = _t->getLocalInterfaces();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->getIpAddressByInterfaceName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->loadSettings();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->saveSettings(); break;
        case 16: _t->setAllAddressAndPorts((*reinterpret_cast< QList<QList<QString> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<QString> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppManger::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppManger::remoteHeartBeatChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppManger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppManger::localinterfacesChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppManger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppManger::localIPAddressChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppManger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppManger::localPortChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AppManger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppManger::remoteIPAddressChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AppManger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppManger::remotePortChanged)) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AppManger *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getHeartBeat(); break;
        case 1: *reinterpret_cast< QList<QString>*>(_v) = _t->getLocalInterfaces(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getlocalIPaddress(); break;
        case 3: *reinterpret_cast< qint16*>(_v) = _t->getlocalPort(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getRemoteIPAddr(); break;
        case 5: *reinterpret_cast< qint16*>(_v) = _t->getremotePort(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AppManger *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setLocalIPaddress(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setlocalPort(*reinterpret_cast< qint16*>(_v)); break;
        case 4: _t->setRemoteIPAddr(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setRemotePort(*reinterpret_cast< qint16*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AppManger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppManger.data,
    qt_meta_data_AppManger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppManger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppManger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppManger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppManger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AppManger::remoteHeartBeatChanged(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppManger::localinterfacesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppManger::localIPAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AppManger::localPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AppManger::remoteIPAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AppManger::remotePortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
