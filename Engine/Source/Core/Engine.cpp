#include "Engine.h"
#include <QCoreApplication>
#include "QmlBridge.h"

#include <QQmlContext>

GameEngine::GameEngine() {}

bool GameEngine::init(QmlBridge *bridge)
{
    QObject::connect(&m_qmlEngine, &QQmlApplicationEngine::objectCreationFailed, []() {
        QCoreApplication::exit(-1);
    });

    m_qmlEngine.rootContext()->setContextProperty("Bridge", bridge);

    m_qmlEngine.loadFromModule("Qubit2D", "Main");

    return !m_qmlEngine.rootObjects().empty();
}

void GameEngine::EventWindowClose()
{
    qDebug("Window Closed");
}

void GameEngine::EventMousePressed(const qreal &x, const qreal &y, const int buttonType)
{
    if (buttonType == Qt::LeftButton)
        qDebug() << x;
}

void GameEngine::EventButtonPressed(const QString &name)
{
    qDebug() << name;
}
