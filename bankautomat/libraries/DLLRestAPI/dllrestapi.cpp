#include "dllrestapi.h"
#include <QDebug>

DLLRestAPI::DLLRestAPI(QString baseUrl)
{
    pRestAPIEngine = new RestAPIEngine(baseUrl);
    //connect(this, SIGNAL(toEngineLoginSignal(QString,QString)), pRestAPIEngine, SLOT(fromDllLoginSlot(QString, QString)));
    connect(pRestAPIEngine, SIGNAL(loginProcessedSignal(QString)), this, SLOT(fromEngineLoginProcessedSlot(QString)));
}

DLLRestAPI::~DLLRestAPI()
{
    delete pRestAPIEngine;
    pRestAPIEngine = nullptr;
}

void DLLRestAPI::fromExeLoginSlot(QString cardNumber, QString pinCode)
{
    qDebug() << "Kortti: " << cardNumber << ", Pinkoodi: " << pinCode;
    pRestAPIEngine->fromDllLoginSlot(cardNumber, pinCode);
}

void DLLRestAPI::fromEngineLoginProcessedSlot(QString result)
{
    emit toExeLoginProcessedSignal(result);
}
