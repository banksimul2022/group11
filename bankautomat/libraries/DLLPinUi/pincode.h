#ifndef PINCODE_H
#define PINCODE_H
//engine
#include <QDialog>

namespace Ui {
class PinCode;
}

class PinCode : public QDialog
{
    Q_OBJECT

public:
    explicit PinCode(QWidget *parent = nullptr);
    ~PinCode();
    const QString &getPinCode() const;
    void setPinCode(const QString &newPinCode);

signals:
    void toExePinCodeEntered(QString);

private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_Clear_clicked();

    void digit_pressed();


private:
    Ui::PinCode *ui;
    QString pinCode;
    void InsertNumber();
};

#endif // PINCODE_H
