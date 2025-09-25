/****************************************************************************
** Meta object code from reading C++ file 'run.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../passenger/run.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'run.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_run_t {
    QByteArrayData data[8];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_run_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_run_t qt_meta_stringdata_run = {
    {
QT_MOC_LITERAL(0, 0, 3), // "run"
QT_MOC_LITERAL(1, 4, 23), // "on_discout_code_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 25), // "on_charge_account_clicked"
QT_MOC_LITERAL(4, 55, 18), // "on_log_out_clicked"
QT_MOC_LITERAL(5, 74, 15), // "on_menu_clicked"
QT_MOC_LITERAL(6, 90, 19), // "on_estimate_clicked"
QT_MOC_LITERAL(7, 110, 18) // "on_request_clicked"

    },
    "run\0on_discout_code_clicked\0\0"
    "on_charge_account_clicked\0on_log_out_clicked\0"
    "on_menu_clicked\0on_estimate_clicked\0"
    "on_request_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_run[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void run::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        run *_t = static_cast<run *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_discout_code_clicked(); break;
        case 1: _t->on_charge_account_clicked(); break;
        case 2: _t->on_log_out_clicked(); break;
        case 3: _t->on_menu_clicked(); break;
        case 4: _t->on_estimate_clicked(); break;
        case 5: _t->on_request_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject run::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_run.data,
      qt_meta_data_run,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *run::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *run::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_run.stringdata0))
        return static_cast<void*>(const_cast< run*>(this));
    return QWidget::qt_metacast(_clname);
}

int run::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
