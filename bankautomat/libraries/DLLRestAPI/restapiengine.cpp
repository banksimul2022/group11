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
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);
    jsonObj.insert("amount", amount);

    QNetworkRequest req((baseUrl + "/operaatiot/nosto"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineWithdrawResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromDllTransactSlot(QString cardNumber, double amount, QString targetCardNumber)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);
    jsonObj.insert("amount", amount);
    jsonObj.insert("targetCardNumber", targetCardNumber);

    QNetworkRequest req((baseUrl + "/operaatiot/siirto"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineTransactResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromEngineLoginResponseSlot(QNetworkReply *reply)
{
    responseData = reply->readAll();
    qDebug() << responseData;
    QJsonObject jsonObj = QJsonDocument::fromJson(responseData).object();
    emit toDllLoginProcessedSignal(jsonObj);
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
    responseData = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(responseData);
    QJsonObject jsonObj = json_doc.array()[0].toObject();
    qDebug() << json_doc["sqlMessage"];
}

void RestAPIEngine::fromEngineTransactResponseSlot(QNetworkReply *)
{
    responseData = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(responseData);
    qDebug() << json_doc;
}
