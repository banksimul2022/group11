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
    void toDllWithdrawProcessedSignal(QJsonObject result);  // TODO
    void toDllTransactProcessedSignal(QJsonObject result);  // TODO

public slots:
    void fromDllLoginSlot(QString cardNumber, QString pinCode);
    void fromDllGetAccTransactsSlot(QString cardNumber, int offset, int noOfRows);
    void fromDllGetAccBalanceSlot(QString cardNumber);
    void fromDllWithdrawSlot(QString cardNumber, double amount); // TODO
    void fromDllTransactSlot(QString cardNumber, double amount, QString targetCardNumber); // TODO

private slots:
    void fromEngineLoginResponseSlot(QNetworkReply*);
    void fromEngineGetAccTransactsResponseSlot(QNetworkReply*);
    void fromEngineGetAccBalanceResponseSlot(QNetworkReply*);
    void fromEngineWithdrawResponseSlot(QNetworkReply*); // TODO
    void fromEngineTransactResponseSlot(QNetworkReply*); // TODO
};

#endif // RESTAPIENGINE_H
