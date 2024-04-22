#ifndef LAYOUT_TOP_BAR_H
#define LAYOUT_TOP_BAR_H

#include <QWidget>

#include "winctrltype.h"

class WindowCtrl;

class TopBar : public QWidget
{
    Q_OBJECT

public:
    TopBar(QWidget *parent);
    ~TopBar();

signals:
    void SigWinCtrl(WinCtrlType type);

private:
    void paintEvent(QPaintEvent *event);

private:
    WindowCtrl *winctrl;

    void RenderUI();
    void EventBinding();
};

#endif // LAYOUT_TOP_BAR_H
