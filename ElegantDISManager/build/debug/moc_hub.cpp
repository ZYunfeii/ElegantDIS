/****************************************************************************
** Meta object code from reading C++ file 'hub.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hub.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hub_t {
    QByteArrayData data[11];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hub_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hub_t qt_meta_stringdata_Hub = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Hub"
QT_MOC_LITERAL(1, 4, 16), // "start_server_sig"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "handle_log_msg"
QT_MOC_LITERAL(4, 37, 17), // "update_topic_show"
QT_MOC_LITERAL(5, 55, 8), // "step_cmd"
QT_MOC_LITERAL(6, 64, 8), // "init_cmd"
QT_MOC_LITERAL(7, 73, 15), // "handle_step_sig"
QT_MOC_LITERAL(8, 89, 14), // "handle_sim_msg"
QT_MOC_LITERAL(9, 104, 17), // "handle_synpub_sig"
QT_MOC_LITERAL(10, 122, 19) // "handle_initover_sig"

    },
    "Hub\0start_server_sig\0\0handle_log_msg\0"
    "update_topic_show\0step_cmd\0init_cmd\0"
    "handle_step_sig\0handle_sim_msg\0"
    "handle_synpub_sig\0handle_initover_sig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hub[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   60,    2, 0x0a /* Public */,
       4,    0,   63,    2, 0x0a /* Public */,
       5,    0,   64,    2, 0x0a /* Public */,
       6,    0,   65,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    1,   67,    2, 0x0a /* Public */,
       9,    0,   70,    2, 0x0a /* Public */,
      10,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Hub::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Hub *_t = static_cast<Hub *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start_server_sig(); break;
        case 1: _t->handle_log_msg((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->update_topic_show(); break;
        case 3: _t->step_cmd(); break;
        case 4: _t->init_cmd(); break;
        case 5: _t->handle_step_sig(); break;
        case 6: _t->handle_sim_msg((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 7: _t->handle_synpub_sig(); break;
        case 8: _t->handle_initover_sig(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Hub::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hub::start_server_sig)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Hub::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Hub.data,
      qt_meta_data_Hub,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Hub::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hub::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hub.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Hub::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Hub::start_server_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
