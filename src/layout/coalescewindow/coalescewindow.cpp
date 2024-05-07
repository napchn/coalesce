#include <QMouseEvent>
#include <QHBoxLayout>

#include "common.h"

#include "windowctrl.h"
#include "iconbtn.h"

#include "coalescewindow.h"

CoalesceWindow::CoalesceWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitMember();
    RenderUI();
}

CoalesceWindow::~CoalesceWindow() {}

void CoalesceWindow::InitMember()
{
    left_area_layout = nullptr;
    titlebar = nullptr;
    is_dragging = false;
}

void CoalesceWindow::RenderUI()
{
    setAttribute(Qt::WA_TranslucentBackground);

#ifdef Q_OS_LINUX || Q_OS_MAC
    setWindowFlags(Qt::FramelessWindowHint);
#endif

    CREATE_WIDGET_WITH_LAYOUT(this, central_widget, "central-widget", QHBoxLayout)
    INSTANTIATED_LAYOUT(central_widget, left_area, "left-area", QVBoxLayout)
    CREATE_WIDGET_WITH_LAYOUT(central_widget, right_area, "right-area", QVBoxLayout)
    INSTANTIATED_WIDGET(right_area, titlebar, "titlebar", QHBoxLayout)
    CREATE_WIDGET_WITH_LAYOUT(right_area, client_area, "client-area", QHBoxLayout)
    INSTANTIATED_LAYOUT(central_widget, topbar, "topbar", QHBoxLayout)

    central_widget_layout->addWidget(left_area);
    central_widget_layout->addWidget(right_area);
    right_area_layout->addWidget(titlebar);
    right_area_layout->addWidget(client_area);
    titlebar_layout->addWidget(topbar);

    setCentralWidget(central_widget);
    left_area_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    titlebar_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    win_ctrl = new WindowCtrl(this);
    win_ctrl->setFixedSize(TITLEBAR_WINCTRL_WIDTH, TITLEBAR_HEIGHT);
    titlebar_layout->addWidget(win_ctrl);

    // For development
    left_area->setStyleSheet("background-color: #ffb399");
    right_area->setStyleSheet("background-color: #ffb399");
    titlebar->setStyleSheet("background-color: #fce38a");
    client_area->setStyleSheet("background-color: #dcedc2");
    topbar->setStyleSheet("background-color: #c3bef0");
}

void CoalesceWindow::AddWidgetToLeft(QWidget *widget, int stretch)
{
    if (left_area_layout == nullptr) {
        return;
    }
    left_area_layout->addWidget(widget, stretch);
}

void CoalesceWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        is_dragging = true;
        drag_pos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void CoalesceWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (is_dragging) {
        move(event->globalPos() - drag_pos);
        event->accept();
    }
}

void CoalesceWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        is_dragging = false;
        event->accept();
    }
}
