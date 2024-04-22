#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "winctrltype.h"

class TopBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    TopBar *topbar;

    void RenderUI();
    void EventBinding();

private slots:
    void SlotWinCtrl(WinCtrlType type);
};

#endif // MAINWINDOW_H
