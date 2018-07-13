/****************************************************************************
** Meta object code from reading C++ file 'timercontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "timercontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timercontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimerController_t {
    QByteArrayData data[12];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimerController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimerController_t qt_meta_stringdata_TimerController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TimerController"
QT_MOC_LITERAL(1, 16, 11), // "timerUpdate"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "newValue"
QT_MOC_LITERAL(4, 38, 17), // "connectedToServer"
QT_MOC_LITERAL(5, 56, 22), // "disconnectedFromServer"
QT_MOC_LITERAL(6, 79, 9), // "connected"
QT_MOC_LITERAL(7, 89, 12), // "disconnected"
QT_MOC_LITERAL(8, 102, 9), // "readyRead"
QT_MOC_LITERAL(9, 112, 14), // "connectTimeout"
QT_MOC_LITERAL(10, 127, 17), // "attemptConnection"
QT_MOC_LITERAL(11, 145, 15) // "startConnection"

    },
    "TimerController\0timerUpdate\0\0newValue\0"
    "connectedToServer\0disconnectedFromServer\0"
    "connected\0disconnected\0readyRead\0"
    "connectTimeout\0attemptConnection\0"
    "startConnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimerController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TimerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimerController *_t = static_cast<TimerController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timerUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->connectedToServer(); break;
        case 2: _t->disconnectedFromServer(); break;
        case 3: _t->connected(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->readyRead(); break;
        case 6: _t->connectTimeout(); break;
        case 7: _t->attemptConnection(); break;
        case 8: _t->startConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimerController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimerController::timerUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TimerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimerController::connectedToServer)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TimerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimerController::disconnectedFromServer)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TimerController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimerController.data,
      qt_meta_data_TimerController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimerController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimerController.stringdata0))
        return static_cast<void*>(const_cast< TimerController*>(this));
    return QObject::qt_metacast(_clname);
}

int TimerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void TimerController::timerUpdate(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TimerController::connectedToServer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimerController::disconnectedFromServer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
