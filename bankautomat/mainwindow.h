#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qstandarditemmodel.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString chosenAmount;


    //Methods to control ui elements
    void withdrawOptionsVisibility(bool);
    void messageLabelVisibility(bool);
    void customAmountVisibility(bool);
    void optionsVisibility(bool);
    void transactionVisibility(bool);
    void balanceVisibility(bool);
    void transferVisibility(bool);
    void backButtonVisibility(bool);
    void logoutButtonVisibility(bool);
    void setMessageLabel(QString);
    void setGreetingsLabel(QString);

    //Different display settings for each state
    void displayPinMenu();      //Should rename, this is custom amount ui
    void displayOptions();
    void displayTransactions();
    void displayChooseAmount();
    void displayTransfer();
    void displayBalance();

    //Change message
    void displayMessage();

    Ui::MainWindow *ui;

public slots:
    void handleChooseAmount();

signals:
    void testCardInserted(QByteArray);

private slots:
    void numberPressed();
    void clearPressed();

private:


protected:
    short int pinCheck;

};
#endif // MAINWINDOW_H
