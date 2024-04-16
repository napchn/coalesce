#ifndef CMPNT_CTRL_TAB_H
#define CMPNT_CTRL_TAB_H

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

#endif // CMPNT_CTRL_TAB_H
