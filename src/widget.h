#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFile>
#include <QApplication>
#include <QLabel>

#include "AscentTitleBar.h"
#include "AscentMainWidget.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel* mainWidget;
    QVBoxLayout* mainLayout, *masterLayout;

    AscentTitleBar* aTitleBar;
    AscentMainWidget* aMainWidget;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


public:
    bool loadQss(QString qssPath);
};
#endif // WIDGET_H
