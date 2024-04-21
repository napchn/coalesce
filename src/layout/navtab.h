#ifndef LAYOUT_NAVTAB_H
#define LAYOUT_NAVTAB_H

#include <QWidget>

class NavTab : public QWidget
{
    Q_OBJECT

public:
    NavTab(QWidget *parent);
    ~NavTab();

private:
    void RenderUI();
};

#endif // LAYOUT_NAVTAB_H
