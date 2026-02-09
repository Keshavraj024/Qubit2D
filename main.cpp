#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Engine.h"

#ifdef Q_OS_WIN
extern "C" {
// This tells the NVIDIA driver: "Turn on the big guns for this app!"
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}
#endif

int main(int argc, char *argv[])
{
    // qputenv("QSG_RHI_PREFER_SOFTWARE_RENDERER", "0");
    qputenv("QSG_INFO", "1");
    QGuiApplication app(argc, argv);

    // app.setWindowIcon();

    GameEngine engine;
    if (!engine.init())
        return -1;

    return app.exec();
}
