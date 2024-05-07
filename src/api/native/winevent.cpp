#pragma comment(lib, "dwmapi")
#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <dwmapi.h>
#include <windowsx.h>

#include "common.h"

#include "winevent.h"

WinEvent::WinEvent() {}

WinEvent::~WinEvent() {}

bool WinEvent::nativeEventFilter(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG *msg = reinterpret_cast<MSG *>(message);

    switch (msg->message) {
    case WM_NCCALCSIZE:
        return HandleNCCalcSize(msg, result);
    case WM_ACTIVATE:
        return HandleActivate(msg, result);
    case WM_NCHITTEST:
        return HandleNCHitTest(msg, result);
    default:
        return false;
    }
}

bool WinEvent::HandleNCCalcSize(MSG *msg, qintptr *result)
{
    *result = 0;
    return true;
}

bool WinEvent::HandleActivate(MSG *msg, qintptr *result)
{
    MARGINS margins = {1, 1, 1, 1};
    HRESULT hr = S_OK;
    hr = DwmExtendFrameIntoClientArea(msg->hwnd, &margins);
    *result = hr;
    return true;
}

bool WinEvent::HandleNCHitTest(MSG *msg, qintptr *result)
{
#define TOPEXTENDWIDTH    5
#define BOTTOMEXTENDWIDTH 5
#define LEFTEXTENDWIDTH   5
#define RIGHTEXTENDWIDTH  5
#define STANDARD_DPI      96.0 // 96 DPI is the standard DPI for a display

    POINT mouse = {GET_X_LPARAM(msg->lParam), GET_Y_LPARAM(msg->lParam)};

    RECT winsize;
    GetWindowRect(msg->hwnd, &winsize);

    RECT lprect = {0};
    AdjustWindowRectEx(&lprect, WS_OVERLAPPEDWINDOW & ~WS_CAPTION, FALSE, NULL);

    HDC hdc = GetDC(NULL);
    float dev_pix_ratio = GetDeviceCaps(hdc, LOGPIXELSX) / STANDARD_DPI;
    ReleaseDC(NULL, hdc);

    USHORT row = 1;
    USHORT col = 1;
    bool on_resize_border = false;
    bool resizable = false;

    if (mouse.y >= winsize.top && mouse.y < winsize.top + TOPEXTENDWIDTH) {
        on_resize_border = (mouse.y < (winsize.top - lprect.top));
        row = 0;
        resizable = true;
    } else if (mouse.y < winsize.bottom && mouse.y >= winsize.bottom - BOTTOMEXTENDWIDTH) {
        row = 2;
        resizable = true;
    }
    if (mouse.x >= winsize.left && mouse.x < winsize.left + LEFTEXTENDWIDTH) {
        col = 0;
        resizable = true;
    } else if (mouse.x < winsize.right && mouse.x >= winsize.right - RIGHTEXTENDWIDTH) {
        col = 2;
        resizable = true;
    }
    LRESULT hitTests[3][3] = {
        {HTTOPLEFT, on_resize_border ? HTTOP : HTCAPTION, HTTOPRIGHT},
        {HTLEFT, HTNOWHERE, HTRIGHT},
        {HTBOTTOMLEFT, HTBOTTOM, HTBOTTOMRIGHT},
    };
    if (resizable == true) {
        *result = hitTests[row][col];
        return true;
    }

#ifdef WIN_NATIVE_DRAG_MOVE_TEST
    if (mouse.x >= winsize.left + (SIDEBAR_WIDTH * dev_pix_ratio)
        && mouse.x <= winsize.right - (TITLEBAR_WINCTRL_WIDTH * dev_pix_ratio)
        && mouse.y >= winsize.top + TOPEXTENDWIDTH
        && mouse.y <= winsize.top + TITLEBAR_HEIGHT * dev_pix_ratio) {
        *result = HTCAPTION;
        return true;
    }
#endif // WIN_NATIVE_DRAG_MOVE_TEST

    return false;
}
