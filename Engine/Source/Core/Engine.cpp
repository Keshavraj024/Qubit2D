#include "Engine.h"

#include <QCoreApplication>
#include "QmlBridge.h"

#include <QQmlContext>
#include <QQuickWindow>

GameEngine::GameEngine() {}

bool GameEngine::init(QmlBridge *bridge)
{
    QObject::connect(&m_qmlEngine, &QQmlApplicationEngine::objectCreationFailed, []() {
        QCoreApplication::exit(-1);
    });

    m_qmlEngine.rootContext()->setContextProperty("Bridge", bridge);

    m_qmlEngine.loadFromModule("Qubit2D", "Main");

    auto rootObjects = m_qmlEngine.rootObjects();
    QObject *root = rootObjects.first();
    QQuickWindow *window = qobject_cast<QQuickWindow *>(root);

    if (window) {
        // 'beforeSynchronizing' or 'afterAnimating' are the best hooks for game logic
        QObject::connect(
            window,
            &QQuickWindow::afterAnimating,
            this,
            [this]() {
                // --- THIS IS THE START OF YOUR GAME LOOP ---
                m_engineContext.time.Update();

                // Now you can update other systems:
                // physicsSystem.step(timeManager.GetDeltaTime());
                // aiSystem.update();
            },
            Qt::DirectConnection);
    }

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
