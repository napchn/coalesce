#include <QHBoxLayout>

#include "common.h"

#include "iconbtn.h"

#include "windowctrl.h"

WindowCtrl::WindowCtrl(QWidget *parent)
    : QWidget(parent)
{
    InitMember();
    RenderUI();
    EventBinding();
}

WindowCtrl::~WindowCtrl() {}

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

void WindowCtrl::EventBinding()
{
    connect(minimize_btn, &QPushButton::clicked, this, [this]() {
        emit SigWinCtrlBtnClicked(WinCtrlType::Minimize);
    });
    connect(maximize_btn, &QPushButton::clicked, this, [this]() {
        if (isNormalWindow) {
            emit SigWinCtrlBtnClicked(WinCtrlType::Maximize);
            isNormalWindow = false;
            maximize_btn->SetIcon(WINDOW_NORMALIZE_ICON);
        } else {
            emit SigWinCtrlBtnClicked(WinCtrlType::Normal);
            maximize_btn->SetIcon(WINDOW_MAXIMIZE_ICON);
            isNormalWindow = true;
        }
    });
    connect(close_btn, &QPushButton::clicked, this, [this]() {
        emit SigWinCtrlBtnClicked(WinCtrlType::Close);
    });
}
