/****************************************************************************
** Meta object code from reading C++ file 'restapiengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DLLRestAPI/restapiengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'restapiengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RestAPIEngine_t {
    QByteArrayData data[25];
    char stringdata0[523];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RestAPIEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RestAPIEngine_t qt_meta_stringdata_RestAPIEngine = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RestAPIEngine"
QT_MOC_LITERAL(1, 14, 25), // "toDllLoginProcessedSignal"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 6), // "result"
QT_MOC_LITERAL(4, 48, 35), // "toDllGetAccTransactsProcessed..."
QT_MOC_LITERAL(5, 84, 33), // "toDllGetAccBalanceProcessedSi..."
QT_MOC_LITERAL(6, 118, 28), // "toDllWithdrawProcessedSignal"
QT_MOC_LITERAL(7, 147, 28), // "toDllTransactProcessedSignal"
QT_MOC_LITERAL(8, 176, 16), // "fromDllLoginSlot"
QT_MOC_LITERAL(9, 193, 10), // "cardNumber"
QT_MOC_LITERAL(10, 204, 7), // "pinCode"
QT_MOC_LITERAL(11, 212, 26), // "fromDllGetAccTransactsSlot"
QT_MOC_LITERAL(12, 239, 6), // "offset"
QT_MOC_LITERAL(13, 246, 8), // "noOfRows"
QT_MOC_LITERAL(14, 255, 24), // "fromDllGetAccBalanceSlot"
QT_MOC_LITERAL(15, 280, 19), // "fromDllWithdrawSlot"
QT_MOC_LITERAL(16, 300, 6), // "amount"
QT_MOC_LITERAL(17, 307, 19), // "fromDllTransactSlot"
QT_MOC_LITERAL(18, 327, 16), // "targetCardNumber"
QT_MOC_LITERAL(19, 344, 27), // "fromEngineLoginResponseSlot"
QT_MOC_LITERAL(20, 372, 14), // "QNetworkReply*"
QT_MOC_LITERAL(21, 387, 37), // "fromEngineGetAccTransactsResp..."
QT_MOC_LITERAL(22, 425, 35), // "fromEngineGetAccBalanceRespon..."
QT_MOC_LITERAL(23, 461, 30), // "fromEngineWithdrawResponseSlot"
QT_MOC_LITERAL(24, 492, 30) // "fromEngineTransactResponseSlot"

    },
    "RestAPIEngine\0toDllLoginProcessedSignal\0"
    "\0result\0toDllGetAccTransactsProcessedSignal\0"
    "toDllGetAccBalanceProcessedSignal\0"
    "toDllWithdrawProcessedSignal\0"
    "toDllTransactProcessedSignal\0"
    "fromDllLoginSlot\0cardNumber\0pinCode\0"
    "fromDllGetAccTransactsSlot\0offset\0"
    "noOfRows\0fromDllGetAccBalanceSlot\0"
    "fromDllWithdrawSlot\0amount\0"
    "fromDllTransactSlot\0targetCardNumber\0"
    "fromEngineLoginResponseSlot\0QNetworkReply*\0"
    "fromEngineGetAccTransactsResponseSlot\0"
    "fromEngineGetAccBalanceResponseSlot\0"
    "fromEngineWithdrawResponseSlot\0"
    "fromEngineTransactResponseSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RestAPIEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       7,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,  104,    2, 0x0a /* Public */,
      11,    3,  109,    2, 0x0a /* Public */,
      14,    1,  116,    2, 0x0a /* Public */,
      15,    2,  119,    2, 0x0a /* Public */,
      17,    3,  124,    2, 0x0a /* Public */,
      19,    1,  131,    2, 0x08 /* Private */,
      21,    1,  134,    2, 0x08 /* Private */,
      22,    1,  137,    2, 0x08 /* Private */,
      23,    1,  140,    2, 0x08 /* Private */,
      24,    1,  143,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    9,   12,   13,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,    9,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Double, QMetaType::QString,    9,   16,   18,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 20,    2,

       0        // eod
};

void RestAPIEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RestAPIEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toDllLoginProcessedSignal((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: _t->toDllGetAccTransactsProcessedSignal((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->toDllGetAccBalanceProcessedSignal((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 3: _t->toDllWithdrawProcessedSignal((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->toDllTransactProcessedSignal((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->fromDllLoginSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->fromDllGetAccTransactsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->fromDllGetAccBalanceSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->fromDllWithdrawSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 9: _t->fromDllTransactSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->fromEngineLoginResponseSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->fromEngineGetAccTransactsResponseSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 12: _t->fromEngineGetAccBalanceResponseSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 13: _t->fromEngineWithdrawResponseSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 14: _t->fromEngineTransactResponseSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RestAPIEngine::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestAPIEngine::toDllLoginProcessedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RestAPIEngine::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestAPIEngine::toDllGetAccTransactsProcessedSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RestAPIEngine::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestAPIEngine::toDllGetAccBalanceProcessedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RestAPIEngine::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestAPIEngine::toDllWithdrawProcessedSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RestAPIEngine::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestAPIEngine::toDllTransactProcessedSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RestAPIEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RestAPIEngine.data,
    qt_meta_data_RestAPIEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RestAPIEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RestAPIEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RestAPIEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RestAPIEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RestAPIEngine::toDllLoginProcessedSignal(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RestAPIEngine::toDllGetAccTransactsProcessedSignal(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RestAPIEngine::toDllGetAccBalanceProcessedSignal(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RestAPIEngine::toDllWithdrawProcessedSignal(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RestAPIEngine::toDllTransactProcessedSignal(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
