/****************************************************************************
** Meta object code from reading C++ file 'memorymodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../memorymodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'memorymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MemoryModel_t {
    QByteArrayData data[13];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MemoryModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MemoryModel_t qt_meta_stringdata_MemoryModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MemoryModel"
QT_MOC_LITERAL(1, 12, 11), // "QML.Element"
QT_MOC_LITERAL(2, 24, 4), // "auto"
QT_MOC_LITERAL(3, 29, 10), // "updateData"
QT_MOC_LITERAL(4, 40, 0), // ""
QT_MOC_LITERAL(5, 41, 4), // "name"
QT_MOC_LITERAL(6, 46, 7), // "address"
QT_MOC_LITERAL(7, 54, 9), // "attribute"
QT_MOC_LITERAL(8, 64, 4), // "type"
QT_MOC_LITERAL(9, 69, 4), // "size"
QT_MOC_LITERAL(10, 74, 5), // "value"
QT_MOC_LITERAL(11, 80, 10), // "modifyData"
QT_MOC_LITERAL(12, 91, 5) // "clear"

    },
    "MemoryModel\0QML.Element\0auto\0updateData\0"
    "\0name\0address\0attribute\0type\0size\0"
    "value\0modifyData\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MemoryModel[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    6,   31,    4, 0x0a /* Public */,
      11,    6,   44,    4, 0x0a /* Public */,
      12,    0,   57,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::UChar, QMetaType::UChar, QMetaType::SChar, QMetaType::QString,    5,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::UChar, QMetaType::UChar, QMetaType::SChar, QMetaType::QString,    5,    6,    7,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void MemoryModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MemoryModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const qint32(*)>(_a[2])),(*reinterpret_cast< const quint8(*)>(_a[3])),(*reinterpret_cast< const quint8(*)>(_a[4])),(*reinterpret_cast< const qint8(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 1: _t->modifyData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const qint32(*)>(_a[2])),(*reinterpret_cast< const quint8(*)>(_a[3])),(*reinterpret_cast< const quint8(*)>(_a[4])),(*reinterpret_cast< const qint8(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 2: _t->clear(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MemoryModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_MemoryModel.data,
    qt_meta_data_MemoryModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MemoryModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MemoryModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MemoryModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int MemoryModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
