#ifndef RESTAPIENGINE_H
#define RESTAPIENGINE_H

#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>

class RestAPIEngine : public QObject
{
    Q_OBJECT
public:
    RestAPIEngine(QString baseUrl);
    ~RestAPIEngine();

private:
    bool debugOn = true;
    QJsonObject replyToJsonObject(QNetworkReply *reply, bool debugOn);
    QString baseUrl;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray responseData;
    QByteArray token;

signals:
    void toDllLoginProcessedSignal(QJsonObject result);
    void toDllGetAccTransactsProcessedSignal(QJsonObject result);
    void toDllGetAccBalanceProcessedSignal(QJsonObject result);
    void toDllGetCustCardsProcessedSignal(QJsonObject result);
    void toDllWithdrawProcessedSignal(QJsonObject result);
    void toDllTransactProcessedSignal(QJsonObject result);
    void toDllLockCardProcessedSignal(QJsonObject result);

public slots:
    void fromDllLoginSlot(QString cardNumber, QString pinCode);
    void fromDllGetAccTransactsSlot(QString cardNumber, int offset, int noOfRows);
    void fromDllGetAccBalanceSlot(QString cardNumber);
    void fromDllGetCustCardsSlot(QString cardNumber);
    void fromDllWithdrawSlot(QString cardNumber, double amount);
    void fromDllTransactSlot(QString cardNumber, double amount, QString targetCardNumber);
    void fromDllLockCardSlot(QString cardNumber);

private slots:
    void fromEngineLoginResponseSlot(QNetworkReply*);
    void fromEngineGetAccTransactsResponseSlot(QNetworkReply*);
    void fromEngineGetAccBalanceResponseSlot(QNetworkReply*);
    void fromEngineGetCustCardsResponseSlot(QNetworkReply*);
    void fromEngineWithdrawResponseSlot(QNetworkReply*);
    void fromEngineTransactResponseSlot(QNetworkReply*);
    void fromEngineLockCardResponseSlot(QNetworkReply*);
};

#endif // RESTAPIENGINE_H
