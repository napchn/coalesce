#ifndef LAYOUT_CTRL_TAB_H
#define LAYOUT_CTRL_TAB_H

#include <QWidget>

class CtrlTab : public QWidget
{
    Q_OBJECT

public:
    CtrlTab(QWidget *parent);
    ~CtrlTab();

private:
    void RenderUI();
};

#endif // LAYOUT_CTRL_TAB_H
