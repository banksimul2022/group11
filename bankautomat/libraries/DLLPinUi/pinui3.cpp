#include "pinui3.h"

PinUi3::PinUi3(QObject *parent): QObject(parent)
{
    pPinCode= new PinCode;
    //pPinCode->show();
    connect(pPinCode,SIGNAL(toExePinCodeEntered(QString)),
            this, SLOT(reserveNumber(QString)));
}

PinUi3::~PinUi3()
{
    pPinCode->close();
    delete pPinCode;
}

void PinUi3::openUi()
{
    pPinCode->show();
}

void PinUi3::reserveNumber(QString pincode) //Ja tämä lähettää sen exelle
{
    emit sendNumberToExe(pincode);
    pPinCode->reject();
}
