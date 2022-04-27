/********************************************************************************
** Form generated from reading UI file 'pincode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINCODE_H
#define UI_PINCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PinCode
{
public:
    QLineEdit *lineEditPinCode;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *pushButton_Clear;
    QPushButton *Button0;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *PinCode)
    {
        if (PinCode->objectName().isEmpty())
            PinCode->setObjectName(QString::fromUtf8("PinCode"));
        PinCode->resize(782, 540);
        lineEditPinCode = new QLineEdit(PinCode);
        lineEditPinCode->setObjectName(QString::fromUtf8("lineEditPinCode"));
        lineEditPinCode->setGeometry(QRect(380, 190, 113, 21));
        Button1 = new QPushButton(PinCode);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        Button1->setGeometry(QRect(290, 230, 80, 21));
        Button2 = new QPushButton(PinCode);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        Button2->setGeometry(QRect(400, 230, 80, 21));
        Button3 = new QPushButton(PinCode);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        Button3->setGeometry(QRect(500, 230, 80, 21));
        Button4 = new QPushButton(PinCode);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        Button4->setGeometry(QRect(290, 260, 80, 21));
        Button5 = new QPushButton(PinCode);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        Button5->setGeometry(QRect(400, 260, 80, 21));
        Button6 = new QPushButton(PinCode);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        Button6->setGeometry(QRect(500, 260, 80, 21));
        Button7 = new QPushButton(PinCode);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        Button7->setGeometry(QRect(290, 290, 80, 21));
        Button8 = new QPushButton(PinCode);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        Button8->setGeometry(QRect(400, 290, 80, 21));
        Button9 = new QPushButton(PinCode);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        Button9->setGeometry(QRect(500, 290, 80, 21));
        pushButton_Clear = new QPushButton(PinCode);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(290, 320, 80, 21));
        Button0 = new QPushButton(PinCode);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        Button0->setGeometry(QRect(400, 320, 80, 21));
        pushButton_Cancel = new QPushButton(PinCode);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(500, 320, 80, 21));

        retranslateUi(PinCode);

        QMetaObject::connectSlotsByName(PinCode);
    } // setupUi

    void retranslateUi(QDialog *PinCode)
    {
        PinCode->setWindowTitle(QCoreApplication::translate("PinCode", "Dialog", nullptr));
        Button1->setText(QCoreApplication::translate("PinCode", "1", nullptr));
        Button2->setText(QCoreApplication::translate("PinCode", "2", nullptr));
        Button3->setText(QCoreApplication::translate("PinCode", "3", nullptr));
        Button4->setText(QCoreApplication::translate("PinCode", "4", nullptr));
        Button5->setText(QCoreApplication::translate("PinCode", "5", nullptr));
        Button6->setText(QCoreApplication::translate("PinCode", "6", nullptr));
        Button7->setText(QCoreApplication::translate("PinCode", "7", nullptr));
        Button8->setText(QCoreApplication::translate("PinCode", "8", nullptr));
        Button9->setText(QCoreApplication::translate("PinCode", "9", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("PinCode", "Clear", nullptr));
        Button0->setText(QCoreApplication::translate("PinCode", "0", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("PinCode", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PinCode: public Ui_PinCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINCODE_H
