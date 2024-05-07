#include <QHBoxLayout>
#include <QVBoxLayout>

#include "common.h"

#include "navtab.h"
#include "ctrltab.h"
#include "windowctrl.h"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : CoalesceWindow(parent)
{
    RenderUI();
    EventBinding();
}

MainWindow::~MainWindow() {}

void MainWindow::RenderUI()
{
    setWindowTitle(QStringLiteral("%1").arg(APP_NAME));
    setWindowIcon(QIcon(APP_ICON));

    NavTab *navtab = new NavTab(this);
    navtab->setFixedWidth(SIDEBAR_WIDTH);
    CtrlTab *ctrltab = new CtrlTab(this);
    ctrltab->setFixedWidth(SIDEBAR_WIDTH);
    AddWidgetToLeft(navtab, 2);
    AddWidgetToLeft(ctrltab, 1);
}

void MainWindow::EventBinding() {}
