#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

#include "common.h"

#include "navtab.h"
#include "ctrltab.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    RenderUI();
}

MainWindow::~MainWindow() {}

void MainWindow::RenderUI()
{
    setWindowTitle(QStringLiteral("%1").arg(APP_NAME));
    setWindowIcon(QIcon(APP_ICON));
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    CREATE_WIDGET_WITH_LAYOUT(this, central_widget, "central-widget", QHBoxLayout)
    this->setCentralWidget(central_widget);

    CREATE_WIDGET_WITH_LAYOUT(central_widget, left_area, "left-area", QVBoxLayout)
    left_area->setFixedWidth(60);
    NavTab *navtab = new NavTab(central_widget);
    left_area_layout->addWidget(navtab);

    CREATE_WIDGET_WITH_LAYOUT(central_widget, right_area, "right-area", QVBoxLayout)

    left_area->setStyleSheet("background-color: #95e1d3");
    right_area->setStyleSheet("background-color: #ffb399");

    central_widget_layout->addWidget(left_area);
    central_widget_layout->addWidget(right_area);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    if (centralWidget() && layout()) {
        layout()->setGeometry(centralWidget()->rect());
    }
}
