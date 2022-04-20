#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Tähän connect() metodit
    QObject::connect(this, SIGNAL(on_number0_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number1_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number2_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number3_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number4_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number5_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number6_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number7_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number8_clicked()),
                     this, SLOT(numberClickHandler()));
    QObject::connect(this, SIGNAL(on_number9_clicked()),
                     this, SLOT(numberClickHandler()));
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



//Tästä eteenpäin appon koodia


//NumberInput click handler for storing inserted numbers

void clickHandler() {

}

//Here NumberInput clicks

void MainWindow::on_number1_clicked()
{

}


void MainWindow::on_number2_clicked()
{

}


void MainWindow::on_number3_clicked()
{

}


void MainWindow::on_number4_clicked()
{

}


void MainWindow::on_number5_clicked()
{

}


void MainWindow::on_number6_clicked()
{

}


void MainWindow::on_number7_clicked()
{

}


void MainWindow::on_number8_clicked()
{

}


void MainWindow::on_number9_clicked()
{

}


void MainWindow::on_number0_clicked()
{

}

void MainWindow::numberClickHandler()
{
    qDebug()<<sender()->objectName();
    qDebug()<<sender();
    //pinCheck.append(this->sender());
}

