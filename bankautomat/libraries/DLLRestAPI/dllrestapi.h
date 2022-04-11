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
   void toExeLoginProcessedSignal(QJsonObject result);
   void toExeLogoutProcessedSignal(QJsonObject result);
   void toExeGetAccTransactsProcessedSignal(QJsonArray result);
   void toExeGetAccBalanceProcessedSignal(double result);
   void toExeWithdrawProcessedSignal(bool result); // TODO
   void toExeTransactProcessedSignal(bool result); // TODO

public slots:
   void fromExeLoginSlot(QString cardNumber, QString pinCode);
   void fromExeLogoutSlot();
   void fromExeGetAccTransactsSlot(int offset, int noOfRows);
   void fromExeGetAccBalance();
   void fromExeWithdraw(double amount); // TODO
   void fromExeTransact(double amount, QString targetCardNumber); // TODO

private slots:
   void fromEngineLoginProcessedSlot(QJsonObject result);
   void fromEngineGetAccTransactsProcessedSlot(QJsonArray result);
   void fromEngineGetAccBalanceProcessedSlot(double result);
   void fromEngineWithdrawProcessedSlot(bool result); // TODO
   void fromEngineTransactProcessedSlot(bool result); // TODO
};

#endif // DLLRESTAPI_H
