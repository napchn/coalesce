#include <QMouseEvent>

#include "framelesswindow.h"

FramelessWindow::FramelessWindow(QWidget *parent)
    : QMainWindow(parent)
{
    RenderUI();

    installEventFilter(this);
}

FramelessWindow::~FramelessWindow() {}

void FramelessWindow::RenderUI()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void FramelessWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        is_dragging = true;
        drag_pos = event->globalPos() - frameGeometry().topLeft();
        //last_mouse_pos = event->pos();
        event->accept();
    }
}

void FramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
    //QSize win_size = size();
    //QPoint win_mouse_pos = event->pos();
    //qint8 edge_margin = 5;
    //bool is_left_side = abs((win_mouse_pos.x() - 0)) < edge_margin;
    //bool is_right_side = abs((win_mouse_pos.x() - win_size.width())) < edge_margin;
    //bool is_top_side = abs((win_mouse_pos.y() - 0)) < edge_margin;
    //bool is_bottom_side = abs((win_mouse_pos.y() - win_size.height())) < edge_margin;

    //if (is_left_side || is_right_side || is_top_side || is_bottom_side) {
    //    QPoint diff = win_mouse_pos - last_mouse_pos;
    //    QRect new_geometry = geometry();

    //    if (is_right_side) {
    //        new_geometry.setWidth(new_geometry.width() + diff.x());
    //    }
    //    if (is_bottom_side) {
    //        new_geometry.setHeight(new_geometry.height() + diff.y());
    //    }
    //    setGeometry(new_geometry.normalized());
    //    event->accept();
    //}
    //last_mouse_pos = win_mouse_pos;

    if (is_dragging) {
        move(event->globalPos() - drag_pos);
        event->accept();
    }
}

void FramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        is_dragging = false;
        event->accept();
    }
}
