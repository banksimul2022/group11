#ifndef RESTAPIENGINE_H
#define RESTAPIENGINE_H

#include <QString>
#include <QJsonArray>
#include <QNetworkAccessManager>

class RestAPIEngine : public QObject
{
    Q_OBJECT
public:
    RestAPIEngine(QString baseUrl);
    ~RestAPIEngine();

private:
    QString baseUrl;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray responseData;
    QByteArray token;

signals:
    void toDllLoginProcessedSignal(QString result);
    void toDllGetAccTransactsProcessedSignal(QJsonArray result);
    void toDllGetAccBalanceProcessedSignal(double result);
    void toDllWithdrawProcessedSignal(double result);  // TODO
    void toDllTransactProcessedSignal(double result);  // TODO

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
