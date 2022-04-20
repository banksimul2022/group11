#include "tilakone.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include "rfid125.h"
#include "dllrestapi.h"

class MainWindow w;     //Create an object from class mainwindow to control GUI in Tilakone rahter than main
class RFID125 oRFID;
//class DLLRestAPI RESTAPI(QString baseURL);

DLLRestAPI* oRestAPI = new DLLRestAPI("https://banksimul-g11.herokuapp.com/");

Tilakone::Tilakone()
{
    qDebug()<<"In Tilakone constructor";

    QObject::connect(this, SIGNAL(mainWindow_WaitingCard()),
                     this, SLOT(runStateMachine()));
    QObject::connect(&oRFID, SIGNAL(sendToExe()),
                     this, SLOT(recieveFromRFID125()));
    //RESTAPI connections
    QObject::connect(this, SIGNAL(loginCheck()),
                     oRestAPI, SLOT(fromExeLoginSlot()));
    QObject::connect(this, SIGNAL(logoutCheck()),
                     oRestAPI, SLOT(fromExeLogoutSlot()));
    QObject::connect(oRestAPI, SIGNAL(toExeLoginProcessedSignal()),
                     this, SLOT(fromRESTAPILogin()));
    QObject::connect(oRestAPI, SIGNAL(toExeLogoutProcessedSignal()),
                     this, SLOT(fromRESTAPILogout()));
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
        //AwaitingDecision
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
}

void Tilakone::fromRESTAPILogin(QJsonObject)
{

}

void Tilakone::fromRESTAPILogout(QJsonObject)
{

}

void Tilakone::fromRESTAPIGetAccTransactions(QJsonObject)
{

}

void Tilakone::fromRESTAPIGetAccBalance(QJsonObject)
{

}

void Tilakone::fromRESTAPIwithdraw(QJsonObject)
{

}

void Tilakone::stateMainWindow(event n)
{
    QString enter = "Insert card into reader!";
    if (n == 0) {
        //Here to show default screen on opening or Insert Card -screen
        w.show();
        w.pinUiVisibility(false);
        w.setMessageLabel(enter);
        oRFID.readCardID();
        //wait for answer

        //Move to next state
        runStateMachine(AwaitingPin, CardInserted);     //Pirkka ratkasut toistaiseksi
    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    }
}

void Tilakone::stateAwaitingPin(event n)
{
    if (n == 1) {
        QString login = "Please insert PIN.";
        //Open login info here
        w.pinUiVisibility(true);
        w.setMessageLabel(login);
        //TODO: put a method here to wait until pin has been inserted into insertedPIN

        //Test for login with restapidll
        emit loginCheck(stringID, insertedPIN);
        if (loginINFO.contains("response")) {
            //this means login succesful
        } else if (loginINFO.contains("error")) {
            //this means login was not succesful
            //invoke incorrectpin event
        }

    } else if (n == 3) {
        //incorrect pin
    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    }
}

void Tilakone::stateAwaitingDecision(event n)
{
    if (n == 7) {
        //Show transactions ->
    } else if (n == 10) {
        //Draw money ->
    } else if (n == 11) {
        //Check balance ->
    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    } //Maybe also have logout option on all states
}

