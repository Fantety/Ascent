#ifndef ASSETDOMAIN_H
#define ASSETDOMAIN_H

#include "../common/common.h"

class AssetDomain
{
    SET_DOMAIN_PARAMATER(QString, id, Id);
    SET_DOMAIN_PARAMATER(QString, sha1, Sha1);
    SET_DOMAIN_PARAMATER(uint, size, Size);
    SET_DOMAIN_PARAMATER(uint, totalSize, TotalSize);
    SET_DOMAIN_PARAMATER(QString, url, Url);

};

#endif // ASSETDOMAIN_H
