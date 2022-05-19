/****************************************************************************
** Meta object code from reading C++ file 'pubsubserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pubsubserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pubsubserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pubsub__PubSubServer_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pubsub__PubSubServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pubsub__PubSubServer_t qt_meta_stringdata_pubsub__PubSubServer = {
    {
QT_MOC_LITERAL(0, 0, 20), // "pubsub::PubSubServer"
QT_MOC_LITERAL(1, 21, 7), // "log_msg"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "update_topic_sig"
QT_MOC_LITERAL(4, 47, 13), // "step_over_sig"
QT_MOC_LITERAL(5, 61, 13), // "init_over_sig"
QT_MOC_LITERAL(6, 75, 15), // "synpub_over_sig"
QT_MOC_LITERAL(7, 91, 5) // "start"

    },
    "pubsub::PubSubServer\0log_msg\0\0"
    "update_topic_sig\0step_over_sig\0"
    "init_over_sig\0synpub_over_sig\0start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pubsub__PubSubServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,
       4,    0,   48,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,
       6,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void pubsub::PubSubServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PubSubServer *_t = static_cast<PubSubServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->log_msg((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->update_topic_sig(); break;
        case 2: _t->step_over_sig(); break;
        case 3: _t->init_over_sig(); break;
        case 4: _t->synpub_over_sig(); break;
        case 5: _t->start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PubSubServer::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubServer::log_msg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PubSubServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubServer::update_topic_sig)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PubSubServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubServer::step_over_sig)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PubSubServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubServer::init_over_sig)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PubSubServer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubServer::synpub_over_sig)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject pubsub::PubSubServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pubsub__PubSubServer.data,
      qt_meta_data_pubsub__PubSubServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pubsub::PubSubServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pubsub::PubSubServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pubsub__PubSubServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int pubsub::PubSubServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void pubsub::PubSubServer::log_msg(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pubsub::PubSubServer::update_topic_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void pubsub::PubSubServer::step_over_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void pubsub::PubSubServer::init_over_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void pubsub::PubSubServer::synpub_over_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
