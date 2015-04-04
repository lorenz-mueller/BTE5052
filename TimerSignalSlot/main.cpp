#include <QApplication>
#include <QQmlApplicationEngine>
#include "maingame.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainGame* mainGame = new MainGame(&app);    //Create a new MainGame and make it a child of app.

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
