#include "pinui.h"
#include "ui_pinui.h"
#include "pincodedll.h"

PinUi::PinUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinUi)
{
    ui->setupUi(this);

    //When button is clicked, it will emit a signal and call a slot associated with given object
    connect(ui->Button1,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button2,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button3,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button4,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button5,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button6,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button7,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button8,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button9,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->Button0,SIGNAL(clicked()),this,SLOT(digit_pressed()));

}

PinUi::~PinUi()
{
    delete ui;
}

void PinUi::digit_pressed() //Function definiton for pressing a digit
{
    QPushButton * button = (QPushButton*)sender(); //Sender returns a pointer to the object that sent the signal, if called in a slot activated by
                                                   // a signal; otherwise it returns 0
    double buttonNumber;
    QString newNumber;

    buttonNumber = (ui->lineEditPinCode->text() + button->text()).toDouble(); //With this we can use the texts on buttons, instead of declaring a number to a each push button

    newNumber = QString::number(buttonNumber);

    ui->lineEditPinCode->setText(newNumber);
}

void PinUi::on_pushButton_Cancel_clicked()
{
    emit toExeCancelPinCode();
}

void PinUi::on_pushButton_Clear_clicked()
{
    setPinCode("");
}

const QString &PinUi::getPinCode() const
{
    return pinCode;
}

void PinUi::setPinCode(const QString &newPinCode)
{
    pinCode = newPinCode;
    ui->lineEditPinCode->setText(pinCode);
    emit toExeButtonPressed();
}

void PinUi::reset()
{
    setPinCode("");
}
