#ifndef TILAKONE_H
#define TILAKONE_H

#include <QJsonObject>
#include <QObject>
#include <QMainWindow>
#include <QTableWidgetItem>

#include <rfid125.h>
#include <mainwindow.h>
#include <pinui3.h>


class Tilakone : public QObject
{

    Q_OBJECT

public:
    Tilakone(MainWindow*);

    enum state {
        MainWindow,
        AwaitingPin,
        AwaitingDecision,
        Transactions,
        ChooseAmount,
        DisplayBalance,
        WithdrawMoney,
        TransferMoney,
        EndScreen
    };
    enum event {
        SMStart,            //This is for resetting all variables and objects in case of unexpected restart
        CardInserted,
        Timeout,            //Timeout is a timed event for 30sec inactivity that is relevant in most states
        IncorrectPIN,
        TooManyIncorrectPINs,
        LockCard,
        CorrectPIN,
        ShowTransactions,
        LogOut,             //Each screen show should have the opportunity to log out of endpoint
        ShowOptions,
        DrawMoney,
        CheckBalance,
        LoginCheck,
        ShowTransfer
    };

public slots:
    void runStateMachine(Tilakone::state, Tilakone::event);

    //RFID slots
    void recieveFromRFID125(QByteArray);

    //RESTAPI slots
    void fromRESTAPILogin(QJsonObject);
    void fromRESTAPILogout(QJsonObject);
    void fromRESTAPIGetAccTransactions(QJsonObject);
    void fromRESTAPIGetAccBalance(QJsonObject);
    void fromRESTAPIGetCustCards(QJsonObject);
    void fromRESTAPIWithdraw(QJsonObject);
    void fromRESTAPITransact(QJsonObject);
    void fromRESTAPICardLocked(QJsonObject);

    //PINUI slots
    void fromPINUIPinEntered(QString);
    void fromPINUIPinCancelled();
    void fromPINUIButtonPressed();

    //UI slots
    void uiConfirmAmount();
    void clickTransactions();
    void clickDraw();
    void clickBalance();
    void clickTransfer();
    void clickMore();
    void clickLess();
    void clickBack();
    void clickLogout();
    void comboBoxSelect(int);

    //Timer
    void handleTimeout();

signals:
    //send these to runStateMachine slot
    void mainWindow_WaitingCard(Tilakone::state, Tilakone::event);
    void mainWindow_AwaitingPin(Tilakone::state,Tilakone::event);
    void decisionWindow_drawDecision(Tilakone::state, Tilakone::event);
    void decisionWindow_transactionDecision(Tilakone::state, Tilakone::event);
    void decisionWindow_balanceDecision(Tilakone::state, Tilakone::event);
    void drawWindow_drawDecision(Tilakone::state, Tilakone::event);

    //send to RESTAPI
    void loginCheck(QString, QString);
    void logoutCheck();
    void lockCard();
    void getAccTransactions(int, int);
    void getAccBalance();
    void withdraw(double);
    void getCustCards();
    void transferMoney(double, QString);

private:
    //Handler for each state with values for any event related
    void stateMainWindow(event n);
    void stateAwaitingPin(event n);
    void stateAwaitingDecision(event n);
    void stateTransactions(event n);
    void stateChooseAmount(event n);
    void stateDisplayBalance(event n);
    void stateDrawMoney(event n);
    void stateTransferMoney(event n);
    void stateEndScreen();

    void addToUiTransactions(int, int);
    void addToUiBalance();

    void timeMachine(int);

    PinUi3* pPinUi3;
    QTimer* timer;

    QTableWidgetItem* column1;
    QTableWidgetItem* column2;
    QTableWidgetItem* column3;
    QTableWidgetItem* column4;
    QTableWidgetItem* column5;
    QTableWidgetItem* column6;
    QTableWidgetItem* column7;
    QTableWidgetItem* column8;
    QTableWidgetItem* column9;
    QTableWidgetItem* column10;

protected:
    QString stringID;
    QString insertedPIN;
    QString chosenAmount;
    QString accBalance;
    QString chosenAcc;

    QString custCard1;
    QString custCard2;
    QString custCard3;
    QString custCard4;
    QString custCard5;
    QString custCard6;
    QString custCard7;
    QString custCard8;
    QString custCard9;
    QString custCard10;

    QJsonObject loginINFO;
    QStringList accTransactions;
    QStringList accSumma;
    QStringList accTapahtuma;
    QStringList accAikaleima;
    QStringList custCards;

    event currentEvent;
    state currentState;

    short int wrongPIN;
    int offsetGlobal;
    double amountDouble;

    bool pinloop;
};

#endif // TILAKONE_H
