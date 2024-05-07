#include <QHBoxLayout>
#include <QWindow>
#include <QScreen>

#pragma comment(lib, "dwmapi")
#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <dwmapi.h>
#include <windowsx.h>

#include "common.h"

#include "iconbtn.h"

#include "windowctrl.h"

WindowCtrl::WindowCtrl(QWidget *parent)
    : QWidget(parent)
{
    InitMember();
    RenderUI();
    EventBinding(parent);
}

WindowCtrl::~WindowCtrl() {}

IconBtn *WindowCtrl::MaximizeBtn()
{
    return maximize_btn;
}

void WindowCtrl::InitMember()
{
    minimize_btn = nullptr;
    maximize_btn = nullptr;
    close_btn = nullptr;
    isNormalWindow = true;
}

void WindowCtrl::RenderUI()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    setLayout(layout);

    minimize_btn = new IconBtn(WINDOW_MINIMIZE_ICON, this);
    maximize_btn = new IconBtn(WINDOW_MAXIMIZE_ICON, this);
    close_btn = new IconBtn(WINDOW_CLOSE_ICON, this);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(this->minimize_btn);
    layout->addWidget(this->maximize_btn);
    layout->addWidget(this->close_btn);
}

void WindowCtrl::EventBinding(QWidget *parent)
{
    connect(minimize_btn, &QPushButton::clicked, parent, &QWidget::showMinimized);
    connect(maximize_btn, &QPushButton::clicked, parent, [this, parent]() {
        if (isNormalWindow) {
            parent->showMaximized();
            maximize_btn->SetIcon(WINDOW_NORMALIZE_ICON);
            isNormalWindow = false;
        } else {
            parent->showNormal();
            maximize_btn->SetIcon(WINDOW_MAXIMIZE_ICON);
            isNormalWindow = true;
        }
    });
    connect(close_btn, &QPushButton::clicked, parent, &QWidget::close);
}
