#include "widget.h"
#include "stdafx.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#ifndef TEST
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTranslator translator;
    //const QStringList uiLanguages = QLocale::system().uiLanguages();
    //for (const QString &locale : uiLanguages) {
    //    const QString baseName = "AscentMinecraftLauncher_" + QLocale(locale).name();
    //    if (translator.load(":/i18n/" + baseName)) {
    //        a.installTranslator(&translator);
    //        break;
    //    }
    //}
    Widget w;
    w.show();
    return a.exec();
}
#endif
