#include "mainwindow.h"
#include "tilakone.h"

#include <QApplication>


Tilakone::state n = Tilakone::MainWindow;
Tilakone::event m = Tilakone::SMStart;
QString insertCard = "Please insert card to reader!";
QString insertPin = "Please insert pin!";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    class MainWindow w;
    Tilakone* oTilakone = new Tilakone(&w);

    //First invocation of runStateMachine
    oTilakone->runStateMachine(n, m);

    return a.exec();
}
