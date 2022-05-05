#include "mainwindow.h"
#include "tilakone.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    class MainWindow w;
    Tilakone* oTilakone = new Tilakone(&w);

    //First invocation of runStateMachine
    oTilakone->runStateMachine(Tilakone::MainWindow, Tilakone::SMStart);

    return a.exec();
}
