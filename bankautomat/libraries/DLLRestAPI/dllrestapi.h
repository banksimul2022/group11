#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include <QObject>
#include "restapiengine.h"

class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI(QString baseUrl);
    ~DLLRestAPI();

private:
   RestAPIEngine *pRestAPIEngine;

signals:
   void toExeLoginProcessedSignal(QString result);

public slots:
   void fromExeLoginSlot(QString cardNumber, QString pinCode);

private slots:
   void fromEngineLoginProcessedSlot(QString result);
};

#endif // DLLRESTAPI_H
