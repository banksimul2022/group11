#ifndef TILAKONE_H
#define TILAKONE_H

#include <QObject>

class Tilakone : public QObject
{

    Q_OBJECT

public:
    Tilakone();

    enum state {
        MainWindow,
        AwaitingPin,        //Is/can this be done in cardreader dll
        AwaitingDecision,
        Transactions,
        ChooseAmount,       //UI of chooseamount could have the opportynity to enter custom amount
        EnterCustomAmount   //so that the entercustomamount screen wouldn't be needed
    };
    enum event {
        SMStart,            //This is for resetting all variables and objects in case of unexpected restart
        CardInserted,
        Timeout,            //Timeout is a timed event for 30sec inactivity that is relevant in most states
        IncorrectPIN,
        TooMayIncorrectPINs,
        LockCard,
        CorrectPIN,
        ShowTransactions,
        LogOut,             //Each screen show should have the opportunity to log out of endpoint
        Draw,
        DrawDefault,        //Change to only one draw signal from ui obj
        DrawCustom,
        CheckBalance
    };

public slots:
    void runStateMachine(state, event);
    void handleTimeOut();
    //void cardInserted(); //for signal from cardreader dll

signals://send these to runStateMachine slot
    void mainWindow_WaitingCard(state, event);      //event to signal cardreader dll
    void decisionWindow_drawDecision(state, event);
    void decisionWindow_transactionDecision(state, event);
    void decisionWindow_balanceDecision(state, event);
    void drawWindow_drawDecision(state, event);

private:
    //Handler for each state with values for any event related
    void stateMainWindow(event n);
    void stateAwaitingPin(event n);
    void stateAwaitingDecision(event n);
    void stateTransactions(event n);
    void stateChooseAmount(event n);
    void stateEnterCustomAmount(event n);

};

#endif // TILAKONE_H
