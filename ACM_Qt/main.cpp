#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "database.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

	QQmlContext *root = engine.rootContext();
	DataBase *db = new DataBase();
	root->setContextProperty("dbClass", db);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
