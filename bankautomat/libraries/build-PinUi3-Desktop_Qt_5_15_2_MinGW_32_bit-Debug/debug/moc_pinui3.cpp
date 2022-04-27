/****************************************************************************
** Meta object code from reading C++ file 'pinui3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DLLPinUi/pinui3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pinui3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PinUi3_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PinUi3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PinUi3_t qt_meta_stringdata_PinUi3 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "PinUi3"
QT_MOC_LITERAL(1, 7, 19), // "toExePinCodeEntered"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "pincode"
QT_MOC_LITERAL(4, 36, 18), // "toExeCancelPinCode"
QT_MOC_LITERAL(5, 55, 18), // "toExeButtonPressed"
QT_MOC_LITERAL(6, 74, 15), // "sendNumberToExe"
QT_MOC_LITERAL(7, 90, 13) // "reserveNumber"

    },
    "PinUi3\0toExePinCodeEntered\0\0pincode\0"
    "toExeCancelPinCode\0toExeButtonPressed\0"
    "sendNumberToExe\0reserveNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PinUi3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void PinUi3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PinUi3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toExePinCodeEntered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->toExeCancelPinCode(); break;
        case 2: _t->toExeButtonPressed(); break;
        case 3: _t->sendNumberToExe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->reserveNumber((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PinUi3::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinUi3::toExePinCodeEntered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PinUi3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinUi3::toExeCancelPinCode)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PinUi3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinUi3::toExeButtonPressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PinUi3::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinUi3::sendNumberToExe)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PinUi3::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PinUi3.data,
    qt_meta_data_PinUi3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PinUi3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PinUi3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PinUi3.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PinUi3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PinUi3::toExePinCodeEntered(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PinUi3::toExeCancelPinCode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PinUi3::toExeButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PinUi3::sendNumberToExe(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
