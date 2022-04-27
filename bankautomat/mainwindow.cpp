#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Here are methods for keeping .ui files to a minimum

void MainWindow::pinUiVisibility(bool b = true)         //Method for handling pinUI visibility
{
    this->ui->NumberInput->setEnabled(b);
    qDebug()<<"NumberInput visibility changed to " << b;
}

void MainWindow::setMessageLabel(QString n)             //Method for changing text on MessageLabel
{
    this->ui->MessageLabel->setText(n);
}

//Here NumberInput clicks

void MainWindow::on_number1_clicked()
{
    pinCheck = pinCheck + 1;
    qDebug()<<pinCheck;
}


void MainWindow::on_number2_clicked()
{
    pinCheck = pinCheck + 2;
    qDebug()<<pinCheck;
}


void MainWindow::on_number3_clicked()
{
    pinCheck = pinCheck + 3;
    qDebug()<<pinCheck;
}


void MainWindow::on_number4_clicked()
{
    pinCheck = pinCheck + 4;
    qDebug()<<pinCheck;
}


void MainWindow::on_number5_clicked()
{
    pinCheck = pinCheck + 5;
    qDebug()<<pinCheck;
}


void MainWindow::on_number6_clicked()
{
    pinCheck = pinCheck + 6;
    qDebug()<<pinCheck;
}


void MainWindow::on_number7_clicked()
{
    pinCheck = pinCheck + 7;
    qDebug()<<pinCheck;
}


void MainWindow::on_number8_clicked()
{
    pinCheck = pinCheck + 8;
    qDebug()<<pinCheck;
}


void MainWindow::on_number9_clicked()
{
    pinCheck = pinCheck + 9;
    qDebug()<<pinCheck;
}


void MainWindow::on_number0_clicked()
{
    pinCheck = pinCheck + 0;
    qDebug()<<pinCheck;
}
