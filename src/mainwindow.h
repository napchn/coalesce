#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelesswindow.h"

#include "winctrltype.h"

class TopBar;

class MainWindow : public FramelessWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    TopBar *topbar;

    void RenderUI();
    void EventBinding();

private slots:
    void SlotWinCtrl(WinCtrlType type);
};

#endif // MAINWINDOW_H
