#include "dllrestapi.h"
#include <QDebug>
#include <QJsonObject>

DLLRestAPI::DLLRestAPI(QString baseUrl)
{
    pRestAPIEngine = new RestAPIEngine(baseUrl);
    connect(pRestAPIEngine, SIGNAL(toDllLoginProcessedSignal(QJsonObject)), this, SLOT(fromEngineLoginProcessedSlot(QJsonObject)));
    connect(pRestAPIEngine, SIGNAL(toDllGetAccTransactsProcessedSignal(QJsonObject)), this, SLOT(fromEngineGetAccTransactsProcessedSlot(QJsonObject)));
    connect(pRestAPIEngine, SIGNAL(toDllGetAccBalanceProcessedSignal(QJsonObject)), this, SLOT(fromEngineGetAccBalanceProcessedSlot(QJsonObject)));
    connect(pRestAPIEngine, SIGNAL(toDllWithdrawProcessedSignal(QJsonObject)), this, SLOT(fromEngineWithdrawProcessedSlot(QJsonObject)));
    connect(pRestAPIEngine, SIGNAL(toDllTransactProcessedSignal(QJsonObject)), this, SLOT(fromEngineTransactProcessedSlot(QJsonObject)));
}

DLLRestAPI::~DLLRestAPI()
{
    delete pRestAPIEngine;
    pRestAPIEngine = nullptr;
}

void DLLRestAPI::fromExeLoginSlot(QString cardNumber, QString pinCode)
{
    qDebug() << "Card: " << cardNumber << ", Pincode: " << pinCode;
    this->cardNumber = cardNumber;
    qDebug() << "Cardnumber saved to dll: " << this->cardNumber;
    pRestAPIEngine->fromDllLoginSlot(cardNumber, pinCode);
}

void DLLRestAPI::fromExeLogoutSlot()
{
    qDebug() << "Logging out. Token and cardNumber values are cleared";
    token = "";
    cardNumber = "";
    QJsonObject result;
    result.insert("result", "Logout succeeded");
    emit toExeLogoutProcessedSignal(result);
}

void DLLRestAPI::fromExeGetAccTransactsSlot(int offset, int noOfRows)
{
    qDebug() << "Get account transactions from server";
    pRestAPIEngine->fromDllGetAccTransactsSlot(cardNumber, offset, noOfRows);
}

void DLLRestAPI::fromExeGetAccBalance()
{
    qDebug() << "Get account balance from server";
    pRestAPIEngine->fromDllGetAccBalanceSlot(cardNumber);
}

void DLLRestAPI::fromExeWithdraw(double amount)
{
//    if (cardNumber.length() <= 0) {
//        qDebug() << "Withdraw request failed. No cardnumber: " << cardNumber;
//        return;
//    }
    qDebug() << "Withdrawing " << amount << " €";
    pRestAPIEngine->fromDllWithdrawSlot(cardNumber, amount);
}

void DLLRestAPI::fromExeTransact(double amount, QString targetCardNumber)
{
//    if (cardNumber.length() <= 0) {
//        qDebug() << "Transfer request failed. No cardnumber: " << cardNumber;
//        return;
//    }
    qDebug() << "Transfering " << amount << " € to cardnumber: " << targetCardNumber;
    pRestAPIEngine->fromDllTransactSlot(cardNumber, amount, targetCardNumber);
}

void DLLRestAPI::fromEngineLoginProcessedSlot(QJsonObject result)
{
    if(result.contains("token"))
    {
        qDebug() << "Login succeeded. Sending result to exe";
        token = result["token"].toString();
        emit toExeLoginProcessedSignal(result);
    } else {
        qDebug() << "Login failed. Sending result to exe";
        cardNumber = "";
        emit toExeLoginProcessedSignal(result);
    }
}

void DLLRestAPI::fromEngineGetAccTransactsProcessedSlot(QJsonObject result)
{
    qDebug() << "Get account transactions processed. Sending result to exe";
    emit toExeGetAccTransactsProcessedSignal(result);
}

void DLLRestAPI::fromEngineGetAccBalanceProcessedSlot(QJsonObject result)
{
    qDebug() << "Get account balance processed. Sending result to exe";
    emit toExeGetAccBalanceProcessedSignal(result);
}

void DLLRestAPI::fromEngineWithdrawProcessedSlot(QJsonObject result)
{
    qDebug() << "Withdraw processed. Sending result to exe";
    emit toExeWithdrawProcessedSignal(result);
}

void DLLRestAPI::fromEngineTransactProcessedSlot(QJsonObject result)
{
    qDebug() << "Transact processed. Sending result to exe";
    emit toExeTransactProcessedSignal(result);
}
