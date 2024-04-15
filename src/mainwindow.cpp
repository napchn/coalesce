#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "common.h"

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
    //setAttribute(Qt::WA_TranslucentBackground);

    CREATE_CENTRAL_WIDGET_WITH_LAYOUT

    QWidget *bg = new QWidget(this);
    bg->setObjectName("background");
    bg->setStyleSheet("background-color: #ffb399");
    layout->addWidget(bg);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    if (centralWidget() && layout())
    {
        layout()->setGeometry(centralWidget()->rect());
    }
}
