#ifndef CLIENTDOMAIN_H
#define CLIENTDOMAIN_H

#include "../common/common.h"

class ClientDomain
{
    SET_DOMAIN_PARAMATER(QString, sha1, Sha1);
    SET_DOMAIN_PARAMATER(uint, size, Size);
    SET_DOMAIN_PARAMATER(QString, url, Url);
};

#endif // CLIENTDOMAIN_H
