#include "AscentTitleBar.h"

AscentTitleBar::AscentTitleBar(QWidget *parent)
	: QLabel(parent),parent(parent)
{
	int fontId = QFontDatabase::addApplicationFont(":/font/font/EDIX.ttf");
	QStringList fontIDs = QFontDatabase::applicationFontFamilies(fontId);
	QFont font(fontIDs.first(), 24, 0);
	setObjectName("TitleBar");
	setFixedSize(QSize(1024, 60));
	closeBtn = new AscentButton(this, 50, 50, 70, 50);
	minBtn = new AscentButton(this, 50, 50, 70, 50);
	layout = new QHBoxLayout(this);
	ascentText = new QLabel(this);
	ascentText->setText("  ASCENT");
	ascentText->setFont(font);
	ascentText->setObjectName("AscentText");
	connect(closeBtn, SIGNAL(clicked()), parent, SLOT(close()));
	connect(minBtn, SIGNAL(clicked()), parent, SLOT(showMinimized()));

	closeBtn->setObjectName("TitleButton");
	minBtn->setObjectName("TitleButton");

	closeBtn->setIcon(QIcon(":/ico/ico/close.svg"));
	minBtn->setIcon(QIcon(":/ico/ico/min.svg"));
	closeBtn->setIconSize(QSize(40, 40));
	minBtn->setIconSize(QSize(40, 40));
	layout->addWidget(ascentText);
	layout->addStretch();
	layout->addWidget(minBtn);
	layout->addWidget(closeBtn);
	layout->setSpacing(10);
	layout->setContentsMargins(0, 0, 30, 0);
	this->setLayout(layout);

}

AscentTitleBar::~AscentTitleBar()
{
}

void AscentTitleBar::mousePressEvent(QMouseEvent* event)
{
	this->currentWindowPos = this->parent->pos();
	this->currentMousePos = event->globalPos();
	this->relativePos = currentMousePos - currentWindowPos;
}

void AscentTitleBar::mouseMoveEvent(QMouseEvent* event)
{
	parent->move(event->globalPos() - relativePos);
}
