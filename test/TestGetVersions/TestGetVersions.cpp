#include "TestGetVersions.h"

QTEST_MAIN(TestGetVersions)

void TestGetVersions::test1_get_versions()
{
    HttpGet* http_get = new HttpGet;
    connect(http_get, SIGNAL(sendResult(QString)), this, SLOT(test1_use_slot1(QString)));
    http_get->get("https://launchermeta.mojang.com/mc/game/version_manifest.json");
}

void TestGetVersions::test2_parse_json()
{
    JsonParse parse;
    QVector<VersionDomain> res;
    res = parse.parseToVersionDomain(this->json);
    foreach(auto item, res)
    {
        QVERIFY(!item.getId().isEmpty()
                &&!item.getType().isEmpty()
                &&!item.getUrl().isEmpty()
                &&!item.getTime().isEmpty()
                &&!item.getReleaseTime().isEmpty());
    }
}

void TestGetVersions::test1_use_slot1(QString result)
{
    this->json = result;
    QVERIFY(result.contains("latest")&&result.contains("versions"));
}
