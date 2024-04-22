#ifndef CMPNT_ICONBTN_ICON_BTN_H
#define CMPNT_ICONBTN_ICON_BTN_H

#include <QPushButton>

class IconBtn : public QPushButton
{
    Q_OBJECT

public:
    explicit IconBtn(const QString &filename, QWidget *parent);
    ~IconBtn();
    void SetIcon(const QString &filename);

private:
    void RenderUI(const QString &filename);
};

#endif // CMPNT_ICONBTN_ICON_BTN_H
