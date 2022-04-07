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
    void toDllGetAccTransactsSignal(QJsonArray result);
    void toDllGetAccBalanceSignal(double result);

public slots:
    void fromDllLoginSlot(QString cardNumber, QString pinCode);
    void fromDllGetAccTransactsSlot(QString cardNumber, int offset, int noOfRows);
    void fromDllGetAccBalanceSlot(QString cardNumber);

private slots:
    void fromEngineLoginResponseSlot(QNetworkReply*);
    void fromEngineGetAccTransactsResponseSlot(QNetworkReply*);
    void fromEngineGetAccBalanceResponseSlot(QNetworkReply*);
};

#endif // RESTAPIENGINE_H
