#ifndef ASSETOBJECTDOMAIN_H
#define ASSETOBJECTDOMAIN_H

#include "../common/common.h"

class AssetObjectDomain
{
    SET_DOMAIN_PARAMATER(QString, assetName, AssetName);
    SET_DOMAIN_PARAMATER(QString, hash, Hash);
    SET_DOMAIN_PARAMATER(uint, size, Size);
    SET_DOMAIN_PARAMATER(QString, url, Url);
};

#endif // ASSETOBJECTDOMAIN_H
