#include <QApplication>
#include <QScreen>

#include "winevent.h"

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WinEvent win_event;
    a.installNativeEventFilter(&win_event);

    MainWindow w;
    QScreen *primary_screen = QApplication::primaryScreen();
    qint16 screen_w = primary_screen->size().width();
    qint16 screen_h = primary_screen->size().height();
    qint16 window_w = screen_w * 2 / 3;
    qint16 window_h = screen_h * 2 / 3;
    w.setGeometry((screen_w - window_w) / 2, (screen_h - window_h) / 2, window_w, window_h);
    w.show();

    return a.exec();
}
