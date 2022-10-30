#include "JsonParse.h"

JsonParse::JsonParse()
{

}

QVector<VersionDomain> JsonParse::parseToVersionDomain(QString json)
{
    QVector<VersionDomain> res;
    if(json.isEmpty())
        return res;
    QJsonParseError jEro;
    QJsonDocument jDoc = QJsonDocument::fromJson(json.toUtf8(), &jEro);
    if (jEro.error == QJsonParseError::NoError && jDoc.isObject())
    {
        QJsonObject jObj = jDoc.object();
        QJsonArray jAry = jObj.value("versions").toArray();
        foreach(auto item, jAry)
        {
            VersionDomain domain;
            domain.setId(item.toObject().value("id").toString());
            domain.setType(item.toObject().value("type").toString());
            domain.setUrl(item.toObject().value("url").toString());
            domain.setTime(item.toObject().value("time").toString());
            domain.setReleaseTime(item.toObject().value("releaseTime").toString());
            res.push_back(domain);
        }
        return res;
    }
    else
    {
        qDebug() << jEro.errorString();
        return res;
    }

}
