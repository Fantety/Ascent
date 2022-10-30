#ifndef VERSIONDOMAIN_H
#define VERSIONDOMAIN_H

#include "../common/common.h"

class VersionDomain
{
    SET_DOMAIN_PARAMATER(QString, id, Id);
    SET_DOMAIN_PARAMATER(QString, type, Type);
    SET_DOMAIN_PARAMATER(QString, url, Url);
    SET_DOMAIN_PARAMATER(QString, time, Time);
    SET_DOMAIN_PARAMATER(QString, releaseTime, ReleaseTime);


};

#endif // VERSIONDOMAIN_H
