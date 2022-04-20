/****************************************************************************
** Meta object code from reading C++ file 'tilakone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../bankautomat/tilakone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tilakone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tilakone_t {
    QByteArrayData data[19];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tilakone_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tilakone_t qt_meta_stringdata_Tilakone = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Tilakone"
QT_MOC_LITERAL(1, 9, 22), // "mainWindow_WaitingCard"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "Tilakone::state"
QT_MOC_LITERAL(4, 49, 15), // "Tilakone::event"
QT_MOC_LITERAL(5, 65, 27), // "decisionWindow_drawDecision"
QT_MOC_LITERAL(6, 93, 34), // "decisionWindow_transactionDec..."
QT_MOC_LITERAL(7, 128, 30), // "decisionWindow_balanceDecision"
QT_MOC_LITERAL(8, 159, 23), // "drawWindow_drawDecision"
QT_MOC_LITERAL(9, 183, 10), // "loginCheck"
QT_MOC_LITERAL(10, 194, 11), // "logoutCheck"
QT_MOC_LITERAL(11, 206, 15), // "runStateMachine"
QT_MOC_LITERAL(12, 222, 13), // "handleTimeOut"
QT_MOC_LITERAL(13, 236, 18), // "recieveFromRFID125"
QT_MOC_LITERAL(14, 255, 16), // "fromRESTAPILogin"
QT_MOC_LITERAL(15, 272, 17), // "fromRESTAPILogout"
QT_MOC_LITERAL(16, 290, 29), // "fromRESTAPIGetAccTransactions"
QT_MOC_LITERAL(17, 320, 24), // "fromRESTAPIGetAccBalance"
QT_MOC_LITERAL(18, 345, 19) // "fromRESTAPIwithdraw"

    },
    "Tilakone\0mainWindow_WaitingCard\0\0"
    "Tilakone::state\0Tilakone::event\0"
    "decisionWindow_drawDecision\0"
    "decisionWindow_transactionDecision\0"
    "decisionWindow_balanceDecision\0"
    "drawWindow_drawDecision\0loginCheck\0"
    "logoutCheck\0runStateMachine\0handleTimeOut\0"
    "recieveFromRFID125\0fromRESTAPILogin\0"
    "fromRESTAPILogout\0fromRESTAPIGetAccTransactions\0"
    "fromRESTAPIGetAccBalance\0fromRESTAPIwithdraw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tilakone[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    2,   94,    2, 0x06 /* Public */,
       6,    2,   99,    2, 0x06 /* Public */,
       7,    2,  104,    2, 0x06 /* Public */,
       8,    2,  109,    2, 0x06 /* Public */,
       9,    2,  114,    2, 0x06 /* Public */,
      10,    0,  119,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,  120,    2, 0x0a /* Public */,
      12,    0,  125,    2, 0x0a /* Public */,
      13,    1,  126,    2, 0x0a /* Public */,
      14,    1,  129,    2, 0x0a /* Public */,
      15,    1,  132,    2, 0x0a /* Public */,
      16,    1,  135,    2, 0x0a /* Public */,
      17,    1,  138,    2, 0x0a /* Public */,
      18,    1,  141,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,

       0        // eod
};

void Tilakone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tilakone *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mainWindow_WaitingCard((*reinterpret_cast< Tilakone::state(*)>(_a[1])),(*reinterpret_cast< Tilakone::event(*)>(_a[2]))); break;
        case 1: _t->decisionWindow_drawDecision((*reinterpret_cast< Tilakone::state(*)>(_a[1])),(*reinterpret_cast< Tilakone::event(*)>(_a[2]))); break;
        case 2: _t->decisionWindow_transactionDecision((*reinterpret_cast< Tilakone::state(*)>(_a[1])),(*reinterpret_cast< Tilakone::event(*)>(_a[2]))); break;
        case 3: _t->decisionWindow_balanceDecision((*reinterpret_cast< Tilakone::state(*)>(_a[1])),(*reinterpret_cast< Tilakone::event(*)>(_a[2]))); break;
        case 4: _t->drawWindow_drawDecision((*reinterpret_cast< Tilakone::state(*)>(_a[1])),(*reinterpret_cast< Tilakone::event(*)>(_a[2]))); break;
        case 5: _t->loginCheck((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->logoutCheck(); break;
        case 7: _t->runStateMachine((*reinterpret_cast< Tilakone::state(*)>(_a[1])),(*reinterpret_cast< Tilakone::event(*)>(_a[2]))); break;
        case 8: _t->handleTimeOut(); break;
        case 9: _t->recieveFromRFID125((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->fromRESTAPILogin((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 11: _t->fromRESTAPILogout((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 12: _t->fromRESTAPIGetAccTransactions((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 13: _t->fromRESTAPIGetAccBalance((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 14: _t->fromRESTAPIwithdraw((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tilakone::*)(Tilakone::state , Tilakone::event );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::mainWindow_WaitingCard)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(Tilakone::state , Tilakone::event );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::decisionWindow_drawDecision)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(Tilakone::state , Tilakone::event );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::decisionWindow_transactionDecision)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(Tilakone::state , Tilakone::event );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::decisionWindow_balanceDecision)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(Tilakone::state , Tilakone::event );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::drawWindow_drawDecision)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::loginCheck)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::logoutCheck)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tilakone::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Tilakone.data,
    qt_meta_data_Tilakone,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tilakone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tilakone::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tilakone.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tilakone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Tilakone::mainWindow_WaitingCard(Tilakone::state _t1, Tilakone::event _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tilakone::decisionWindow_drawDecision(Tilakone::state _t1, Tilakone::event _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tilakone::decisionWindow_transactionDecision(Tilakone::state _t1, Tilakone::event _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Tilakone::decisionWindow_balanceDecision(Tilakone::state _t1, Tilakone::event _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Tilakone::drawWindow_drawDecision(Tilakone::state _t1, Tilakone::event _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Tilakone::loginCheck(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Tilakone::logoutCheck()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
