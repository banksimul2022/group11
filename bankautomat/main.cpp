#include "mainwindow.h"
#include "tilakone.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;               //This will be created in Tilakone
    w.show();                   //This will be shown by Tilakone
    return a.exec();
}
