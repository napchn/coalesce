#ifndef LAYOUT_WINCTRL_WINDOW_CTRL_H
#define LAYOUT_WINCTRL_WINDOW_CTRL_H

#include <QWidget>

class IconBtn;

class WindowCtrl : public QWidget
{
    Q_OBJECT

public:
    WindowCtrl(QWidget *parent);
    ~WindowCtrl();
    IconBtn *MaximizeBtn();

private:
    IconBtn *minimize_btn;
    IconBtn *maximize_btn;
    IconBtn *close_btn;
    bool isNormalWindow;

    void InitMember();
    void RenderUI();
    void EventBinding(QWidget *parent);
};

#endif // LAYOUT_WINCTRL_WINDOW_CTRL_H
