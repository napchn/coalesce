#ifndef API_NATIVE_WIN_EVENT_H
#define API_NATIVE_WIN_EVENT_H

#include <QAbstractNativeEventFilter>

#include "qwindowdefs_win.h"

class WinEvent : public QAbstractNativeEventFilter
{
public:
    WinEvent();
    ~WinEvent();
    bool nativeEventFilter(const QByteArray &eventType, void *message, qintptr *result) override;

private:
    bool HandleNCCalcSize(MSG *msg, qintptr *result);
    bool HandleActivate(MSG *msg, qintptr *result);
    bool HandleNCHitTest(MSG *msg, qintptr *result);
};

#endif // API_NATIVE_WIN_EVENT_H
