#include "tilakone.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>
#include <rfid125.h>
#include <thread>

class MainWindow w;     //Create an object from class mainwindow to control GUI
class RFID125 oRFID;

std::thread t{

    };

Tilakone::Tilakone()
{
    qDebug()<<"In Tilakone constructor";

    QObject::connect(this, SIGNAL(mainWindow_WaitingCard()),
                     this, SLOT(runStateMachine()));
    QObject::connect(&oRFID, SIGNAL(sendToExe()),
                     this, SLOT(recieveFromRFID125()));
}

void Tilakone::runStateMachine(state n, event m)
{
    switch(n) {
    case 0:
        stateMainWindow(m);
        break;
    case 1:
        //awaitingPIN
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
    case 5:
        //EnterCustomAmount
        break;
    default:
        qDebug()<<"runStateMachine default state!";
    }
}

void Tilakone::handleTimeOut()
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
        //Here wait for interrupt from rfid thread


    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    }
}

void Tilakone::stateAwaitingPin(event n)
{

}
