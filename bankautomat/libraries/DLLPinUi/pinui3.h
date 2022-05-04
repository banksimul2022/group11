#ifndef PINUI3_H
#define PINUI3_H

#include "PinUi3_global.h"
#include "pincode.h"
#include <QObject>

class PINUI3_EXPORT PinUi3: public QObject
{
    Q_OBJECT

public:
    PinUi3(QObject * parent= nullptr);
    ~PinUi3();
    void openUi();

signals:
    void toExePinCodeEntered(QString pincode);

    void toExeCancelPinCode();

    void toExeButtonPressed();

    void sendNumberToExe(QString pincode);

public slots:
    void reserveNumber(QString);

private:
    PinCode * pPinCode;
};

#endif // PINUI3_H
