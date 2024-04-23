#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "common.h"

#include "navtab.h"
#include "ctrltab.h"
#include "topbar.h"
#include "windowctrl.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    RenderUI();
    EventBinding();
}

MainWindow::~MainWindow() {}

void MainWindow::RenderUI()
{
    setWindowTitle(QStringLiteral("%1").arg(APP_NAME));
    setWindowIcon(QIcon(APP_ICON));
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    CREATE_WIDGET_WITH_LAYOUT(this, central_widget, "central-widget", QHBoxLayout)
    CREATE_WIDGET_WITH_LAYOUT(central_widget, left_area, "left-area", QVBoxLayout)
    CREATE_WIDGET_WITH_LAYOUT(central_widget, right_area, "right-area", QVBoxLayout)
    setCentralWidget(central_widget);
    left_area->setFixedWidth(60);
    central_widget_layout->addWidget(left_area);
    central_widget_layout->addWidget(right_area);

    NavTab *navtab = new NavTab(central_widget);
    CtrlTab *ctrltab = new CtrlTab(central_widget);
    left_area_layout->addWidget(navtab, 2);
    left_area_layout->addWidget(ctrltab, 1);

    topbar = new TopBar(central_widget);
    topbar->setFixedHeight(38);
    right_area_layout->addWidget(topbar);
    right_area_layout->addStretch();

    // For development
    left_area->setStyleSheet("background-color: #ffb399");
    right_area->setStyleSheet("background-color: #ffb399");
}

void MainWindow::EventBinding()
{
    connect(topbar, &TopBar::SigWinCtrl, this, &MainWindow::SlotWinCtrl);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    if (centralWidget() && layout()) {
        layout()->setGeometry(centralWidget()->rect());
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        is_dragging = true;
        drag_position = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (is_dragging) {
        move(event->globalPos() - drag_position);
        event->accept();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        is_dragging = false;
        event->accept();
    }
}

void MainWindow::SlotWinCtrl(WinCtrlType type)
{
    switch (type) {
    case WinCtrlType::Minimize:
        showMinimized();
        break;
    case WinCtrlType::Normal:
        showNormal();
        break;
    case WinCtrlType::Maximize:
        showMaximized();
        break;
    case WinCtrlType::Close:
        close();
        break;
    default:
        break;
    }
}
