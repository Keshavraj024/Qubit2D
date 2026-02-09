#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <qqmlintegration.h>

class GameEngine : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    GameEngine();
    bool init();

private:
    QQmlApplicationEngine m_qmlEngine;
};
