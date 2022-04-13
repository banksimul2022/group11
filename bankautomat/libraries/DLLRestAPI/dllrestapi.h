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
   void toExeWithdrawProcessedSignal(QJsonObject result);
   void toExeTransactProcessedSignal(QJsonObject result);
   void toExeLockCardProcessedSignal(QJsonObject result);

public slots:
   void fromExeLoginSlot(QString cardNumber, QString pinCode);
   void fromExeLogoutSlot();
   void fromExeGetAccTransactsSlot(int offset, int noOfRows);
   void fromExeGetAccBalanceSlot();
   void fromExeWithdrawSlot(double amount);
   void fromExeTransactSlot(double amount, QString targetCardNumber);
   void fromExeLockCardSlot();

private slots:
   void fromEngineLoginProcessedSlot(QJsonObject result);
   void fromEngineGetAccTransactsProcessedSlot(QJsonObject result);
   void fromEngineGetAccBalanceProcessedSlot(QJsonObject result);
   void fromEngineWithdrawProcessedSlot(QJsonObject result);
   void fromEngineTransactProcessedSlot(QJsonObject result);
   void fromEngineLockCardProcessedSlot(QJsonObject result);
};

#endif // DLLRESTAPI_H
