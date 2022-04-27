#include "tilakone.h"
#include "mainwindow.h"
#include "rfid125.h"
#include "dllrestapi.h"

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

//class MainWindow w;
class RFID125 oRFID;
DLLRestAPI* oRestAPI = new DLLRestAPI("https://banksimul-g11.herokuapp.com/");
MainWindow* w = nullptr;

Tilakone::Tilakone(class MainWindow* p)
{
    //Set variables to be nothing on
    stringID = "";
    insertedPIN = "";

    w = p;

    //STATEMACHINE connections
    connect(this, SIGNAL(mainWindow_WaitingCard(Tilakone::state,Tilakone::event)),
                     this, SLOT(runStateMachine(Tilakone::state,Tilakone::event)));

    //RFID connections
    connect(&oRFID, SIGNAL(sendToExe(QByteArray)),
                     this, SLOT(recieveFromRFID125(QByteArray)));

    //RESTAPI connections
    connect(this, SIGNAL(loginCheck(QString,QString)),
                     oRestAPI, SLOT(fromExeLoginSlot(QString,QString)));
    connect(this, SIGNAL(logoutCheck()),
                     oRestAPI, SLOT(fromExeLogoutSlot()));
    connect(this, SIGNAL(lockCard()),
                     oRestAPI, SLOT(fromExeLockCardSlot()));
    connect(this, SIGNAL(getAccTransactions(int,int)),
                     oRestAPI, SLOT(fromExeGetAccTransactsSlot(int,int)));
    connect(this, SIGNAL(getAccBalance()),
                     oRestAPI, SLOT(fromExeGetAccBalanceSlot()));

    connect(oRestAPI, SIGNAL(toExeLoginProcessedSignal(QJsonObject)),
                     this, SLOT(fromRESTAPILogin(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeLogoutProcessedSignal(QJsonObject)),
                     this, SLOT(fromRESTAPILogout(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeGetAccTransactsProcessedSignal(QJsonObject)),
                     this, SLOT(fromRESTAPIGetAccTransactions(QJsonObject)));
    connect(oRestAPI, SIGNAL(toExeGetAccBalanceProcessedSignal(QJsonObject)),
                     this, SLOT(fromRESTAPIGetAccBalance(QJsonObject)));


    //TESTI connections
    connect(w, SIGNAL(testCardInserted(QByteArray)),
                     this, SLOT(recieveFromRFID125(QByteArray)));
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
        //Transactions
        break;
    case 4:
        //choose amount
        break;
    default:
        qDebug()<<"runStateMachine default state!";
    }
}

void Tilakone::handleTimeOut()
{

}

void Tilakone::recieveFromRFID125(QByteArray n)
{
    this->stringID = QString(n);
    qDebug()<<stringID<<" recieved from rfiddll";
}

void Tilakone::fromRESTAPILogin(QJsonObject)
{

}

void Tilakone::fromRESTAPILogout(QJsonObject)
{

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

void Tilakone::fromRESTAPIwithdraw(QJsonObject)
{

}

void Tilakone::stateMainWindow(event n)
{

    qDebug()<<"stateMainWindow";

    QString enter = "Insert card into reader!";
    if (n == 0) {
        //Here to show default screen on opening or Insert Card -screen
        w->show();
        w->pinUiVisibility(false);
        w->setMessageLabel(enter);


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

        qDebug()<<"StateAwaitingPin";

        QString login = "Please insert PIN.";

        //Open login info here
        w->pinUiVisibility(true);
        w->setMessageLabel(login);

        //Wait for pin

        //TODO: Kysele aappolta tähän koodi

        //Pirkka(tm) ratkasu palvelimen yhdistystä varten
        if (insertedPIN.length() < 1) {
            insertedPIN = "1234";
        }

        //Test for login with restapidll
        emit loginCheck(stringID, insertedPIN);
        if (loginINFO.contains("response")) {
            //this means login succesful
            qDebug()<< "loginINFO contains key:response";
            foreach(const QString& key, loginINFO.keys()) {
                QJsonValue value = loginINFO.value(key);
                qDebug()<< "key: " << key << " value: " << value.toString();
            }

            //move to next state
            runStateMachine(AwaitingDecision, CorrectPIN);
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

    } else if (n == 3) {
        //incorrect pin
        if (wrongPIN >= 3) {
            runStateMachine(AwaitingPin, TooManyIncorrectPINs);
            //Card will be locked
        }
        wrongPIN++;
        qDebug()<< "number of incorrect pins: " << wrongPIN;
        runStateMachine(AwaitingPin, CardInserted);
    } else if (n == 4) {
        //Send lock pin requesti to server
    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    }
}

void Tilakone::stateAwaitingDecision(event n)
{
    qDebug()<< "stateAwaitingDecision";
    //ui change here
    if (n == 7) {           //Show transactions ->

        //restapidll request for transactions 10 offset 0
        emit getAccTransactions(10, 0);
        foreach(const QString& key, accTransactions.keys()) {
            QJsonValue value = accTransactions.value(key);
            //place into ui element each transaction
            qDebug()<<"key: "<< key << " value: " << value;
        }
        //move to show transactions
        runStateMachine(Transactions, ShowTransactions);
    } else if (n == 10) {   //Draw money ->
            runStateMachine(ChooseAmount, Draw);
    } else if (n == 11) {   //Check balance ->

    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    } //Maybe also have logout option on all states
}


