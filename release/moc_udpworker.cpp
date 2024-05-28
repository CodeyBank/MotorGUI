/****************************************************************************
** Meta object code from reading C++ file 'udpworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../udpworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDPWorker_t {
    QByteArrayData data[45];
    char stringdata0[584];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDPWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDPWorker_t qt_meta_stringdata_UDPWorker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "UDPWorker"
QT_MOC_LITERAL(1, 10, 15), // "newDataReceived"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "data"
QT_MOC_LITERAL(4, 32, 22), // "remoteHeartBeatChanged"
QT_MOC_LITERAL(5, 55, 6), // "status"
QT_MOC_LITERAL(6, 62, 22), // "localinterfacesChanged"
QT_MOC_LITERAL(7, 85, 21), // "localIPAddressChanged"
QT_MOC_LITERAL(8, 107, 16), // "localPortChanged"
QT_MOC_LITERAL(9, 124, 22), // "remoteIPAddressChanged"
QT_MOC_LITERAL(10, 147, 17), // "remotePortChanged"
QT_MOC_LITERAL(11, 165, 19), // "variableListChanged"
QT_MOC_LITERAL(12, 185, 20), // "modifiedDataReceived"
QT_MOC_LITERAL(13, 206, 11), // "vmapChanged"
QT_MOC_LITERAL(14, 218, 19), // "newVariableRecieved"
QT_MOC_LITERAL(15, 238, 8), // "variable"
QT_MOC_LITERAL(16, 247, 18), // "updateVariableData"
QT_MOC_LITERAL(17, 266, 5), // "value"
QT_MOC_LITERAL(18, 272, 5), // "start"
QT_MOC_LITERAL(19, 278, 4), // "stop"
QT_MOC_LITERAL(20, 283, 7), // "timeout"
QT_MOC_LITERAL(21, 291, 9), // "readyread"
QT_MOC_LITERAL(22, 301, 5), // "fetch"
QT_MOC_LITERAL(23, 307, 12), // "variableName"
QT_MOC_LITERAL(24, 320, 20), // "request_memory_table"
QT_MOC_LITERAL(25, 341, 11), // "memory_poll"
QT_MOC_LITERAL(26, 353, 10), // "addCommand"
QT_MOC_LITERAL(27, 364, 13), // "variablenName"
QT_MOC_LITERAL(28, 378, 10), // "objectName"
QT_MOC_LITERAL(29, 389, 11), // "commandType"
QT_MOC_LITERAL(30, 401, 16), // "sendCommandToMCU"
QT_MOC_LITERAL(31, 418, 17), // "read_memory_value"
QT_MOC_LITERAL(32, 436, 7), // "address"
QT_MOC_LITERAL(33, 444, 6), // "dt_map"
QT_MOC_LITERAL(34, 451, 9), // "data_type"
QT_MOC_LITERAL(35, 461, 9), // "configure"
QT_MOC_LITERAL(36, 471, 14), // "localIPAddress"
QT_MOC_LITERAL(37, 486, 9), // "localPort"
QT_MOC_LITERAL(38, 496, 15), // "remoteIPAddress"
QT_MOC_LITERAL(39, 512, 10), // "remotePort"
QT_MOC_LITERAL(40, 523, 14), // "setTimerStatus"
QT_MOC_LITERAL(41, 538, 12), // "dummyTimeout"
QT_MOC_LITERAL(42, 551, 12), // "variablelist"
QT_MOC_LITERAL(43, 564, 14), // "QList<QString>"
QT_MOC_LITERAL(44, 579, 4) // "vmap"

    },
    "UDPWorker\0newDataReceived\0\0data\0"
    "remoteHeartBeatChanged\0status\0"
    "localinterfacesChanged\0localIPAddressChanged\0"
    "localPortChanged\0remoteIPAddressChanged\0"
    "remotePortChanged\0variableListChanged\0"
    "modifiedDataReceived\0vmapChanged\0"
    "newVariableRecieved\0variable\0"
    "updateVariableData\0value\0start\0stop\0"
    "timeout\0readyread\0fetch\0variableName\0"
    "request_memory_table\0memory_poll\0"
    "addCommand\0variablenName\0objectName\0"
    "commandType\0sendCommandToMCU\0"
    "read_memory_value\0address\0dt_map\0"
    "data_type\0configure\0localIPAddress\0"
    "localPort\0remoteIPAddress\0remotePort\0"
    "setTimerStatus\0dummyTimeout\0variablelist\0"
    "QList<QString>\0vmap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDPWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       6,  202, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x06 /* Public */,
       4,    1,  142,    2, 0x06 /* Public */,
       6,    0,  145,    2, 0x06 /* Public */,
       7,    0,  146,    2, 0x06 /* Public */,
       8,    0,  147,    2, 0x06 /* Public */,
       9,    0,  148,    2, 0x06 /* Public */,
      10,    0,  149,    2, 0x06 /* Public */,
      11,    0,  150,    2, 0x06 /* Public */,
      12,    1,  151,    2, 0x06 /* Public */,
      13,    0,  154,    2, 0x06 /* Public */,
      14,    1,  155,    2, 0x06 /* Public */,
      16,    2,  158,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  163,    2, 0x0a /* Public */,
      19,    0,  164,    2, 0x0a /* Public */,
      20,    0,  165,    2, 0x0a /* Public */,
      21,    0,  166,    2, 0x0a /* Public */,
      22,    1,  167,    2, 0x0a /* Public */,
      24,    0,  170,    2, 0x0a /* Public */,
      25,    0,  171,    2, 0x0a /* Public */,
      26,    3,  172,    2, 0x0a /* Public */,
      30,    2,  179,    2, 0x0a /* Public */,
      31,    2,  184,    2, 0x0a /* Public */,
      35,    4,  189,    2, 0x0a /* Public */,
      40,    1,  198,    2, 0x0a /* Public */,
      41,    0,  201,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantMap,    3,
    QMetaType::Void, QMetaType::QVariant,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   15,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QVariant, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   28,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 33,   32,   34,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   36,   37,   38,   39,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

 // properties: name, type, flags
      36, QMetaType::QString, 0x00495803,
      37, QMetaType::Short, 0x00495803,
      38, QMetaType::QString, 0x00495803,
      39, QMetaType::Short, 0x00495903,
      42, 0x80000000 | 43, 0x00495809,
      44, QMetaType::QVariantMap, 0x00495801,

 // properties: notify_signal_id
       3,
       4,
       5,
       6,
       7,
       9,

       0        // eod
};

void UDPWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDPWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDataReceived((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 1: _t->remoteHeartBeatChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->localinterfacesChanged(); break;
        case 3: _t->localIPAddressChanged(); break;
        case 4: _t->localPortChanged(); break;
        case 5: _t->remoteIPAddressChanged(); break;
        case 6: _t->remotePortChanged(); break;
        case 7: _t->variableListChanged(); break;
        case 8: _t->modifiedDataReceived((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 9: _t->vmapChanged(); break;
        case 10: _t->newVariableRecieved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->updateVariableData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 12: _t->start(); break;
        case 13: _t->stop(); break;
        case 14: _t->timeout(); break;
        case 15: _t->readyread(); break;
        case 16: { QVariant _r = _t->fetch((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->request_memory_table(); break;
        case 18: _t->memory_poll(); break;
        case 19: _t->addCommand((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 20: _t->sendCommandToMCU((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 21: _t->read_memory_value((*reinterpret_cast< qint32(*)>(_a[1])),(*reinterpret_cast< dt_map(*)>(_a[2]))); break;
        case 22: { bool _r = _t->configure((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->setTimerStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->dummyTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDPWorker::*)(const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::newDataReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::remoteHeartBeatChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::localinterfacesChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::localIPAddressChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::localPortChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::remoteIPAddressChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::remotePortChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::variableListChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)(const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::modifiedDataReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::vmapChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::newVariableRecieved)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (UDPWorker::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDPWorker::updateVariableData)) {
                *result = 11;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UDPWorker *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getlocalIPaddress(); break;
        case 1: *reinterpret_cast< qint16*>(_v) = _t->getlocalPort(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getRemoteIPAddr(); break;
        case 3: *reinterpret_cast< qint16*>(_v) = _t->getremotePort(); break;
        case 4: *reinterpret_cast< QList<QString>*>(_v) = _t->variable(); break;
        case 5: *reinterpret_cast< QVariantMap*>(_v) = _t->vmap(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UDPWorker *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLocalIPaddress(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setlocalPort(*reinterpret_cast< qint16*>(_v)); break;
        case 2: _t->setRemoteIPAddr(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setRemotePort(*reinterpret_cast< qint16*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UDPWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UDPWorker.data,
    qt_meta_data_UDPWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UDPWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDPWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDPWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDPWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
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
void UDPWorker::newDataReceived(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDPWorker::remoteHeartBeatChanged(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UDPWorker::localinterfacesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void UDPWorker::localIPAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void UDPWorker::localPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void UDPWorker::remoteIPAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void UDPWorker::remotePortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void UDPWorker::variableListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void UDPWorker::modifiedDataReceived(const QVariantMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void UDPWorker::vmapChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void UDPWorker::newVariableRecieved(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void UDPWorker::updateVariableData(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
