#include "tilakone.h"
#include "mainwindow.h"
#include "rfid125.h"
#include "dllrestapi.h"
#include "pinui3.h"
#include "PinUi3_global.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMainWindow>


class RFID125 oRFID;
DLLRestAPI* oRestAPI = new DLLRestAPI("https://banksimul-g11.herokuapp.com/");
MainWindow* w = nullptr;
//class PinUi3 oPinUi;
//Must construct Qapplication before qwidget

Tilakone::Tilakone(class MainWindow* p)
{
    //Set variables to be nothing on
    stringID = "";
    insertedPIN = "";
    pinloop = true;

    w = p;

    //STATEMACHINE connections
    connect(this, SIGNAL(mainWindow_WaitingCard(Tilakone::state,Tilakone::event)),
                     this, SLOT(runStateMachine(Tilakone::state,Tilakone::event)));

    //RFID connections
    connect(&oRFID, SIGNAL(sendToExe(QByteArray)),
            this, SLOT(recieveFromRFID125(QByteArray)));

    //RESTAPI connections
    connect(this, SIGNAL(loginCheck(QString,QString)),                   //Login
            oRestAPI, SLOT(fromExeLoginSlot(QString,QString)));
    connect(this, SIGNAL(logoutCheck()),                                 //Logout
            oRestAPI, SLOT(fromExeLogoutSlot()));
    connect(this, SIGNAL(getAccTransactions(int,int)),                   //Transactions
            oRestAPI, SLOT(fromExeGetAccTransactsSlot(int,int)));
    connect(this, SIGNAL(getAccBalance()),                               //Balance
            oRestAPI, SLOT(fromExeGetAccBalanceSlot()));
    connect(this, SIGNAL(getCustCards()),                                //CustCards
            oRestAPI, SLOT(fromExeGetCustCardsSlot()));
    connect(this, SIGNAL(withdraw(double)),                              //Withdraw
            oRestAPI, (SLOT(fromExeWithdrawSlot(double))));
    connect(this, SIGNAL(transferMoney(double,QString)),                 //Transfer
            oRestAPI, SLOT(fromExeTransactSlot(double,QString)));
    connect(this, SIGNAL(lockCard()),                                    //CardLock
            oRestAPI, SLOT(fromExeLockCardSlot()));

    connect(oRestAPI, SIGNAL(toExeLoginProcessedSignal(QJsonObject)),           //Login
            this, SLOT(fromRESTAPILogin(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeLogoutProcessedSignal(QJsonObject)),          //Logout
            this, SLOT(fromRESTAPILogout(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeGetAccTransactsProcessedSignal(QJsonObject)), //Transactions
            this, SLOT(fromRESTAPIGetAccTransactions(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeGetAccBalanceProcessedSignal(QJsonObject)),   //Balance
            this, SLOT(fromRESTAPIGetAccBalance(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeGetCustCardsProcessedSignal(QJsonObject)),    //CustCards
            this, SLOT(fromRESTAPIGetCustCards(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeWithdrawProcessedSignal(QJsonObject)),        //Withdraw
            this, SLOT(fromRESTAPIWithdraw(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeTransactProcessedSignal(QJsonObject)),        //Transfer
            this, SLOT(fromRESTAPITransact(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeLockCardProcessedSignal(QJsonObject)),        //CardLock
            this, SLOT(fromRESTAPICardLocked(QJsonObject)));

    /*
    //PINUI connections
    connect(oPinUi, SIGNAL(toExePinCodeEntered(QString)),
            this, SLOT(fromPINUIPinEntered(QString)));
    connect(oPinUi, SIGNAL(toExeCancelPinCode()),
            this, SLOT(fromPINUIPinCancelled()));
    connect(oPinUi, SIGNAL(toExeButtonPressed()),
            this, SLOT(fromPINUIButtonPressed));
    */  //Commented out until fix is found

    //UI connections
    connect(w->ui->confirmButton, SIGNAL(clicked()),
            this, SLOT(uiConfirmPin()));

}

void Tilakone::runStateMachine(state n, event m)
{
    switch(n) {
    case 0:
        stateMainWindow(m);
        break;
    case 1:
        stateAwaitingPin(m);
        break;
    case 2:
        stateAwaitingDecision(m);
        break;
    case 3:
        stateTransactions(m);
        break;
    case 4:
        stateChooseAmount(m);
        break;
    case 5:
        stateDisplayBalance(m);
        break;
    case 6:
        stateDrawMoney(m);
        break;
    case 7:
        stateTransferMoney(m);
        break;
    default:
        qDebug()<<"runStateMachine default state!";
    }
}

void Tilakone::handleTimeOut()
{

}

bool Tilakone::handlePIN()
{
    if (insertedPIN >= 4) {
        return false;
    }
    return true;
}

void Tilakone::recieveFromRFID125(QByteArray n)
{
    this->stringID = QString(n);
    qDebug()<<stringID<<" recieved from rfiddll";
}

void Tilakone::fromRESTAPILogin(QJsonObject l)
{
    foreach(const QString& key, l.keys()) {
        QJsonValue value = l.value(key);
        loginINFO.insert(key, value.toString());
    }
}

void Tilakone::fromRESTAPILogout(QJsonObject)
{
    qDebug()<<"Logout processed!";
}

void Tilakone::fromRESTAPIGetAccTransactions(QJsonObject t)
{
    foreach(const QString& key, t.keys()) {
        QJsonValue value = t.value(key);
        accTransactions.insert(key, value.toString());
    }
}

void Tilakone::fromRESTAPIGetAccBalance(QJsonObject b)
{
    foreach(const QString& key, b.keys()) {
        QJsonValue value = b.value(key);
        accBalance.insert(key, value.toString());
    }
}

void Tilakone::fromRESTAPIGetCustCards(QJsonObject)
{

}

void Tilakone::fromRESTAPIWithdraw(QJsonObject n)
{
    if(n.contains("result")) {
        qDebug()<<"Withdrawal succesful";
        foreach(const QString& key, n.keys()) {
            QJsonValue value = n.value(key);
            qDebug()<< "Key: " << key << " Value: " << value.toString();
        }
    }
}

void Tilakone::fromRESTAPITransact(QJsonObject)
{

}

void Tilakone::fromRESTAPICardLocked(QJsonObject n)
{
    qDebug()<<"Card locked confirmation recieved!";
    foreach(const QString& key, n.keys()) {
        QJsonValue value = n.value(key);
        qDebug()<<"Key: " << key << " Value: " << value.toString();
    }
}

void Tilakone::fromPINUIPinEntered(QString)
{

}

void Tilakone::fromPINUIPinCancelled()
{

}

void Tilakone::fromPINUIButtonPressed()
{

}

void Tilakone::uiConfirmPin()
{
    insertedPIN = w->ui->lineEdit->text();
    qDebug()<<"PIN inserted is " << insertedPIN;
    pinloop = false;
}

void Tilakone::uiConfirmAmount()
{
    qDebug()<<"Amount to be withdrawn is ";
}

void Tilakone::stateMainWindow(event n)
{

    qDebug()<<"stateMainWindow";

    if (n == 0) {
        //Here to show default screen on opening or Insert Card -screen
        w->show();
        w->displayMessage();

        /*
        try {
            oRFID.readCardID();
        } catch (QString error) {
            qDebug()<<"readCardID error: "<<error;
            runStateMachine(stateMainWindow, SMStart);
        }
        //wait for answer
        */


        //here we do a pirkka solution because trycatch only crashes the program without rfid reader
        oRFID.testCardID();

        //Move to next state
        runStateMachine(AwaitingPin, CardInserted);

    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    }
}

void Tilakone::stateAwaitingPin(event n)
{
    if (n == 1) {

        //Pirkka
        qDebug()<<"stateAwaitingPin";
        /*
        PinUi3* pPinUi = new PinUi3;
        delete pPinUi;
        pPinUi = nullptr;
        */

        /*
        pPinCode->pinui();      //Opens dialog for entering pin
        */  //commented out until fix is found



        /*      //Pirkka(tm) ratkasu palvelimen yhdistystä varten
        if (insertedPIN.length() < 1) {
            insertedPIN = "1234";
        }
        */

        w->displayPinMenu();

        while(handlePIN()) {

        //Test for login with restapidll
        emit loginCheck(stringID, insertedPIN);
        if (loginINFO.contains("result")) {
            //this means login succesful
            qDebug()<< "loginINFO contains key:response";
            foreach(const QString& key, loginINFO.keys()) {
                QJsonValue value = loginINFO.value(key);
                qDebug()<< "key: " << key << " value: " << value.toString();
            }

            //move to next state
            runStateMachine(AwaitingDecision, ShowOptions);

        } else if (loginINFO.contains("error")) {
            //this means login was not succesful
            qDebug()<< "loginINFO contains key:error";
            foreach(const QString& key, loginINFO.keys()) {
                QJsonValue value = loginINFO.value(key);
                qDebug()<< "key: " << key << " value: " << value.toString();
            }

            //invoke incorrectpin event
            runStateMachine(AwaitingPin, IncorrectPIN);     //TODO: should propably check that the error is pin related
        }
        }
    } else if (n == 3) {
        //incorrect pin
        if (wrongPIN >= 3) {
            runStateMachine(AwaitingPin, TooManyIncorrectPINs);
        }
        wrongPIN++;
        qDebug()<< "number of incorrect pins: " << wrongPIN;
        runStateMachine(AwaitingPin, CardInserted);
    } else if (n == 4) {
        //Card will be locked
        emit lockCard();
        runStateMachine(MainWindow, SMStart);       //TODO: should be a cleanup state before restart
    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    }
}

void Tilakone::stateAwaitingDecision(event n)
{
    qDebug()<< "stateAwaitingDecision";

    if (n == 9) {
        qDebug()<<"Displaying options!";
        w->displayOptions();
    } else if (n == 7) {            //Show transactions ->
        //move to show transactions
        runStateMachine(Transactions, ShowTransactions);
    } else if (n == 10) {           //Draw money ->
        //move to choose amount screen
        runStateMachine(ChooseAmount, DrawMoney);
    } else if (n == 11) {           //Check balance ->
        //move to check balance screen
        runStateMachine(DisplayBalance, CheckBalance);
    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    } //TODO: Maybe also have logout option on all states
}

void Tilakone::stateTransactions(event n)
{
    qDebug()<< "stateTransactions, event: " << n;

    //restapidll request for 10 transactions starting from 0.th
    emit getAccTransactions(10, 0);
    foreach(const QString& key, accTransactions.keys()) {
        QJsonValue value = accTransactions.value(key);
        //place into ui element each transaction
        qDebug()<<"key: "<< key << " value: " << value;
    }

    //ui change here
    w->displayTransactions();

    //TODO: in displayTransactions, more and less buttons to refresh the displayed transactions
    //TODO: button to return to previous menu
}

void Tilakone::stateChooseAmount(event n)
{
    qDebug()<< "stateChooseAmount, event: " << n;

    //ui change here
    w->displayChooseAmount();

    //TODO: button to emit signal to restapidll for withdrawal
}

void Tilakone::stateDisplayBalance(event n)
{
    qDebug()<< "stateDisplayBalance, event: " << n;

    emit getAccBalance();

    foreach(const QString& key, accBalance.keys()) {
        QJsonValue value = accBalance.value(key);
        qDebug()<< "Key: " << key << " Value: " << value.toString();    //TODO: ui
    }

    //ui change here
    w->displayBalance();

    //TODO: back and logout buttons
}

void Tilakone::stateDrawMoney(event n)
{
    qDebug() << "stateDrawMoney, event: " << n;

    //ui change here
    w->displayChooseAmount();

    //from ui buttons to emit signal to restapidll
}

void Tilakone::stateTransferMoney(event n)
{
    qDebug()<< "stateTransferMoney, event " << n;

    //ui change here
    w->displayTransfer();

    //from ui to choose account and emit send transaction
}


