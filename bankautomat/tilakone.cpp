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
#include <QJsonValue>
#include <QMainWindow>
#include <QTableView>
#include <QList>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QTimer>


class RFID125 oRFID;    //Muuta siten että on tilakoneen lapsia
DLLRestAPI* oRestAPI = new DLLRestAPI("https://banksimul-g11.herokuapp.com/");
MainWindow* w = nullptr;

Tilakone::Tilakone(class MainWindow* p)
{
    //Set variables to be nothing
    stringID = "";
    insertedPIN = "";
    wrongPIN = 0;

    pPinUi3 = new PinUi3(this); //Pass this pointer so that if Tilakone is deleted, the PinUi will be also
    timer = new QTimer(this);

    w = p;

    //STATEMACHINE connections TODO: most are pointless
    connect(this, SIGNAL(mainWindow_WaitingCard(Tilakone::state,Tilakone::event)),
            this, SLOT(runStateMachine(Tilakone::state,Tilakone::event)));
    connect(this, SIGNAL(decisionWindow_drawDecision(Tilakone::state,Tilakone::event)),
            this, SLOT(runStateMachine(Tilakone::state,Tilakone::event)));
    connect(this, SIGNAL(decisionWindow_transactionDecision(Tilakone::state,Tilakone::event)),
            this, SLOT(runStateMachine(Tilakone::state,Tilakone::event)));
    connect(this, SIGNAL(decisionWindow_balanceDecision(Tilakone::state,Tilakone::event)),
            this, SLOT(runStateMachine(Tilakone::state,Tilakone::event)));
    connect(this, SIGNAL(mainWindow_AwaitingPin(Tilakone::state,Tilakone::event)),
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
    connect(this, SIGNAL(getCustInfo()),                                 //Customer info
            oRestAPI, SLOT(fromExeGetCustInfoSlot()));

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
    connect(oRestAPI, SIGNAL(toExeGetCustInfoProcessedSignal(QJsonObject)),     //Customer info
            this, SLOT(fromRESTAPICustInfo(QJsonObject)));


    //PINUI connections
    connect(pPinUi3, SIGNAL(sendNumberToExe(QString)),
            this, SLOT(fromPINUIPinEntered(QString)));
    connect(pPinUi3, SIGNAL(toExeCancelPinCode()),
            this, SLOT(fromPINUIPinCancelled()));
    connect(pPinUi3, SIGNAL(toExeButtonPressed()),
            this, SLOT(fromPINUIButtonPressed()));


    //UI connections
    connect(w->ui->transactionsButton, SIGNAL(clicked()),
            this, SLOT(clickTransactions()));
    connect(w->ui->drawCashButton, SIGNAL(clicked()),
            this, SLOT(clickDraw()));
    connect(w->ui->balanceButton, SIGNAL(clicked()),
            this, SLOT(clickBalance()));
    connect(w->ui->transferButton, SIGNAL(clicked()),
            this, SLOT(clickTransfer()));
    connect(w->ui->transactionMore, SIGNAL(clicked()),
            this, SLOT(clickMore()));
    connect(w->ui->transactionLess, SIGNAL(clicked()),
            this, SLOT(clickLess()));
    connect(w->ui->backButton, SIGNAL(clicked()),
            this, SLOT(clickBack()));
    connect(w->ui->confirmButton, SIGNAL(clicked()),
            this, SLOT(uiConfirmAmount()));
    connect(w->ui->logoutButton, SIGNAL(clicked()),
            this, SLOT(clickLogout()));
    connect(w->ui->transferConfirm, SIGNAL(clicked()),
            this, SLOT(confirmTransfer()));
    connect(w->ui->recieverAddress, SIGNAL(textHighlighted(QString)),
            this, SLOT(comboBoxSelect(QString)));
    connect(w->ui->shutdownButton, SIGNAL(clicked()),
            this, SLOT(clickShutdown()));

    //UI timer reset connects
    connect(w->ui->number0, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number1, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number2, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number3, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number4, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number5, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number6, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number7, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number8, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));
    connect(w->ui->number9, SIGNAL(clicked()),
            this, SLOT(fromPINUIButtonPressed()));

    //Time
    connect(timer, SIGNAL(timeout()),
            this, SLOT(handleTimeout()));
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
    case 8:
        stateEndScreen();
        break;
    case 9:
        return;
    default:
        qDebug()<<"runStateMachine default state!";
    }
}

void Tilakone::addToUiTransactions()
{
    //Clear and populate table
    w->ui->tableWidget->clearContents();
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 4; j++) {
            if(j==0){
                w->ui->tableWidget->setItem(i, j, new QTableWidgetItem(accAikaleima.at(i)));
            } else if (j==1) {
                w->ui->tableWidget->setItem(i, j, new QTableWidgetItem(accTapahtuma.at(i)));
            } else if (j==2) {
                w->ui->tableWidget->setItem(i, j, new QTableWidgetItem(accSumma.at(i)));
            } else if (j==3) {
                w->ui->tableWidget->setItem(i, j, new QTableWidgetItem(accTransactions.at(i)));
            }
        }
    }
}

void Tilakone::addToUiBalance()
{
    w->ui->DisplaySum->setText(accBalance);
}

void Tilakone::timeMachine(int n)   //Re-calling this funtion while timer is active will restart timer with new given value
{
    timer->start(n);        //Use timer with custom amounts of ms
}

void Tilakone::recieveFromRFID125(QByteArray n)
{
    this->stringID = QString(n);
    runStateMachine(AwaitingPin, CardInserted);
}

void Tilakone::fromRESTAPILogin(QJsonObject l)      //TODO: selvitä miksi pinui laukasee emit logincheck kahdesti
{
    foreach(const QString& key, l.keys()) {
        QJsonValue value = l.value(key);
        loginINFO.insert(key, value.toString());
    }
    if (l.contains("result")) {
        //this means login succesful
        //move to next state
        runStateMachine(AwaitingPin, GetCustInfo);
    } else if (l.contains("error")) {
        //this means login was not succesful
        //invoke incorrectpin event
        runStateMachine(AwaitingPin, IncorrectPIN);     //TODO: should propably check that the error is pin related
    }
}

void Tilakone::fromRESTAPILogout(QJsonObject)
{
    stringID = "";
    insertedPIN = "";
    chosenAmount = "";
    accBalance = "";

    runStateMachine(MainWindow, SMStart);
}

void Tilakone::fromRESTAPIGetAccTransactions(QJsonObject t)
{
    timeMachine(30000);

    QJsonArray subValue = t["result"].toArray();

    foreach(const QJsonValue& value, subValue) {
        QJsonObject obj = value.toObject();

        accAikaleima.append(obj["aikaleima"].toString());
        accSumma.append(QString::number(obj["summa"].toDouble()));
        accTapahtuma.append(obj["tapahtuma"].toString());
        accTransactions.append(obj["tilinumero"].toString());
        }
    addToUiTransactions();
}

void Tilakone::fromRESTAPIGetAccBalance(QJsonObject b)
{
    foreach(const QString& key, b.keys()) {
        QJsonValue value = b.value(key);
        accBalance = value.toString();
    }
    addToUiBalance();
}

void Tilakone::fromRESTAPIGetCustCards(QJsonObject c)   //TODO: selvitä miksi ei toimi
{
    w->ui->recieverAddress->clear();

    QJsonArray subValue = c["result"].toArray();

    foreach(const QJsonValue& value, subValue) {
        QJsonObject obj = value.toObject();
        custCards.append(obj["korttinumero"].toString());
        qDebug()<<"Lisätty kortti :" << obj["korttinumero"].toString();
    }

    w->ui->recieverAddress->addItems(custCards);
    //Move away from here by pressing transfer or back
    }

void Tilakone::fromRESTAPIWithdraw(QJsonObject n)
{
    if(n.contains("result")) {
        foreach(const QString& key, n.keys()) {
            QJsonValue value = n.value(key);
        }
    } else if(n.contains("error")) {
        qDebug()<<"Somethig went wrong withdrawing!";
        runStateMachine(AwaitingDecision, ShowOptions);
    }
    runStateMachine(EndScreen, LogOut);
}

void Tilakone::fromRESTAPITransact(QJsonObject) //transaction processed!
{
    qDebug()<<"Transfer confirmation recieved!";
    w->ui->DisplaySum->setText("");
    runStateMachine(AwaitingDecision, ShowOptions);
}

void Tilakone::fromRESTAPICardLocked(QJsonObject n)
{
    qDebug()<<"Card locked confirmation recieved!";

    foreach(const QString& key, n.keys()) {
        QJsonValue value = n.value(key);
        qDebug()<<"Key: " << key << " Value: " << value.toString();
    }

    stringID = "";
    insertedPIN = "";

    runStateMachine(MainWindow, SMStart);
}

void Tilakone::fromRESTAPICustInfo(QJsonObject n)
{
    qDebug()<<n;

    QJsonObject obj = n["result"].toObject();
    fName = obj["etunimi"].toString();
    sName = obj["sukunimi"].toString();

    runStateMachine(AwaitingDecision, ShowOptions);
}

void Tilakone::fromPINUIPinEntered(QString n)
{
    insertedPIN = n;
    runStateMachine(AwaitingPin, LoginCheck);
}

void Tilakone::fromPINUIPinCancelled()
{
    qDebug()<<"Pin cancelled, aborting";
    stringID = "";                          //Hide card info
    runStateMachine(MainWindow, SMStart);   //Return to start
}

void Tilakone::fromPINUIButtonPressed()
{
    timeMachine(30000); //Reset timer with 30sec
}

void Tilakone::uiConfirmAmount()
{
    amountDouble = w->chosenAmount.toDouble();
    emit withdraw(amountDouble);
}

void Tilakone::clickTransactions()
{
    w->ui->DisplaySum->setText("");
    runStateMachine(AwaitingDecision, ShowTransactions);
}

void Tilakone::clickDraw()
{
    w->ui->DisplaySum->setText("");
    runStateMachine(AwaitingDecision, DrawMoney);
}

void Tilakone::clickBalance()
{
    w->ui->DisplaySum->setText("");
    runStateMachine(AwaitingDecision, CheckBalance);
}

void Tilakone::clickMore()
{
    if (offsetGlobal >= 0) {
        offsetGlobal += 10;
        emit getAccTransactions(offsetGlobal, 10);
    }
}

void Tilakone::clickLess()
{
    if (offsetGlobal < 10) {
        qDebug()<<"invalid offsetGlobal too small!";
        offsetGlobal = 0;
        emit getAccTransactions(offsetGlobal, 10);
    } else if (offsetGlobal >= 10) {
        offsetGlobal -= 10;
        emit getAccTransactions(offsetGlobal, 10);
    }
}

void Tilakone::clickBack()
{
    switch(currentState) {
    case MainWindow:
        qDebug()<<"Cant' go further back";
        break;
    case AwaitingPin:
        currentState = MainWindow;
        currentEvent = SMStart;
        break;
    case AwaitingDecision:
        currentState = AwaitingDecision;  //can't go back to givin pin
        currentEvent = ShowOptions;
        break;
    case Transactions:
        currentState = AwaitingDecision;
        currentEvent = ShowOptions;
        break;
    case ChooseAmount:
        currentState = AwaitingDecision;
        currentEvent = ShowOptions;
        break;
    case DisplayBalance:
        currentState = AwaitingDecision;
        currentEvent = ShowOptions;
        break;
    case WithdrawMoney:
        currentState = AwaitingDecision;
        currentEvent = ShowOptions;
        break;
    case TransferMoney:
        currentState = AwaitingDecision;
        currentEvent = ShowOptions;
        break;
    case EndScreen:
        qDebug()<<"Cant go back from this!";
        break;
    case ExitState:
        qDebug()<<"HOW ARE YOU HERE!";
        break;
    }
    runStateMachine(currentState, currentEvent);
}

void Tilakone::clickLogout()
{
    emit logoutCheck();
}

void Tilakone::clickShutdown()
{
    qDebug()<<"Shutting Down!";

    w->close();
    runStateMachine(ExitState, LogOut);
}

void Tilakone::confirmTransfer()
{
    transferAmount = w->ui->DisplaySum->text().toDouble();
    chosenAcc = w->ui->recieverAddress->currentText();

    //pirkkaAcc = "0500AAAAAA";     //For when all else fails, there is Pirkka
    emit transferMoney(transferAmount, chosenAcc);
}

void Tilakone::comboBoxSelect(QString i)
{
    qDebug()<<"Chosen acc: " << i;
    chosenAcc = w->ui->recieverAddress->currentText();
}

void Tilakone::handleTimeout()
{
    qDebug()<<"Time's up!";
    emit logoutCheck();
}

void Tilakone::clickTransfer()
{
    w->ui->DisplaySum->setText("");
    runStateMachine(AwaitingDecision, ShowTransfer);
}

/*                             */
/*   THE MACHINE STARTS HERE   */
/*                             */
void Tilakone::stateMainWindow(event n)
{
    currentState = MainWindow;
    currentEvent = SMStart;

    if (n == SMStart) {
        //Here to show default screen on opening or Insert Card -screen
        w->show();
        w->displayPinMenu();

        try {
            oRFID.readCardID();
        } catch (int error) {
            qDebug()<<"readCardID error: "<<error;
            //emit mainWindow_WaitingCard(MainWindow, SMStart);
            QString message = "Please install card reader!";
            w->displayMessage();
            w->setMessageLabel(message);
            }
    }
}

void Tilakone::stateAwaitingPin(event n)
{
    currentState = AwaitingPin;

    timeMachine(30000); //Reset timer with 30sec

    if (n == CardInserted) {
        currentEvent = CardInserted;
        //pinuidll invocation
        pPinUi3->openUi();

        //instead of waiting pinuidll we just skip to next with pirkka niksi's
        //insertedPIN = "1234";
        //runStateMachine(AwaitingPin, LoginCheck);

    } else if (n == LoginCheck) {
        currentEvent = LoginCheck;        
        //Test for login with restapidll
        emit loginCheck(stringID, insertedPIN);

    } else if (n == IncorrectPIN) {
        currentEvent = IncorrectPIN;
        //incorrect pin
        if (wrongPIN >= 3) {
            runStateMachine(AwaitingPin, TooManyIncorrectPINs);
        }
        wrongPIN++;
        qDebug()<< "number of incorrect pins: " << wrongPIN;
        runStateMachine(AwaitingPin, CardInserted);
    } else if (n == TooManyIncorrectPINs) {
        currentEvent = LockCard;
        //Card will be locked
        wrongPIN = 0;
        emit lockCard();
    } else if (n == GetCustInfo) {
        wrongPIN = 0;
        //Lets get customer info to display on the next screen
        emit getCustInfo();
    }
}

void Tilakone::stateAwaitingDecision(event n)
{
    currentState = AwaitingDecision;

    timeMachine(30000); //Reset timer with 30sec

    if (n == 9) {
        currentEvent = ShowOptions;
        w->setGreetingsLabel("Greetings "+fName+" "+sName+"!");
        w->displayOptions();
    } else if (n == ShowTransactions) {         //Show transactions ->
        currentEvent = ShowTransactions;
        //move to show transactions
        runStateMachine(Transactions, ShowTransactions);
    } else if (n == DrawMoney) {                //Draw money ->
        currentEvent = DrawMoney;
        //move to choose amount screen
        runStateMachine(ChooseAmount, DrawMoney);
    } else if (n == CheckBalance) {            //Check balance ->
        currentEvent = CheckBalance;
        //move to check balance screen
        runStateMachine(DisplayBalance, CheckBalance);
    } else if (n == ShowTransfer) {           //TransferMoney ->
        currentEvent = ShowTransfer;
        //move to transfer screen
        runStateMachine(TransferMoney, ShowTransfer);
    }
}

void Tilakone::stateTransactions(event)
{
    currentState = Transactions;

    timeMachine(30000); //Reset timer with 30sec

    offsetGlobal = 0; //first time invocation to set 0

    //ui change here
    w->displayTransactions();

    //Get transactions from server
    emit getAccTransactions(offsetGlobal, 10);

}

void Tilakone::stateChooseAmount(event)
{
    currentState = ChooseAmount;

    timeMachine(30000); //Reset timer with 30sec

    //ui change here
    w->displayChooseAmount();
}

void Tilakone::stateDisplayBalance(event)
{
    currentState = DisplayBalance;

    timeMachine(30000); //Reset timer with 30sec

    w->displayBalance();

    emit getAccBalance();   //slot to this will push the values to ui    
}

void Tilakone::stateDrawMoney(event)
{
    currentState = WithdrawMoney;

    timeMachine(30000); //Reset timer with 30sec

    //ui change here
    w->displayChooseAmount();
}

void Tilakone::stateTransferMoney(event)
{
    currentState = TransferMoney;
    emit getCustCards();

    timeMachine(30000); //Reset timer with 30sec

    //ui change here
    w->displayTransfer();

    //HOME OF PIRKKA

}

void Tilakone::stateEndScreen()
{
    w->displayMessage();
    timer->stop();
    QTimer::singleShot(5000, this, SLOT(handleTimeout()));
}


