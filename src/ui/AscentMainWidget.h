#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStackedWidget>

#include "AscentButton.h"

class AscentMainWidget : public QWidget
{
	Q_OBJECT

private:
	QLabel* bottomBar;
	QStackedWidget* stackedWidget;
	QVBoxLayout* mainLayout;
	QHBoxLayout* bottomBarLayout;

	AscentButton *homeBtn, *downloadBtn, *settingBtn;
public:
	AscentMainWidget(QWidget *parent);
	~AscentMainWidget();
};
