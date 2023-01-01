#pragma once

#include <QPushButton>
#include <QPropertyAnimation>

#define SELECT true
#define UNSELECT false

class AscentButton : public QPushButton
{
	Q_OBJECT
private:
    bool isClicked = false;

protected:
    void enterEvent(QEnterEvent*) override;
    void leaveEvent(QEvent*) override;

    QPropertyAnimation* inAni;
    QPropertyAnimation* outAni;

public:
	AscentButton(QWidget* parent, int og_width, int og_height, int width, int height);
	~AscentButton();
    void Reduction();
    void Change();
    void SetStatus(bool status);
signals:
    void hover();
    void leave();
};
