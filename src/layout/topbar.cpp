#include <QMainWindow>
#include <QHBoxLayout>
#include <QPainter>

#include "windowctrl.h"

#include "topbar.h"

TopBar::TopBar(QWidget *parent)
    : QWidget(parent)
{
    RenderUI();
    EventBinding();
}

TopBar::~TopBar() {}

void TopBar::RenderUI()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    this->setLayout(layout);

    layout->addStretch();

    winctrl = new WindowCtrl(this);
    layout->addWidget(winctrl);

    layout->setContentsMargins(0, 0, 0, 0);
}

void TopBar::EventBinding()
{
    connect(winctrl, &WindowCtrl::SigWinCtrlBtnClicked, this, &TopBar::SigWinCtrl);
}

void TopBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.fillRect(rect(), QColor("#fce38a"));
}
