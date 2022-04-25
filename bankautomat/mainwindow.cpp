#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pincodedll.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    pinui = new PinCodeDLL();
    pinui->pinui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

