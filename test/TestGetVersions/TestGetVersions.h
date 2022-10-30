#ifndef TESTGETVERSIONS_H
#define TESTGETVERSIONS_H

#include <QObject>
#include "../TestCommon.h"

class TestGetVersions : public QObject
{
    Q_OBJECT
    QString json;
private slots:
    void test1_get_versions();
    void test2_parse_json();

private slots:
    void test1_use_slot1(QString result);
};

#endif // TESTGETVERSIONS_H
