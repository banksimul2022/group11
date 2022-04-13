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
   void toExeGetAccTransactsProcessedSignal(QJsonObject result);
   void toExeGetAccBalanceProcessedSignal(QJsonObject result);
   void toExeWithdrawProcessedSignal(QJsonObject result); // TODO
   void toExeTransactProcessedSignal(QJsonObject result); // TODO

public slots:
   void fromExeLoginSlot(QString cardNumber, QString pinCode);
   void fromExeLogoutSlot();
   void fromExeGetAccTransactsSlot(int offset, int noOfRows);
   void fromExeGetAccBalance();
   void fromExeWithdraw(double amount); // TODO
   void fromExeTransact(double amount, QString targetCardNumber); // TODO

private slots:
   void fromEngineLoginProcessedSlot(QJsonObject result);
   void fromEngineGetAccTransactsProcessedSlot(QJsonObject result);
   void fromEngineGetAccBalanceProcessedSlot(QJsonObject result);
   void fromEngineWithdrawProcessedSlot(QJsonObject result); // TODO
   void fromEngineTransactProcessedSlot(QJsonObject result); // TODO
};

#endif // DLLRESTAPI_H
