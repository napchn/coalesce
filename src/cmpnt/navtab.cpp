#include <QVBoxLayout>
#include <QPushButton>

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
    QPushButton *btn1 = new QPushButton("btn1");
    QPushButton *btn2 = new QPushButton("btn2");
    layout->addWidget(btn1);
    layout->addWidget(btn2);

    layout->addStretch();
}
