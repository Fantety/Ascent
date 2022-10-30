#ifndef HTTPGET_H
#define HTTPGET_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class HttpGet : public QObject
{
    Q_OBJECT
    QNetworkAccessManager* manager;
public:
    HttpGet(QObject *parent = nullptr);


    void get(QString url);

private slots:
    void getFinished(QNetworkReply* relay);
signals:
    void sendResult(QString res);
};

#endif // HTTPGET_H
