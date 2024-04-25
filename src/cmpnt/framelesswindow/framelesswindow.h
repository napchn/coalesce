#ifndef CMN_FRAMELESS_WINDOW_H
#define CMN_FRAMELESS_WINDOW_H

#include <QMainWindow>

class FramelessWindow : public QMainWindow
{
    Q_OBJECT

public:
    FramelessWindow(QWidget *parent = nullptr);
    ~FramelessWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool is_dragging;
    QPoint drag_pos;
    //QPoint last_mouse_pos;

    void RenderUI();
};

#endif // CMN_FRAMELESS_WINDOW_H
