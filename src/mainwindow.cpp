#include <QHBoxLayout>
#include <QVBoxLayout>

#include "common.h"

#include "navtab.h"
#include "ctrltab.h"
#include "topbar.h"
#include "windowctrl.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : FramelessWindow(parent)
{
    RenderUI();
    EventBinding();
}

MainWindow::~MainWindow() {}

void MainWindow::RenderUI()
{
    setWindowTitle(QStringLiteral("%1").arg(APP_NAME));
    setWindowIcon(QIcon(APP_ICON));

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
