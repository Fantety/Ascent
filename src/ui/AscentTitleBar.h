#pragma once

#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QLabel>
#include <QFontDatabase>

#include "AscentButton.h"

class AscentTitleBar : public QLabel
{
	Q_OBJECT

private:
	QHBoxLayout* layout;
	AscentButton* closeBtn;
	AscentButton* minBtn;
	QLabel* ascentText;
	QPoint currentWindowPos, currentMousePos, relativePos;

	QWidget* parent;
public:
	AscentTitleBar(QWidget *parent);
	~AscentTitleBar();

private:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
};
