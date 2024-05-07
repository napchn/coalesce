#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "coalescewindow.h"

class MainWindow : public CoalesceWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void RenderUI();
    void EventBinding();
};

#endif // MAINWINDOW_H
