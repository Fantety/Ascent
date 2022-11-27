#ifndef JSONPARSE_H
#define JSONPARSE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

#include "common/common.h"
#include "domain/VersionDomain.h"
#include "domain/LibraryDomain.h"
#include "domain/ClientDomain.h"
#include "domain/AssetDomain.h"
#include "domain/AssetObjectDomain.h"
#include "domain/CommandLineDomain.h"


class JsonParse
{
public:
    JsonParse();

    QVector<VersionDomain> parseToVersionDomain(QString json);
    QVector<LibraryDomain> parseToLibraryDomain(QString json);
    QVector<AssetObjectDomain> parseToAssetObjectDomain(QString json);
    ClientDomain parseToClientDomain(QString json);
    AssetDomain parseToAssetDomain(QString json);
    CommandLineDomain parseToCommandLineDomain(QString json);
};

#endif // JSONPARSE_H
