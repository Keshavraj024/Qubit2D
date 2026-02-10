#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>

#include "Engine.h"
#include "QmlBridge.h"

#include <QDebug>
#include <QDirIterator>

#include <QQmlContext>

#ifdef Q_OS_WIN
extern "C" {
// This tells the NVIDIA driver: "Turn on the big guns for this app!"
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

int main(int argc, char *argv[])
{
    // qputenv("QSG_INFO", "1");
    QGuiApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/Assets/Icons/AppIcon.png"));

    GameEngine engine;

    QmlBridge bridge(engine);

    if (!engine.init(&bridge))
        return -1;

    return app.exec();
}
