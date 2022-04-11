#include "tilakone.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>


Tilakone::Tilakone()
{
    qDebug()<<"In Tilakone constructor";

    QObject::connect(this, SIGNAL(mainWindow_WaitingCard()),
                     this, SLOT(runStateMachine()));
    QObject::connect(this, SIGNAL(),
                     this, SLOT());
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

void Tilakone::stateMainWindow(event n)
{
    if (n == 0) {
        //Here to show default screen on opening or Insert Card -screen

    } else if (n == 1) {
        //Call from cardreaderdll that card has been inserted and pin is required
        //Call to awaiting pin state
    } else if (n == 2) {
        //Default timeout event, clear all objects and restart
    }
}

void Tilakone::stateAwaitingPin(event n)
{

}
