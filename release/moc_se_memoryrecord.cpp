/****************************************************************************
** Meta object code from reading C++ file 'se_memoryrecord.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../se_memoryrecord.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'se_memoryrecord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SE_MemoryRecord_t {
    QByteArrayData data[14];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SE_MemoryRecord_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SE_MemoryRecord_t qt_meta_stringdata_SE_MemoryRecord = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SE_MemoryRecord"
QT_MOC_LITERAL(1, 16, 11), // "nameChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "addressChanged"
QT_MOC_LITERAL(4, 44, 11), // "typeChanged"
QT_MOC_LITERAL(5, 56, 12), // "valueChanged"
QT_MOC_LITERAL(6, 69, 16), // "attributeChanged"
QT_MOC_LITERAL(7, 86, 11), // "sizeChanged"
QT_MOC_LITERAL(8, 98, 4), // "name"
QT_MOC_LITERAL(9, 103, 7), // "address"
QT_MOC_LITERAL(10, 111, 4), // "type"
QT_MOC_LITERAL(11, 116, 4), // "size"
QT_MOC_LITERAL(12, 121, 9), // "attribute"
QT_MOC_LITERAL(13, 131, 5) // "value"

    },
    "SE_MemoryRecord\0nameChanged\0\0"
    "addressChanged\0typeChanged\0valueChanged\0"
    "attributeChanged\0sizeChanged\0name\0"
    "address\0type\0size\0attribute\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SE_MemoryRecord[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       6,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::SChar, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       1,
       4,
       3,

       0        // eod
};

void SE_MemoryRecord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SE_MemoryRecord *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->addressChanged(); break;
        case 2: _t->typeChanged(); break;
        case 3: _t->valueChanged(); break;
        case 4: _t->attributeChanged(); break;
        case 5: _t->sizeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SE_MemoryRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SE_MemoryRecord::nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SE_MemoryRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SE_MemoryRecord::addressChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SE_MemoryRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SE_MemoryRecord::typeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SE_MemoryRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SE_MemoryRecord::valueChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SE_MemoryRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SE_MemoryRecord::attributeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SE_MemoryRecord::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SE_MemoryRecord::sizeChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SE_MemoryRecord *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->address(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->type(); break;
        case 3: *reinterpret_cast< qint8*>(_v) = _t->size(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->attribute(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SE_MemoryRecord *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setAddress(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setType(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setSize(*reinterpret_cast< qint8*>(_v)); break;
        case 4: _t->setAttribute(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setValue(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SE_MemoryRecord::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SE_MemoryRecord.data,
    qt_meta_data_SE_MemoryRecord,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SE_MemoryRecord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SE_MemoryRecord::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SE_MemoryRecord.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SE_MemoryRecord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
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
void SE_MemoryRecord::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SE_MemoryRecord::addressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SE_MemoryRecord::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SE_MemoryRecord::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SE_MemoryRecord::attributeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SE_MemoryRecord::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
