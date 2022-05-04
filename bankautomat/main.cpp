#include "mainwindow.h"
#include "tilakone.h"

#include <QApplication>

//TODO: test if main could control Tilakone as each loop would invoke runStateMachine
Tilakone::state n = Tilakone::MainWindow;
Tilakone::event m = Tilakone::SMStart;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    class MainWindow w;
    Tilakone* oTilakone = new Tilakone(&w);

    //First invocation of runStateMachine
    oTilakone->runStateMachine(n, m);

    return a.exec();
}
