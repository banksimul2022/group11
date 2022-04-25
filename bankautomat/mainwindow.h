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
    void pinUiVisibility(bool);
    void setMessageLabel(QString);

public slots:
    void numberClickHandler();
    void on_pushButton_clicked();

signals:
    void testCardInserted(QByteArray);

private slots:
    void on_number1_clicked();

    void on_number2_clicked();

    void on_number3_clicked();

    void on_number4_clicked();

    void on_number5_clicked();

    void on_number6_clicked();

    void on_number7_clicked();

    void on_number8_clicked();

    void on_number9_clicked();

    void on_number0_clicked();


private:
    Ui::MainWindow *ui;
    void clickHandler();

protected:
    QString pinCheck;

};
#endif // MAINWINDOW_H
