#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connect numbers like Aappo does
    connect(ui->number0, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number1, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number2, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number3, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number4, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number5, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number6, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number7, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number8, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
    connect(ui->number9, SIGNAL(clicked()),
            this, SLOT(numberPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Here are methods for keeping .ui files to a minimum

void MainWindow::pinUiVisibility(bool b = true)         //Method for handling pinUI visibility
{
    //pirkka
    this->ui->number0->setVisible(b);
    this->ui->number1->setVisible(b);
    this->ui->number2->setVisible(b);
    this->ui->number3->setVisible(b);
    this->ui->number4->setVisible(b);
    this->ui->number5->setVisible(b);
    this->ui->number6->setVisible(b);
    this->ui->number7->setVisible(b);
    this->ui->number8->setVisible(b);
    this->ui->number9->setVisible(b);
    this->ui->clearButton->setVisible(b);
    this->ui->confirmButton->setVisible(b);
    this->ui->lineEdit->setVisible(b);

    qDebug()<<"NumberInput visibility changed to " << b;
}

void MainWindow::withdrawOptionsVisibility(bool b)
{
    //En jaksa tapella, pirkka ratkasut is go
    this->ui->pushButton->setVisible(b);
    this->ui->pushButton_2->setVisible(b);
    this->ui->pushButton_3->setVisible(b);
    this->ui->pushButton_4->setVisible(b);
    this->ui->pushButton_5->setVisible(b);
    this->ui->pushButton_6->setVisible(b);
    this->ui->pushButton_7->setVisible(b);
    this->ui->amountOther->setVisible(b);

    qDebug()<<"withdrawOptions visibility changed to " << b;
}

void MainWindow::messageLabelVisibility(bool b)
{
    this->ui->MessageLabel->setVisible(b);

    qDebug()<<"messageLabel visibility changed to " <<b;
}

void MainWindow::customAmountVisibility(bool b)
{
    //pirkka
    this->ui->number0_2->setVisible(b);
    this->ui->number1_2->setVisible(b);
    this->ui->number2_2->setVisible(b);
    this->ui->number3_2->setVisible(b);
    this->ui->number4_2->setVisible(b);
    this->ui->number5_2->setVisible(b);
    this->ui->number6_2->setVisible(b);
    this->ui->number7_2->setVisible(b);
    this->ui->number8_2->setVisible(b);
    this->ui->number9_2->setVisible(b);
    this->ui->clearButton_2->setVisible(b);
    this->ui->confirmButton_2->setVisible(b);
    this->ui->lineEdit_2->setVisible(b);

    qDebug()<<"AmountInput visibility chaged to " << b;
}

void MainWindow::optionsVisibility(bool b)
{
    this->ui->drawCashButton->setVisible(b);
    this->ui->transactionsButton->setVisible(b);
    this->ui->transferButton->setVisible(b);
    this->ui->balanceButton->setVisible(b);

    qDebug()<<"options visibility changed to " << b;
}

void MainWindow::setMessageLabel(QString n)
{
    this->ui->MessageLabel->setText(n);
}

void MainWindow::displayPinMenu()
{
    QString enter = "Insert card into reader!";

    this->messageLabelVisibility(true);
    this->setMessageLabel(enter);
    this->pinUiVisibility(true);

    this->withdrawOptionsVisibility(false);
    this->customAmountVisibility(false);
    this->optionsVisibility(false);
    this->ui->DisplaySum->setVisible(false);
}

void MainWindow::displayOptions()
{
    QString message = "Choose action!";
    this->pinUiVisibility(false);
    this->customAmountVisibility(false);
    this->withdrawOptionsVisibility(false);

    this->messageLabelVisibility(true);
    this->optionsVisibility(true);
    this->setMessageLabel(message);
}

void MainWindow::displayTransactions()
{

}

void MainWindow::displayChooseAmount()
{
    QString message = "Choose amount to withdraw!";

    this->withdrawOptionsVisibility(true);
    this->customAmountVisibility(true);
    this->messageLabelVisibility(true);

    this->optionsVisibility(false);
    this->pinUiVisibility(false);
    this->setMessageLabel(message);
}

void MainWindow::displayTransfer()
{

}

void MainWindow::displayBalance()
{

}

void MainWindow::displayMessage()
{
    this->messageLabelVisibility(true);

    this->withdrawOptionsVisibility(false);
    this->customAmountVisibility(false);
    this->optionsVisibility(false);
    this->pinUiVisibility(false);
    this->ui->DisplaySum->setVisible(false);
}

void MainWindow::numberPressed()
{
    QPushButton * button = (QPushButton*)sender();

    double buttonNumber;
    QString newNumber;

    buttonNumber = (ui->lineEdit->text() + button->text()).toDouble();
    newNumber = QString::number(buttonNumber);
    ui->lineEdit->setText(newNumber);
}

void MainWindow::clearPressed()
{
    ui->lineEdit->setText("");
}

