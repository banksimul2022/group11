#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    //Methods to control ui elements
    void pinUiVisibility(bool);
    void withdrawOptionsVisibility(bool);
    void messageLabelVisibility(bool);
    void customAmountVisibility(bool);
    void optionsVisibility(bool);
    void setMessageLabel(QString);

    //Different display settings for each state
    void displayPinMenu();      //This is for if PinUi.dll doesn't work
    void displayOptions();
    void displayTransactions();
    void displayChooseAmount();
    void displayTransfer();
    void displayBalance();

    void displayMessage();

     Ui::MainWindow *ui;

public slots:


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
