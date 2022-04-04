#include "restapiengine.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkReply>

RestAPIEngine::RestAPIEngine(QString baseUrl)
{
    this->baseUrl = baseUrl;
}

RestAPIEngine::~RestAPIEngine()
{
    delete loginManager;
    loginManager = nullptr;
    delete reply;
    reply = nullptr;
}

void RestAPIEngine::fromDllLoginSlot(QString cardNumber, QString pinCode)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);
    jsonObj.insert("pinCode", pinCode);

    QNetworkRequest req((baseUrl+"/login"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineLoginResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromEngineLoginResponseSlot(QNetworkReply *reply)
{
    responseData = reply->readAll();
    qDebug() << responseData;
    emit toDllLoginProcessedSignal(responseData);
}
