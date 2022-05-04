#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QDebug>
#include <QStandardItem>
#include <QAbstractItemModel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    class QStandardItemModel* treeList = new QStandardItemModel;
    treeList->setRowCount(10);

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(1);

    //ui->tableWidget->setModel(treeList);

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

    //Connect choose amount buttons
    connect(ui->number0, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number1, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number2, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number3, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number4, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number5, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number6, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number7, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number8, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->number9, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->confirmButton, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->clearButton, SIGNAL(clicked()),
            this, SLOT(clearPressed()));

    //Connect choose amount buttons
    connect(ui->draw20, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->draw40, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->draw50, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->draw60, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->draw100, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->draw200, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
    connect(ui->draw500, SIGNAL(clicked()),
            this, SLOT(handleChooseAmount()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Here are methods for keeping .ui files to a minimum
void MainWindow::withdrawOptionsVisibility(bool b)
{
    //En jaksa tapella, pirkka ratkasut is go
    this->ui->draw20->setVisible(b);
    this->ui->draw40->setVisible(b);
    this->ui->draw50->setVisible(b);
    this->ui->draw60->setVisible(b);
    this->ui->draw100->setVisible(b);
    this->ui->draw200->setVisible(b);
    this->ui->draw500->setVisible(b);
    this->ui->amountOther->setVisible(b);
}

void MainWindow::messageLabelVisibility(bool b)
{
    this->ui->MessageLabel->setVisible(b);
}

void MainWindow::customAmountVisibility(bool b)
{
    //pirkka miehen pirkka niksit
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
    //this->ui->lineEdit_2->setVisible(b);
    //this->ui->DisplaySum->setVisible(b);
}

void MainWindow::optionsVisibility(bool b)
{
    this->ui->drawCashButton->setVisible(b);
    this->ui->transactionsButton->setVisible(b);
    this->ui->transferButton->setVisible(b);
    this->ui->balanceButton->setVisible(b);
}

void MainWindow::transactionVisibility(bool b)
{
    this->ui->transactionMore->setVisible(b);
    this->ui->transactionLess->setVisible(b);
    this->ui->tableWidget->setVisible(b);
}

void MainWindow::balanceVisibility(bool b)
{
    this->ui->DisplaySum->setVisible(b);
}

void MainWindow::transferVisibility(bool b)
{
    //this->ui->DisplaySum->setVisible(b);
    //this->ui->MessageLabel->setVisible(b);
    this->ui->recieverLabel->setVisible(b);
    this->ui->recieverAddress->setVisible(b);
    this->ui->transferConfirm->setVisible(b);
}

void MainWindow::backButtonVisibility(bool b)
{
    this->ui->backButton->setVisible(b);
}

void MainWindow::logoutButtonVisibility(bool b)
{
    this->ui->logoutButton->setVisible(b);
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

    this->withdrawOptionsVisibility(false);
    this->customAmountVisibility(false);
    this->optionsVisibility(false);
    this->transactionVisibility(false);
    this->backButtonVisibility(false);
    this->logoutButtonVisibility(false);
    this->transferVisibility(false);
    this->balanceVisibility(false);
    this->ui->transferConfirm->setVisible(false);
}

void MainWindow::displayOptions()
{
    QString message = "Choose action!";

    this->customAmountVisibility(false);
    this->withdrawOptionsVisibility(false);
    this->transactionVisibility(false);
    this->backButtonVisibility(false);
    this->transferVisibility(false);
    this->balanceVisibility(false);
    this->ui->transferConfirm->setVisible(false);

    this->messageLabelVisibility(true);
    this->optionsVisibility(true);
    this->logoutButtonVisibility(true);

    this->setMessageLabel(message);
}

void MainWindow::displayTransactions()
{
    this->customAmountVisibility(false);
    this->withdrawOptionsVisibility(false);
    this->messageLabelVisibility(false);
    this->optionsVisibility(false);
    this->transferVisibility(false);
    this->ui->transferConfirm->setVisible(false);

    this->transactionVisibility(true);
    this->backButtonVisibility(true);
    this->logoutButtonVisibility(true);
}

void MainWindow::displayChooseAmount()
{
    QString message = "Choose amount to withdraw!";

    this->withdrawOptionsVisibility(true);
    this->customAmountVisibility(true);
    this->messageLabelVisibility(true);
    this->backButtonVisibility(true);
    this->logoutButtonVisibility(true);
    this->balanceVisibility(true);

    this->optionsVisibility(false);
    this->transactionVisibility(false);
    this->transferVisibility(false);
    this->ui->transferConfirm->setVisible(false);

    this->setMessageLabel(message);
}

void MainWindow::displayTransfer()
{
    QString message = "Choose amount to transfer";

    this->balanceVisibility(false);
    this->optionsVisibility(false);
    this->transactionVisibility(false);
    this->withdrawOptionsVisibility(false);

    this->customAmountVisibility(true);
    this->ui->confirmButton->setVisible(false);

    this->messageLabelVisibility(true);
    this->backButtonVisibility(true);
    this->logoutButtonVisibility(true);
    this->transferVisibility(true);
    this->balanceVisibility(true);

    this->setMessageLabel(message);
}

void MainWindow::displayBalance()
{
    QString message = "Account balance";

    this->withdrawOptionsVisibility(false);
    this->customAmountVisibility(false);
    this->optionsVisibility(false);
    this->transactionVisibility(false);
    this->transferVisibility(false);
    this->ui->transferConfirm->setVisible(false);

    this->messageLabelVisibility(true);
    this->backButtonVisibility(true);
    this->logoutButtonVisibility(true);
    this->balanceVisibility(true);

    this->setMessageLabel(message);
}

void MainWindow::displayMessage()
{
    QString message = "Process ready, Thank you!";

    this->messageLabelVisibility(true);

    this->withdrawOptionsVisibility(false);
    this->customAmountVisibility(false);
    this->optionsVisibility(false);
    this->backButtonVisibility(false);
    this->logoutButtonVisibility(false);
    this->transferVisibility(false);
    this->transactionVisibility(false);
    this->balanceVisibility(false);
    this->ui->transferConfirm->setVisible(false);

    this->setMessageLabel(message);
}

void MainWindow::handleChooseAmount()   //Shameless copy from Aappo
{
    chosenAmount = this->ui->DisplaySum->text();

    QPushButton* button = (QPushButton*)sender();

    double buttonNumber;
    QString displayNumber;

    buttonNumber = (this->ui->DisplaySum->text() + button->text()).toDouble();
    displayNumber = QString::number(buttonNumber);

    this->ui->DisplaySum->setText(displayNumber);
    qDebug()<<ui->DisplaySum->text();
}

void MainWindow::numberPressed()    //Shameless copy from Aappo
{   /*
    QPushButton * button = (QPushButton*)sender();

    double buttonNumber;
    QString newNumber;

    buttonNumber = (ui->lineEdit->text() + button->text()).toDouble();
    newNumber = QString::number(buttonNumber);
    ui->lineEdit->setText(newNumber);
    */
}

void MainWindow::clearPressed()
{
    ui->DisplaySum->setText("");
}

