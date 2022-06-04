/****************************************************************************
** Meta object code from reading C++ file 'pubsub.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pubsub.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pubsub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pubsub__PubSubClient_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pubsub__PubSubClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pubsub__PubSubClient_t qt_meta_stringdata_pubsub__PubSubClient = {
    {
QT_MOC_LITERAL(0, 0, 20), // "pubsub::PubSubClient"
QT_MOC_LITERAL(1, 21, 7), // "log_msg"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "init_msg"
QT_MOC_LITERAL(4, 39, 17), // "update_topic_data"
QT_MOC_LITERAL(5, 57, 10), // "topic_name"
QT_MOC_LITERAL(6, 68, 10), // "topic_data"
QT_MOC_LITERAL(7, 79, 10), // "synpub_sig"
QT_MOC_LITERAL(8, 90, 22), // "update_pubsub_data_sig"
QT_MOC_LITERAL(9, 113, 5), // "start"
QT_MOC_LITERAL(10, 119, 4) // "stop"

    },
    "pubsub::PubSubClient\0log_msg\0\0init_msg\0"
    "update_topic_data\0topic_name\0topic_data\0"
    "synpub_sig\0update_pubsub_data_sig\0"
    "start\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pubsub__PubSubClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    2,   55,    2, 0x06 /* Public */,
       7,    0,   60,    2, 0x06 /* Public */,
       8,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pubsub::PubSubClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PubSubClient *_t = static_cast<PubSubClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->log_msg((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->init_msg((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->update_topic_data((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: _t->synpub_sig(); break;
        case 4: _t->update_pubsub_data_sig(); break;
        case 5: _t->start(); break;
        case 6: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PubSubClient::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubClient::log_msg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PubSubClient::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubClient::init_msg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PubSubClient::*_t)(QVariant , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubClient::update_topic_data)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PubSubClient::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubClient::synpub_sig)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PubSubClient::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PubSubClient::update_pubsub_data_sig)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject pubsub::PubSubClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pubsub__PubSubClient.data,
      qt_meta_data_pubsub__PubSubClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pubsub::PubSubClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pubsub::PubSubClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pubsub__PubSubClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int pubsub::PubSubClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void pubsub::PubSubClient::log_msg(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pubsub::PubSubClient::init_msg(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pubsub::PubSubClient::update_topic_data(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pubsub::PubSubClient::synpub_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void pubsub::PubSubClient::update_pubsub_data_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
