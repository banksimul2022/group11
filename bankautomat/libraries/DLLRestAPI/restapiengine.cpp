#include "restapiengine.h"

#include <QJsonArray>
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

void RestAPIEngine::fromDllGetAccTransactsSlot(QString cardNumber, int offset, int noOfRows)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);
    jsonObj.insert("offset", offset);
    jsonObj.insert("noOfRows", noOfRows);

    QNetworkRequest req((baseUrl + "/operaatiot/tilitapahtumat"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineGetAccTransactsResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromDllGetAccBalanceSlot(QString cardNumber)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);

    QNetworkRequest req((baseUrl + "/operaatiot/saldo"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineGetAccBalanceResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromDllWithdrawSlot(QString cardNumber, double amount)
{

}

void RestAPIEngine::fromDllTransactSlot(QString cardNumber, double amount, QString targetCardNumber)
{

}

void RestAPIEngine::fromEngineLoginResponseSlot(QNetworkReply *reply)
{
    responseData = reply->readAll();
    qDebug() << responseData;
    emit toDllLoginProcessedSignal(responseData);
}

void RestAPIEngine::fromEngineGetAccTransactsResponseSlot(QNetworkReply *)
{
    responseData = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(responseData);
    QJsonArray json_array = json_doc.array();
    qDebug() << json_array;
    emit toDllGetAccTransactsProcessedSignal(json_array);
}

void RestAPIEngine::fromEngineGetAccBalanceResponseSlot(QNetworkReply *)
{
    responseData = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(responseData);
    double result = json_doc.array()[0].toObject()["saldo"].toDouble();
    qDebug() << QString::number(result, 'f', 2);
    emit toDllGetAccBalanceProcessedSignal(result);
}

void RestAPIEngine::fromEngineWithdrawResponseSlot(QNetworkReply *)
{

}

void RestAPIEngine::fromEngineTransactResponseSlot(QNetworkReply *)
{

}
