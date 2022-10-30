#ifndef JSONPARSE_H
#define JSONPARSE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

#include "common/common.h"
#include "domain/VersionDomain.h"


class JsonParse
{
public:
    JsonParse();

    QVector<VersionDomain> parseToVersionDomain(QString json);
};

#endif // JSONPARSE_H
