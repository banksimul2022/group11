#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include <QObject>
#include <QJsonArray>
#include "restapiengine.h"

class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI(QString baseUrl);
    ~DLLRestAPI();

private:
   RestAPIEngine *pRestAPIEngine;
   QString token;
   QString cardNumber;

signals:
   void toExeLoginProcessedSignal(bool result);
   void toExeLogoutProcessedSignal(bool result);
   void toExeGetAccTransactsProcessedSignal(QJsonArray result);
   void toExeGetAccBalanceProcessedSignal(double result);

public slots:
   void fromExeLoginSlot(QString cardNumber, QString pinCode);
   void fromExeLogoutSlot();
   void fromExeGetAccTransactsSlot();
   void fromExeGetAccBalance();

private slots:
   void fromEngineLoginProcessedSlot(QString result);
   void fromEngineGetAccTransactsProcessedSlot(QJsonArray result);
   void fromEngineGetAccBalanceProcessedSlot(double result);
};

#endif // DLLRESTAPI_H
