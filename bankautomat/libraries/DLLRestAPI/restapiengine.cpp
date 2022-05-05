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

QJsonObject RestAPIEngine::replyToJsonObject(QNetworkReply * reply, bool debugOn)
{
    QByteArray responseData = reply->readAll();
    QJsonObject jsonObj = QJsonDocument::fromJson(responseData).object();
    if(debugOn) qDebug() << jsonObj;
    return jsonObj;
}

const QByteArray &RestAPIEngine::getToken() const
{
    return token;
}

void RestAPIEngine::setToken(const QByteArray &newToken)
{
    token = newToken;
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
    req.setRawHeader(QByteArray("Authorization"),QString("bearer ").append(token).toUtf8());

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
    req.setRawHeader(QByteArray("Authorization"),QString("bearer ").append(token).toUtf8());

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineGetAccBalanceResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromDllGetCustCardsSlot(QString cardNumber)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);

    QNetworkRequest req((baseUrl + "/operaatiot/kortit"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    req.setRawHeader(QByteArray("Authorization"),QString("bearer ").append(token).toUtf8());

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineGetCustCardsResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromDllGetCustInfoSlot(QString cardNumber)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);

    QNetworkRequest req((baseUrl + "/operaatiot/asiakastiedot"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    req.setRawHeader(QByteArray("Authorization"),QString("bearer ").append(token).toUtf8());

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineGetCustInfoResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromDllWithdrawSlot(QString cardNumber, double amount)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);
    jsonObj.insert("amount", amount);

    QNetworkRequest req((baseUrl + "/operaatiot/nosto"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    req.setRawHeader(QByteArray("Authorization"),QString("bearer ").append(token).toUtf8());

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
    req.setRawHeader(QByteArray("Authorization"),QString("bearer ").append(token).toUtf8());

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineTransactResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromDllLockCardSlot(QString cardNumber)
{
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber", cardNumber);
    jsonObj.insert("lockStatus", 1);

    QNetworkRequest req((baseUrl + "/operaatiot/muutalukitus"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    req.setRawHeader(QByteArray("Authorization"),QString("bearer ").append(token).toUtf8());

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fromEngineLockCardResponseSlot(QNetworkReply*)));

    reply = loginManager->post(req, QJsonDocument(jsonObj).toJson());
}

void RestAPIEngine::fromEngineLoginResponseSlot(QNetworkReply *reply)
{
    emit toDllLoginProcessedSignal(replyToJsonObject(reply, debugOn));
}

void RestAPIEngine::fromEngineGetAccTransactsResponseSlot(QNetworkReply *reply)
{
    emit toDllGetAccTransactsProcessedSignal(replyToJsonObject(reply, debugOn));
}

void RestAPIEngine::fromEngineGetAccBalanceResponseSlot(QNetworkReply *reply)
{
    emit toDllGetAccBalanceProcessedSignal(replyToJsonObject(reply, debugOn));
}

void RestAPIEngine::fromEngineGetCustCardsResponseSlot(QNetworkReply *reply)
{
    emit toDllGetCustCardsProcessedSignal(replyToJsonObject(reply, debugOn));
}

void RestAPIEngine::fromEngineGetCustInfoResponseSlot(QNetworkReply *reply)
{
    emit toDllGetCustInfoProcessedSignal(replyToJsonObject(reply, debugOn));
}

void RestAPIEngine::fromEngineWithdrawResponseSlot(QNetworkReply *reply)
{
    emit toDllWithdrawProcessedSignal(replyToJsonObject(reply, debugOn));
}

void RestAPIEngine::fromEngineTransactResponseSlot(QNetworkReply *reply)
{
    emit toDllTransactProcessedSignal(replyToJsonObject(reply, debugOn));
}

void RestAPIEngine::fromEngineLockCardResponseSlot(QNetworkReply *reply)
{
    emit toDllLockCardProcessedSignal(replyToJsonObject(reply, debugOn));
}
