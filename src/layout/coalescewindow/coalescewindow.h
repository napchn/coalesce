#ifndef CMN_FRAMELESS_WINDOW_H
#define CMN_FRAMELESS_WINDOW_H

#include <QMainWindow>

class QHBoxLayout;
class QVBoxLayout;
class IconBtn;
class WindowCtrl;

class CoalesceWindow : public QMainWindow
{
    Q_OBJECT

public:
    CoalesceWindow(QWidget *parent = nullptr);
    ~CoalesceWindow();
    void AddWidgetToLeft(QWidget *widget, int stretch = 0);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QVBoxLayout *left_area_layout;
    QHBoxLayout *topbar_layout;
    QWidget *titlebar;
    WindowCtrl *win_ctrl;
    bool is_dragging;
    QPoint drag_pos;

    void InitMember();
    void RenderUI();
};

#endif // CMN_FRAMELESS_WINDOW_H
