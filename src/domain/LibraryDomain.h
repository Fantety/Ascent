#ifndef LIBRARYDOMAIN_H
#define LIBRARYDOMAIN_H

#include "../common/common.h"

class LibraryDomain
{
    SET_DOMAIN_PARAMATER(QString, path, Path);
    SET_DOMAIN_PARAMATER(QString, sha1, Sha1);
    SET_DOMAIN_PARAMATER(uint, size, Size);
    SET_DOMAIN_PARAMATER(QString, url, Url);
    SET_DOMAIN_PARAMATER(uint, os, Os);
};

#endif // LIBRARYDOMAIN_H
