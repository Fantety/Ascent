#ifndef COMMANDLINEDOMAIN_H
#define COMMANDLINEDOMAIN_H

#include "../common/common.h"

class CommandLineDomain
{
    //game参数
    SET_DOMAIN_PARAMATER(QString, username, Username);
    SET_DOMAIN_PARAMATER(QString, version, Version);
    SET_DOMAIN_PARAMATER(QString, gameDir, GameDir);
    SET_DOMAIN_PARAMATER(QString, assetsDir, AssetsDir);
    SET_DOMAIN_PARAMATER(QString, assetsIndex, AssetsIndex);
    SET_DOMAIN_PARAMATER(QString, uuid, Uuid);
    SET_DOMAIN_PARAMATER(QString, accessToken, AccessToken);
    SET_DOMAIN_PARAMATER(QString, clientId, ClientId);
    SET_DOMAIN_PARAMATER(QString, xuid, Xuid);
    SET_DOMAIN_PARAMATER(QString, userType, UserType);
    SET_DOMAIN_PARAMATER(QString, versionType, VersionType);
    //jvm参数
    SET_DOMAIN_PARAMATER(QString, xx, Xx);
    SET_DOMAIN_PARAMATER(QString, dosName, DosName);
    SET_DOMAIN_PARAMATER(QString, dosVersion, DosVersion);
    SET_DOMAIN_PARAMATER(QString, xss, Xss);
    SET_DOMAIN_PARAMATER(QString, launcherBrand, LauncherBrand);
    SET_DOMAIN_PARAMATER(QString, launcherVersion, LauncherVersion);
    SET_DOMAIN_PARAMATER(QString, cp, Cp);


};

#endif // COMMANDLINEDOMAIN_H
