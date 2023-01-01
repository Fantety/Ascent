#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(QSize(1024, 720));
    mainLayout = new QVBoxLayout(this);
    masterLayout = new QVBoxLayout(this);
    mainWidget = new QLabel(this);
    mainLayout->addWidget(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    masterLayout->setContentsMargins(0, 0, 0, 0);
    mainWidget->setObjectName("MainWidget");
    mainWidget->setLayout(masterLayout);
    this->setLayout(mainLayout);
    loadQss(":/qss/theme/default.qss");

    aTitleBar = new AscentTitleBar(this);
    aMainWidget = new AscentMainWidget(this);

    masterLayout->addWidget(aTitleBar, 1);
    masterLayout->addWidget(aMainWidget, 5);


}

Widget::~Widget()
{
}

bool Widget::loadQss(QString qssPath)
{
    QFile qssFile(qssPath);
    if (qssFile.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
        return true;
    }
    else {
        return false;
    }
}


