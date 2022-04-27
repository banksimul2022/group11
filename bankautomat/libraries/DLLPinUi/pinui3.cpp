#include "pinui3.h"

PinUi3::PinUi3(QObject *parent): QObject(parent)
{
    pPinCode= new PinCode;
    pPinCode->show();
    connect(pPinCode,SIGNAL(toExePinCodeEntered(QString)),
            this, SLOT(reserveNumber(QString)));
}

PinUi3::~PinUi3()
{

}

void PinUi3::reserveNumber(QString pincode)
{
    emit sendNumberToExe(pincode);
}
