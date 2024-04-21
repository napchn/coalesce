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
    this->setLayout(new QVBoxLayout(this));
    CREATE_WIDGET_WITH_LAYOUT(this, navtab, "nav-tab", QVBoxLayout)
    this->layout()->addWidget(navtab);
    this->layout()->setContentsMargins(0, 0, 0, 0);

    QPushButton *btn1 = new QPushButton("btn1");
    QPushButton *btn2 = new QPushButton("btn2");
    navtab_layout->addWidget(btn1);
    navtab_layout->addWidget(btn2);
    navtab_layout->addStretch();

    // For development
    navtab->setStyleSheet("background-color: #eaffd0;");
}
