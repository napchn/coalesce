#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>

#include "common.h"

#include "ctrltab.h"

CtrlTab::CtrlTab(QWidget *parent)
    : QWidget(parent)
{
    RenderUI();
}

CtrlTab::~CtrlTab() {}

void CtrlTab::RenderUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->setLayout(layout);

    QPushButton *btn3 = new QPushButton("btn3");
    QPushButton *btn4 = new QPushButton("btn4");
    layout->addStretch();
    layout->addWidget(btn3);
    layout->addWidget(btn4);
    layout->setContentsMargins(0, 0, 0, 0);
}

void CtrlTab::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.fillRect(rect(), QColor("#95e1d3"));
}
