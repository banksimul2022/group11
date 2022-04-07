#include "dllrestapi.h"
#include <QDebug>

DLLRestAPI::DLLRestAPI(QString baseUrl)
{
    pRestAPIEngine = new RestAPIEngine(baseUrl);
    connect(pRestAPIEngine, SIGNAL(toDllLoginProcessedSignal(QString)), this, SLOT(fromEngineLoginProcessedSlot(QString)));
    connect(pRestAPIEngine, SIGNAL(toDllGetAccTransactsSignal(QJsonArray)), this, SLOT(fromEngineGetAccTransactsProcessedSlot(QJsonArray)));
    connect(pRestAPIEngine, SIGNAL(toDllGetAccBalanceSignal(double)), this, SLOT(fromEngineGetAccBalanceProcessedSlot(double)));
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
    emit toExeLogoutProcessedSignal(true);
}

void DLLRestAPI::fromExeGetAccTransactsSlot(int offset, int noOfRows)
{
    if (cardNumber.length() <= 0) {
        qDebug() << "Get account transactions request failed. No cardnumber: " << cardNumber;
        return;
    }
    qDebug() << "Get account transactions from server";
    pRestAPIEngine->fromDllGetAccTransactsSlot(cardNumber, offset, noOfRows);

}

void DLLRestAPI::fromExeGetAccBalance()
{
    if (cardNumber.length() <= 0) {
        qDebug() << "Get account balance request failed. No cardnumber: " << cardNumber;
        return;
    }
    qDebug() << "Get account balance from server";
    pRestAPIEngine->fromDllGetAccBalanceSlot(cardNumber);
}

void DLLRestAPI::fromExeWithdraw(double amount)
{

}

void DLLRestAPI::fromExeTransact(double amount, QString targetCardNumber)
{

}

void DLLRestAPI::fromEngineLoginProcessedSlot(QString result)
{
    if(result != "false")
    {
        qDebug() << "Login succeeded. Sending result to exe";
        token = result;
        emit toExeLoginProcessedSignal(true);
    } else {
        qDebug() << "Login failed. Sending result to exe";
        cardNumber = "";
        emit toExeLoginProcessedSignal(false);
    }
}

void DLLRestAPI::fromEngineGetAccTransactsProcessedSlot(QJsonArray result)
{
    qDebug() << "Get account transactions processed. Sending result to exe";
    emit toExeGetAccTransactsProcessedSignal(result);
}

void DLLRestAPI::fromEngineGetAccBalanceProcessedSlot(double result)
{
    qDebug() << "Get account balance processed. Sending result to exe";
    emit toExeGetAccBalanceProcessedSignal(result);
}

void DLLRestAPI::fromEngineWithdrawProcessedSlot(bool result)
{

}

void DLLRestAPI::fromEngineTransactProcessedSlot(bool result)
{

}
