#pragma once
#include <QNetworkAccessManager>
#include <QNetworkReply>


class DownloadObject : public QObject
{
	Q_OBJECT
private:
	QNetworkAccessManager* networkManager;
	QNetworkReply* networkRely;
public:
	DownloadObject(QString url);
	~DownloadObject();
};

