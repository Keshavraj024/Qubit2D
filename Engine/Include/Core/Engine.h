#pragma once

#include <QObject>
#include <QQmlApplicationEngine>

#include "EngineContext.h"
#include "QmlBridge.h"
#include <qqmlintegration.h>

class GameEngine : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    GameEngine();
    bool init(QmlBridge *bridge);

    void EventWindowClose();
    void EventMousePressed(const qreal &x, const qreal &y, const int buttonType);
    void EventButtonPressed(const QString &name);
    // void EventWindowResize(const sf::Vector2u& windowSize);
    // void EventWindowFocusLost();
    // void EventWindowFocusGain();
    // void EventJoystickConnected(const int id);
    // void EventJoystickDisconnected(const int id);
    // void EventMouseButtonPressed();
    // void EventWindowScreenshot();
    // void EventSceneChange(const std::string &sceneName);
    // void EventSceneRestart();
    // void EventSceneMenuReturn();
    // void EventOverlayPauseToggle();
    // void EventOverlaySelection(OverlaySelection selection);

private:
    QQmlApplicationEngine m_qmlEngine;
    EngineContext m_engineContext;
};
