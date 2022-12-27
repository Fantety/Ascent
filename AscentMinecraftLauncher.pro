QT       += core gui testlib network

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

CONFIG += c++17

INCLUDEPATH += \
    src/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/http/HttpGet.cpp \
    src/json/JsonParse.cpp \
    src\widget.cpp \
    test/TestGetVersions/TestGetVersions.cpp

HEADERS += \
    src/common/ComMacro.h \
    src/common/common.h \
    src/domain/AssetDomain.h \
    src/domain/AssetObjectDomain.h \
    src/domain/ClientDomain.h \
    src/domain/CommandLineDomain.h \
    src/domain/LibraryDomain.h \
    src/domain/VersionDomain.h \
    src/http/HttpGet.h \
    src/json/JsonParse.h \
    src/widget.h \
    test/TestCommon.h \
    test/TestGetVersions/TestGetVersions.h

TRANSLATIONS += \
    AscentMinecraftLauncher_en.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
