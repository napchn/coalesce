#ifndef LAYOUT_WINCTRL_WINDOW_CTRL_H
#define LAYOUT_WINCTRL_WINDOW_CTRL_H

#include <QWidget>

#include "winctrltype.h"

class IconBtn;

class WindowCtrl : public QWidget
{
    Q_OBJECT

public:
    WindowCtrl(QWidget *parent);
    ~WindowCtrl();

signals:
    void SigWinCtrlBtnClicked(WinCtrlType type);

private:
    IconBtn *minimize_btn;
    IconBtn *maximize_btn;
    IconBtn *close_btn;
    bool isNormalWindow;

    void InitMember();
    void RenderUI();
    void EventBinding();
};

#endif // LAYOUT_WINCTRL_WINDOW_CTRL_H
