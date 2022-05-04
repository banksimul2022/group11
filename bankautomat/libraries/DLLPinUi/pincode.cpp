#include "pincode.h"
#include "ui_pincode.h"

PinCode::PinCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinCode)
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

PinCode::~PinCode()
{
    delete ui;
}

void PinCode::digit_pressed() //Function definiton for pressing a digit
{
    QPushButton * button = (QPushButton*)sender(); //Sender returns a pointer to the object that sent the signal, if called in a slot activated by
                                                   // a signal; otherwise it returns 0
    double buttonNumber;
    int newNumber;

    buttonNumber = (ui->lineEditPinCode->text() + button->text()).toDouble(); //With this we can use the texts on buttons, instead of declaring a number to a each push button

    newNumber = (QString::number(buttonNumber)).length();
    if (newNumber == 0) {
        ui->lineEditPinCode->setText("");
    } else if (newNumber == 1) {
        ui->lineEditPinCode->setText("*");
    } else if (newNumber == 2) {
        ui->lineEditPinCode->setText("**");
    } else if (newNumber == 3) {
        ui->lineEditPinCode->setText("***");
    } else if (newNumber == 4) {
        ui->lineEditPinCode->setText("****");
    }
}

void PinCode::on_pushButton_Cancel_clicked()
{
    emit toExePinCodeEntered(pinCode);
}

void PinCode::on_pushButton_Clear_clicked()
{
    ui->lineEditPinCode->setText("");
}

void PinCode::InsertNumber()
{
    if(pinCode.length() >= 4)
    {
        emit toExePinCodeEntered(pinCode);
    }
}
