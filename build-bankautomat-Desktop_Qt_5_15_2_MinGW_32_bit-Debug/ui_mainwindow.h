/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *MessageLabel;
    QWidget *layoutWidget;
    QGridLayout *NumberInput;
    QPushButton *number4;
    QPushButton *number6;
    QPushButton *number3;
    QPushButton *number0;
    QPushButton *number1;
    QPushButton *number9;
    QPushButton *number2;
    QPushButton *number5;
    QPushButton *number7;
    QPushButton *number8;
    QLineEdit *lineEdit;
    QPushButton *clearButton;
    QPushButton *confirmButton;
    QLineEdit *DisplaySum;
    QWidget *layoutWidget_2;
    QGridLayout *NumberInput_2;
    QPushButton *number6_2;
    QPushButton *number2_2;
    QPushButton *number5_2;
    QPushButton *number9_2;
    QPushButton *number8_2;
    QPushButton *number7_2;
    QPushButton *number3_2;
    QPushButton *number0_2;
    QPushButton *confirmButton_2;
    QPushButton *number1_2;
    QPushButton *clearButton_2;
    QPushButton *number4_2;
    QLineEdit *lineEdit_2;
    QWidget *widget;
    QFormLayout *Withdraw1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *widget1;
    QFormLayout *Withdraw2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *amountOther;
    QWidget *widget2;
    QGridLayout *gridLayout;
    QPushButton *drawCashButton;
    QPushButton *transactionsButton;
    QPushButton *balanceButton;
    QPushButton *transferButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(663, 503);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MessageLabel = new QLabel(centralwidget);
        MessageLabel->setObjectName(QString::fromUtf8("MessageLabel"));
        MessageLabel->setGeometry(QRect(250, 50, 141, 51));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 110, 254, 161));
        NumberInput = new QGridLayout(layoutWidget);
        NumberInput->setObjectName(QString::fromUtf8("NumberInput"));
        NumberInput->setSizeConstraint(QLayout::SetFixedSize);
        NumberInput->setContentsMargins(0, 0, 0, 0);
        number4 = new QPushButton(layoutWidget);
        number4->setObjectName(QString::fromUtf8("number4"));

        NumberInput->addWidget(number4, 2, 0, 1, 1);

        number6 = new QPushButton(layoutWidget);
        number6->setObjectName(QString::fromUtf8("number6"));

        NumberInput->addWidget(number6, 2, 2, 1, 1);

        number3 = new QPushButton(layoutWidget);
        number3->setObjectName(QString::fromUtf8("number3"));

        NumberInput->addWidget(number3, 1, 2, 1, 1);

        number0 = new QPushButton(layoutWidget);
        number0->setObjectName(QString::fromUtf8("number0"));

        NumberInput->addWidget(number0, 4, 1, 1, 1);

        number1 = new QPushButton(layoutWidget);
        number1->setObjectName(QString::fromUtf8("number1"));

        NumberInput->addWidget(number1, 1, 0, 1, 1);

        number9 = new QPushButton(layoutWidget);
        number9->setObjectName(QString::fromUtf8("number9"));

        NumberInput->addWidget(number9, 3, 2, 1, 1);

        number2 = new QPushButton(layoutWidget);
        number2->setObjectName(QString::fromUtf8("number2"));

        NumberInput->addWidget(number2, 1, 1, 1, 1);

        number5 = new QPushButton(layoutWidget);
        number5->setObjectName(QString::fromUtf8("number5"));

        NumberInput->addWidget(number5, 2, 1, 1, 1);

        number7 = new QPushButton(layoutWidget);
        number7->setObjectName(QString::fromUtf8("number7"));

        NumberInput->addWidget(number7, 3, 0, 1, 1);

        number8 = new QPushButton(layoutWidget);
        number8->setObjectName(QString::fromUtf8("number8"));

        NumberInput->addWidget(number8, 3, 1, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        NumberInput->addWidget(lineEdit, 0, 0, 1, 3);

        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        NumberInput->addWidget(clearButton, 4, 0, 1, 1);

        confirmButton = new QPushButton(layoutWidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        NumberInput->addWidget(confirmButton, 4, 2, 1, 1);

        DisplaySum = new QLineEdit(centralwidget);
        DisplaySum->setObjectName(QString::fromUtf8("DisplaySum"));
        DisplaySum->setGeometry(QRect(270, 110, 113, 24));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(190, 140, 254, 161));
        NumberInput_2 = new QGridLayout(layoutWidget_2);
        NumberInput_2->setObjectName(QString::fromUtf8("NumberInput_2"));
        NumberInput_2->setSizeConstraint(QLayout::SetFixedSize);
        NumberInput_2->setContentsMargins(0, 0, 0, 0);
        number6_2 = new QPushButton(layoutWidget_2);
        number6_2->setObjectName(QString::fromUtf8("number6_2"));

        NumberInput_2->addWidget(number6_2, 3, 2, 1, 1);

        number2_2 = new QPushButton(layoutWidget_2);
        number2_2->setObjectName(QString::fromUtf8("number2_2"));

        NumberInput_2->addWidget(number2_2, 2, 1, 1, 1);

        number5_2 = new QPushButton(layoutWidget_2);
        number5_2->setObjectName(QString::fromUtf8("number5_2"));

        NumberInput_2->addWidget(number5_2, 3, 1, 1, 1);

        number9_2 = new QPushButton(layoutWidget_2);
        number9_2->setObjectName(QString::fromUtf8("number9_2"));

        NumberInput_2->addWidget(number9_2, 4, 2, 1, 1);

        number8_2 = new QPushButton(layoutWidget_2);
        number8_2->setObjectName(QString::fromUtf8("number8_2"));

        NumberInput_2->addWidget(number8_2, 4, 1, 1, 1);

        number7_2 = new QPushButton(layoutWidget_2);
        number7_2->setObjectName(QString::fromUtf8("number7_2"));

        NumberInput_2->addWidget(number7_2, 4, 0, 1, 1);

        number3_2 = new QPushButton(layoutWidget_2);
        number3_2->setObjectName(QString::fromUtf8("number3_2"));

        NumberInput_2->addWidget(number3_2, 2, 2, 1, 1);

        number0_2 = new QPushButton(layoutWidget_2);
        number0_2->setObjectName(QString::fromUtf8("number0_2"));

        NumberInput_2->addWidget(number0_2, 5, 1, 1, 1);

        confirmButton_2 = new QPushButton(layoutWidget_2);
        confirmButton_2->setObjectName(QString::fromUtf8("confirmButton_2"));

        NumberInput_2->addWidget(confirmButton_2, 5, 2, 1, 1);

        number1_2 = new QPushButton(layoutWidget_2);
        number1_2->setObjectName(QString::fromUtf8("number1_2"));

        NumberInput_2->addWidget(number1_2, 2, 0, 1, 1);

        clearButton_2 = new QPushButton(layoutWidget_2);
        clearButton_2->setObjectName(QString::fromUtf8("clearButton_2"));

        NumberInput_2->addWidget(clearButton_2, 5, 0, 1, 1);

        number4_2 = new QPushButton(layoutWidget_2);
        number4_2->setObjectName(QString::fromUtf8("number4_2"));

        NumberInput_2->addWidget(number4_2, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        NumberInput_2->addWidget(lineEdit_2, 1, 2, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 90, 88, 251));
        Withdraw1 = new QFormLayout(widget);
        Withdraw1->setObjectName(QString::fromUtf8("Withdraw1"));
        Withdraw1->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);

        Withdraw1->setWidget(0, QFormLayout::LabelRole, pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        Withdraw1->setWidget(1, QFormLayout::LabelRole, pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        Withdraw1->setWidget(2, QFormLayout::LabelRole, pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        Withdraw1->setWidget(3, QFormLayout::LabelRole, pushButton_4);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(540, 90, 88, 251));
        Withdraw2 = new QFormLayout(widget1);
        Withdraw2->setObjectName(QString::fromUtf8("Withdraw2"));
        Withdraw2->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(widget1);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        Withdraw2->setWidget(0, QFormLayout::LabelRole, pushButton_5);

        pushButton_6 = new QPushButton(widget1);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        Withdraw2->setWidget(1, QFormLayout::LabelRole, pushButton_6);

        pushButton_7 = new QPushButton(widget1);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        Withdraw2->setWidget(2, QFormLayout::LabelRole, pushButton_7);

        amountOther = new QPushButton(widget1);
        amountOther->setObjectName(QString::fromUtf8("amountOther"));

        Withdraw2->setWidget(3, QFormLayout::LabelRole, amountOther);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(150, 310, 340, 26));
        gridLayout = new QGridLayout(widget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        drawCashButton = new QPushButton(widget2);
        drawCashButton->setObjectName(QString::fromUtf8("drawCashButton"));

        gridLayout->addWidget(drawCashButton, 0, 0, 1, 1);

        transactionsButton = new QPushButton(widget2);
        transactionsButton->setObjectName(QString::fromUtf8("transactionsButton"));

        gridLayout->addWidget(transactionsButton, 0, 1, 1, 1);

        balanceButton = new QPushButton(widget2);
        balanceButton->setObjectName(QString::fromUtf8("balanceButton"));

        gridLayout->addWidget(balanceButton, 0, 2, 1, 1);

        transferButton = new QPushButton(widget2);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));

        gridLayout->addWidget(transferButton, 0, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 663, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MessageLabel->setText(QCoreApplication::translate("MainWindow", "Please insert card to reader", nullptr));
        number4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        number6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        number3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        number0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        number1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        number9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        number2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        number5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        number7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        number8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        confirmButton->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        number6_2->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        number2_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        number5_2->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        number9_2->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        number8_2->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        number7_2->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        number3_2->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        number0_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        confirmButton_2->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        number1_2->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        clearButton_2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        number4_2->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        amountOther->setText(QCoreApplication::translate("MainWindow", "Other", nullptr));
        drawCashButton->setText(QCoreApplication::translate("MainWindow", "Draw Cash", nullptr));
        transactionsButton->setText(QCoreApplication::translate("MainWindow", "Transactions", nullptr));
        balanceButton->setText(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        transferButton->setText(QCoreApplication::translate("MainWindow", "Transfer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
