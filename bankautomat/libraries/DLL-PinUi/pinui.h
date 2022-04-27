#ifndef PINUI_H
#define PINUI_H

#include <QDialog>

namespace Ui {
class PinUi;
}

class PinUi : public QDialog
{
    Q_OBJECT

public:
    explicit PinUi(QWidget *parent = nullptr);
    ~PinUi();
    const QString &getPinCode() const;
    void setPinCode(const QString &newPinCode);

signals:
void toExePinCodeEntered(QString pincode);

void toExeCancelPinCode();

void toExeButtonPressed();

public slots:
    void reset();


private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_Clear_clicked();

    void digit_pressed();


private:
    Ui::PinUi *ui;
    QString pinCode;
    void InsertNumber (char number);
};

#endif // PINUI_H
