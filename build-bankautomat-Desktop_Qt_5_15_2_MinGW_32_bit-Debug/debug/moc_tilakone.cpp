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
    QByteArrayData data[34];
    char stringdata0[613];
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
QT_MOC_LITERAL(11, 206, 8), // "lockCard"
QT_MOC_LITERAL(12, 215, 18), // "getAccTransactions"
QT_MOC_LITERAL(13, 234, 13), // "getAccBalance"
QT_MOC_LITERAL(14, 248, 8), // "withdraw"
QT_MOC_LITERAL(15, 257, 12), // "getCustCards"
QT_MOC_LITERAL(16, 270, 13), // "transferMoney"
QT_MOC_LITERAL(17, 284, 15), // "runStateMachine"
QT_MOC_LITERAL(18, 300, 13), // "handleTimeOut"
QT_MOC_LITERAL(19, 314, 9), // "handlePIN"
QT_MOC_LITERAL(20, 324, 18), // "recieveFromRFID125"
QT_MOC_LITERAL(21, 343, 16), // "fromRESTAPILogin"
QT_MOC_LITERAL(22, 360, 17), // "fromRESTAPILogout"
QT_MOC_LITERAL(23, 378, 29), // "fromRESTAPIGetAccTransactions"
QT_MOC_LITERAL(24, 408, 24), // "fromRESTAPIGetAccBalance"
QT_MOC_LITERAL(25, 433, 23), // "fromRESTAPIGetCustCards"
QT_MOC_LITERAL(26, 457, 19), // "fromRESTAPIWithdraw"
QT_MOC_LITERAL(27, 477, 19), // "fromRESTAPITransact"
QT_MOC_LITERAL(28, 497, 21), // "fromRESTAPICardLocked"
QT_MOC_LITERAL(29, 519, 19), // "fromPINUIPinEntered"
QT_MOC_LITERAL(30, 539, 21), // "fromPINUIPinCancelled"
QT_MOC_LITERAL(31, 561, 22), // "fromPINUIButtonPressed"
QT_MOC_LITERAL(32, 584, 12), // "uiConfirmPin"
QT_MOC_LITERAL(33, 597, 15) // "uiConfirmAmount"

    },
    "Tilakone\0mainWindow_WaitingCard\0\0"
    "Tilakone::state\0Tilakone::event\0"
    "decisionWindow_drawDecision\0"
    "decisionWindow_transactionDecision\0"
    "decisionWindow_balanceDecision\0"
    "drawWindow_drawDecision\0loginCheck\0"
    "logoutCheck\0lockCard\0getAccTransactions\0"
    "getAccBalance\0withdraw\0getCustCards\0"
    "transferMoney\0runStateMachine\0"
    "handleTimeOut\0handlePIN\0recieveFromRFID125\0"
    "fromRESTAPILogin\0fromRESTAPILogout\0"
    "fromRESTAPIGetAccTransactions\0"
    "fromRESTAPIGetAccBalance\0"
    "fromRESTAPIGetCustCards\0fromRESTAPIWithdraw\0"
    "fromRESTAPITransact\0fromRESTAPICardLocked\0"
    "fromPINUIPinEntered\0fromPINUIPinCancelled\0"
    "fromPINUIButtonPressed\0uiConfirmPin\0"
    "uiConfirmAmount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tilakone[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  164,    2, 0x06 /* Public */,
       5,    2,  169,    2, 0x06 /* Public */,
       6,    2,  174,    2, 0x06 /* Public */,
       7,    2,  179,    2, 0x06 /* Public */,
       8,    2,  184,    2, 0x06 /* Public */,
       9,    2,  189,    2, 0x06 /* Public */,
      10,    0,  194,    2, 0x06 /* Public */,
      11,    0,  195,    2, 0x06 /* Public */,
      12,    2,  196,    2, 0x06 /* Public */,
      13,    0,  201,    2, 0x06 /* Public */,
      14,    1,  202,    2, 0x06 /* Public */,
      15,    0,  205,    2, 0x06 /* Public */,
      16,    2,  206,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    2,  211,    2, 0x0a /* Public */,
      18,    0,  216,    2, 0x0a /* Public */,
      19,    0,  217,    2, 0x0a /* Public */,
      20,    1,  218,    2, 0x0a /* Public */,
      21,    1,  221,    2, 0x0a /* Public */,
      22,    1,  224,    2, 0x0a /* Public */,
      23,    1,  227,    2, 0x0a /* Public */,
      24,    1,  230,    2, 0x0a /* Public */,
      25,    1,  233,    2, 0x0a /* Public */,
      26,    1,  236,    2, 0x0a /* Public */,
      27,    1,  239,    2, 0x0a /* Public */,
      28,    1,  242,    2, 0x0a /* Public */,
      29,    1,  245,    2, 0x0a /* Public */,
      30,    0,  248,    2, 0x0a /* Public */,
      31,    0,  249,    2, 0x0a /* Public */,
      32,    0,  250,    2, 0x0a /* Public */,
      33,    0,  251,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        case 7: _t->lockCard(); break;
        case 8: _t->getAccTransactions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->getAccBalance(); break;
        case 10: _t->withdraw((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->getCustCards(); break;
        case 12: _t->transferMoney((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->runStateMachine((*reinterpret_cast< Tilakone::state(*)>(_a[1])),(*reinterpret_cast< Tilakone::event(*)>(_a[2]))); break;
        case 14: _t->handleTimeOut(); break;
        case 15: { bool _r = _t->handlePIN();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->recieveFromRFID125((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 17: _t->fromRESTAPILogin((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 18: _t->fromRESTAPILogout((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 19: _t->fromRESTAPIGetAccTransactions((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 20: _t->fromRESTAPIGetAccBalance((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 21: _t->fromRESTAPIGetCustCards((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 22: _t->fromRESTAPIWithdraw((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 23: _t->fromRESTAPITransact((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 24: _t->fromRESTAPICardLocked((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 25: _t->fromPINUIPinEntered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->fromPINUIPinCancelled(); break;
        case 27: _t->fromPINUIButtonPressed(); break;
        case 28: _t->uiConfirmPin(); break;
        case 29: _t->uiConfirmAmount(); break;
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
        {
            using _t = void (Tilakone::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::lockCard)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::getAccTransactions)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::getAccBalance)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::withdraw)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::getCustCards)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Tilakone::*)(double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tilakone::transferMoney)) {
                *result = 12;
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
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
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

// SIGNAL 7
void Tilakone::lockCard()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Tilakone::getAccTransactions(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Tilakone::getAccBalance()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Tilakone::withdraw(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Tilakone::getCustCards()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Tilakone::transferMoney(double _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
