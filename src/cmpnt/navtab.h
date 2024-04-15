#pragma once

#include <QObject>

class NavTab  : public QObject
{
	Q_OBJECT

public:
	NavTab(QWidget *parent);
	~NavTab();
};
