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

QVector<LibraryDomain> JsonParse::parseToLibraryDomain(QString json)
{
    QVector<LibraryDomain> res;
    if(json.isEmpty())
        return res;
    QJsonParseError jEro;
    QJsonDocument jDoc = QJsonDocument::fromJson(json.toUtf8(), &jEro);
    if (jEro.error == QJsonParseError::NoError && jDoc.isObject())
    {
        QJsonObject jObj = jDoc.object();
        QJsonArray jAry = jObj.value("libraries").toArray();
        foreach(auto item, jAry)
        {
            LibraryDomain domain;
            domain.setPath(item.toObject().value("download").toObject().value("artifact").toObject().value("path").toString());
            domain.setSha1(item.toObject().value("download").toObject().value("artifact").toObject().value("sha1").toString());
            domain.setSize(item.toObject().value("download").toObject().value("artifact").toObject().value("size").toInt());
            domain.setUrl(item.toObject().value("download").toObject().value("artifact").toObject().value("url").toString());
            if(item.toObject().contains("rules")){
                if(item.toObject().value("rules").toArray().first().toObject().value("os").toObject().value("name").toString() == "linux"){
                    domain.setOs(LINUX);
                }else{
                    domain.setOs(OSX);
                }
            }else{
                domain.setOs(WIN);
            }
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

QVector<AssetObjectDomain> JsonParse::parseToAssetObjectDomain(QString json)
{
    QVector<AssetObjectDomain> res;
    if(json.isEmpty())
        return res;
    QJsonParseError jEro;
    QJsonDocument jDoc = QJsonDocument::fromJson(json.toUtf8(), &jEro);
    if (jEro.error == QJsonParseError::NoError && jDoc.isObject())
    {
        QJsonObject jObj = jDoc.object().value("objects").toObject();
        QStringList kList = jObj.keys();
        foreach(auto item, kList)
        {
            AssetObjectDomain domain;
            domain.setAssetName(item);
            domain.setHash(jObj.find(item)->toObject().value("hash").toString());
            domain.setSize(jObj.find(item)->toObject().value("size").toInt());
            domain.setUrl("http://resources.download.minecraft.net/"+domain.getHash().left(2)+"/"+domain.getHash());
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

ClientDomain JsonParse::parseToClientDomain(QString json)
{
    ClientDomain res;
    if(json.isEmpty())
        return res;
    QJsonParseError jEro;
    QJsonDocument jDoc = QJsonDocument::fromJson(json.toUtf8(), &jEro);
    if (jEro.error == QJsonParseError::NoError && jDoc.isObject())
    {
        QJsonObject jObj = jDoc.object().value("downloads").toObject().value("client").toObject();
        res.setSha1(jObj.value("sha1").toString());
        res.setUrl(jObj.value("url").toString());
        res.setSize(jObj.value("size").toInt());
        return res;
    }
    else
    {
        qDebug() << jEro.errorString();
        return res;
    }
}

AssetDomain JsonParse::parseToAssetDomain(QString json)
{
    AssetDomain res;
    if (json.isEmpty())
        return res;
    QJsonParseError jEro;
    QJsonDocument jDoc = QJsonDocument::fromJson(json.toUtf8(), &jEro);
    if (jEro.error == QJsonParseError::NoError && jDoc.isObject())
    {
        QJsonObject jObj = jDoc.object().value("assetIndex").toObject();
        res.setId(jObj.value("id").toString());
        res.setSha1(jObj.value("sha1").toString());
        res.setSize(jObj.value("size").toInt());
        res.setTotalSize(jObj.value("totalSize").toInt());
        res.setUrl(jObj.value("url").toString());
        return res;
    }
    else
    {
        qDebug() << jEro.errorString();
        return res;
    }
    return AssetDomain{};
}
