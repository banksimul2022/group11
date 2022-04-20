#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_Login_clicked() //Function definiton for pressing a login button
{
    //Setting the password and also the next window wich is opened once a correct password has been entered
    QString password = ui->lineEdit_Pw->text();

    if(pinCheck.length == 4) {


    }
    else {
        QMessageBox::warning(this,"Login", "Password is incorrect!"); //Warning will appear if the user enters wrong password
    }
}

void MainWindow::digit_pressed() //Function definiton for pressing a digit
{
    QPushButton * button = (QPushButton*)sender(); //Sender returns a pointer to the object that sent the signal, if called in a slot activated by
                                                   // a signal; otherwise it returns 0
    double buttonNumber;
    QString newNumber;

    buttonNumber = (ui->lineEdit_Pw->text() + button->text()).toDouble(); //With this we can use the texts on buttons, instead of declaring a number to a each push button

    newNumber = QString::number(buttonNumber);

    ui->lineEdit_Pw->setText(newNumber);
}


void MainWindow::on_clearButton_clicked() //Simple clear button incase the password had some typos
{
    ui->lineEdit_Pw->setText("");
}

