#ifndef RESTAPIENGINE_H
#define RESTAPIENGINE_H

#include <QString>
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
    void toDllLoginProcessedSignal(QString);

public slots:
    void fromDllLoginSlot(QString cardNumber, QString pinCode);

private slots:
    void fromEngineLoginResponseSlot(QNetworkReply*);
};

#endif // RESTAPIENGINE_H
