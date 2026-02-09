#include "Engine.h"
#include <QCoreApplication>

GameEngine::GameEngine() {}

bool GameEngine::init()
{
    QObject::connect(&m_qmlEngine, &QQmlApplicationEngine::objectCreationFailed, []() {
        QCoreApplication::exit(-1);
    });
    m_qmlEngine.loadFromModule("Qubit2D", "Main");

    return !m_qmlEngine.rootObjects().empty();
}
