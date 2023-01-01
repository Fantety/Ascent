#include "AscentButton.h"

void AscentButton::enterEvent(QEnterEvent*)
{
    this->setCursor(Qt::PointingHandCursor);
    if (this->isClicked == SELECT) return;
    inAni->start();
}

void AscentButton::leaveEvent(QEvent*)
{
    this->setCursor(Qt::ArrowCursor);
    if (this->isClicked == SELECT) return;
    outAni->start();
}

AscentButton::AscentButton(QWidget* parent, int ogWidth, int ogHeight, int width, int height)
	: QPushButton(parent)
{
    this->setObjectName("AscentButton");
    this->setFixedSize(ogWidth, ogHeight);
    inAni = new QPropertyAnimation(this, "minimumSize");
    inAni->setDuration(300);
    inAni->setKeyValueAt(0, QSize(ogWidth, ogHeight));
    inAni->setKeyValueAt(1, QSize(width, height));
    inAni->setEasingCurve(QEasingCurve::InOutQuad);

    outAni = new QPropertyAnimation(this, "minimumSize");
    outAni->setDuration(300);
    outAni->setKeyValueAt(0, QSize(width, height));
    outAni->setKeyValueAt(1, QSize(ogWidth, ogHeight));
    outAni->setEasingCurve(QEasingCurve::InOutQuad);
}

AscentButton::~AscentButton()
{
}

void AscentButton::Reduction()
{
    outAni->start();
}

void AscentButton::Change()
{
    inAni->start();
}

void AscentButton::SetStatus(bool status)
{
    this->isClicked = status;
}
