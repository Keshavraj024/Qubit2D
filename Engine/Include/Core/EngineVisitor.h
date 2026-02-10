#pragma once

#include "Engine.h"
#include "Events.h"

struct EngineVisitor
{
    GameEngine &engine;

    void operator()(const QmlEvents::Closed &);
    void operator()(const QmlEvents::Resized &event);
    void operator()(const QmlEvents::MousePressed &event);
    void operator()(const QmlEvents::MouseReleased &event);
    void operator()(const QmlEvents::ButtonPressed &event);
    void operator()(const QmlEvents::ButtonReleased &event);
    void operator()(const QmlEvents::KeyPressed &event);
    void operator()(const QmlEvents::KeyReleased &event);
    void operator()(const QmlEvents::FocusChanged &event);

    void operator()(const auto &) {}
};
