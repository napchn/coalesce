#include "iconbtn.h"

IconBtn::IconBtn(const QString &filename, QWidget *parent)
    : QPushButton(parent)
{
    RenderUI(filename);
}

IconBtn::~IconBtn() {}

void IconBtn::SetIcon(const QString &filename)
{
    setIcon(QIcon(filename));
}

void IconBtn::RenderUI(const QString &filename)
{
    setIcon(QIcon(filename));
}
