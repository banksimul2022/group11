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
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(531, 406);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MessageLabel = new QLabel(centralwidget);
        MessageLabel->setObjectName(QString::fromUtf8("MessageLabel"));
        MessageLabel->setGeometry(QRect(190, 20, 141, 51));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 80, 254, 161));
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

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(140, 280, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 531, 21));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "Card 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
