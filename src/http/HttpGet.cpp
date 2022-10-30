#include "HttpGet.h"

HttpGet::HttpGet(QObject *parent)
    : QObject{parent}
{
}

void HttpGet::get(QString url)
{
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getFinished(QNetworkReply*)));
    manager->get(request);
}

void HttpGet::getFinished(QNetworkReply *relay)
{
    emit sendResult(relay->readAll().data());
    disconnect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getFinished(QNetworkReply*)));
    manager->deleteLater();
    this->deleteLater();
}
