#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "window.h"


int main(int argCount, char* argVector[])
{
    QGuiApplication app(argCount, argVector);

    WindowSettings* config = WindowSettings::self();
    qmlRegisterSingletonInstance("kconfigxttest", 1, 0, "WindowSettings", config);

    QQmlApplicationEngine engine;
    engine.load("qrc:/main.qml");

    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
