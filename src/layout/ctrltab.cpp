#include <QVBoxLayout>
#include <QPushButton>

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
    this->setLayout(new QVBoxLayout(this));
    CREATE_WIDGET_WITH_LAYOUT(this, ctrltab, "ctrl-tab", QVBoxLayout)
    this->layout()->addWidget(ctrltab);
    this->layout()->setContentsMargins(0, 0, 0, 0);

    QPushButton *btn3 = new QPushButton("btn3");
    QPushButton *btn4 = new QPushButton("btn4");
    ctrltab_layout->addStretch();
    ctrltab_layout->addWidget(btn3);
    ctrltab_layout->addWidget(btn4);

    // For development
    ctrltab->setStyleSheet("background-color: #95e1d3;");
}
