#include "AscentMainWidget.h"

AscentMainWidget::AscentMainWidget(QWidget *parent)
	: QWidget(parent)
{
	bottomBar = new QLabel(this);
	stackedWidget = new QStackedWidget(this);
	mainLayout = new QVBoxLayout(this);
	bottomBarLayout = new QHBoxLayout(this);
	homeBtn = new AscentButton(this, 60, 50, 80, 50);
	downloadBtn = new AscentButton(this, 60, 50, 80, 50);
	settingBtn = new AscentButton(this, 60, 50, 80, 50);
	homeBtn->setObjectName("BottomBarBatton");
	downloadBtn->setObjectName("BottomBarBatton");
	settingBtn->setObjectName("BottomBarBatton");
	homeBtn->setIcon(QIcon(":/ico/ico/home.svg"));
	downloadBtn->setIcon(QIcon(":/ico/ico/download.svg"));
	settingBtn->setIcon(QIcon(":/ico/ico/setting.svg"));
	homeBtn->setIconSize(QSize(40, 40));
	downloadBtn->setIconSize(QSize(40, 40));
	settingBtn->setIconSize(QSize(40, 40));

	bottomBar->setObjectName("BottomBar");
	bottomBarLayout->addWidget(homeBtn);
	bottomBarLayout->addWidget(downloadBtn);
	bottomBarLayout->addWidget(settingBtn);
	bottomBarLayout->addStretch();
	bottomBarLayout->setContentsMargins(15, 0, 0, 0);
	bottomBarLayout->setSpacing(10);
	bottomBar->setLayout(bottomBarLayout);
	mainLayout->addWidget(stackedWidget,8);
	mainLayout->addWidget(bottomBar,1);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(mainLayout);

}

AscentMainWidget::~AscentMainWidget()
{
}
