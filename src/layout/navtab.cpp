#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>

#include "common.h"

#include "navtab.h"

NavTab::NavTab(QWidget *parent)
    : QWidget(parent)
{
    RenderUI();
}

NavTab::~NavTab() {}

void NavTab::RenderUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->setLayout(layout);

    QPushButton *btn1 = new QPushButton("btn1");
    QPushButton *btn2 = new QPushButton("btn2");
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addStretch();
    layout->setContentsMargins(0, 0, 0, 0);
}

void NavTab::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.fillRect(rect(), QColor("#eaffd0"));
}
