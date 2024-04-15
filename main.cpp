#include <QApplication>
#include <QScreen>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QScreen *primary_screen = QApplication::primaryScreen();
    w.resize(primary_screen->size().width() * 2 / 3, primary_screen->size().height() * 3 / 4);
    w.show();

    return a.exec();
}
