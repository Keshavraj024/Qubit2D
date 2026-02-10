#pragma once

#include "Events.h"
#include <qobject.h>

class GameEngine;

class QmlBridge : public QObject
{
    Q_OBJECT
public:
    QmlBridge(GameEngine &engine, QObject *parent = nullptr);

    Q_INVOKABLE void sendClose();
    Q_INVOKABLE void sendButtonPress(const QString &buttonName);

    Q_INVOKABLE void sendMousePress(const qreal &x, const qreal &y, const int buttonType);

    ~QmlBridge();

private:
    GameEngine &m_engine;
    void dispatcher(const QmlEvents::Event &);
};
