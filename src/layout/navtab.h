#ifndef CMPNT_NAVTAB_H
#define CMPNT_NAVTAB_H

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

#endif // CMPNT_NAVTAB_H
