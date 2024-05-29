/****************************************************************************
** Meta object code from reading C++ file 'bindingmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../bindingmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bindingmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BindingModel_t {
    QByteArrayData data[10];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BindingModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BindingModel_t qt_meta_stringdata_BindingModel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BindingModel"
QT_MOC_LITERAL(1, 13, 11), // "QML.Element"
QT_MOC_LITERAL(2, 25, 4), // "auto"
QT_MOC_LITERAL(3, 30, 10), // "addBinding"
QT_MOC_LITERAL(4, 41, 0), // ""
QT_MOC_LITERAL(5, 42, 4), // "name"
QT_MOC_LITERAL(6, 47, 3), // "tag"
QT_MOC_LITERAL(7, 51, 9), // "readwrite"
QT_MOC_LITERAL(8, 61, 13), // "modifyBinding"
QT_MOC_LITERAL(9, 75, 3) // "row"

    },
    "BindingModel\0QML.Element\0auto\0addBinding\0"
    "\0name\0tag\0readwrite\0modifyBinding\0row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BindingModel[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    3,   26,    4, 0x0a /* Public */,
       8,    4,   33,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,    5,    6,    7,

       0        // eod
};

void BindingModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BindingModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addBinding((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->modifyBinding((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BindingModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_BindingModel.data,
    qt_meta_data_BindingModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BindingModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BindingModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BindingModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int BindingModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
