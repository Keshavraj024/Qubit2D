#include "EngineVisitor.h"

void EngineVisitor::operator()(const QmlEvents::Closed &)
{
    engine.EventWindowClose();
}

void EngineVisitor::operator()(const QmlEvents::Resized &event) {}

void EngineVisitor::operator()(const QmlEvents::MousePressed &event)
{
    engine.EventMousePressed(event.x, event.y, event.buttonType);
}
void EngineVisitor::operator()(const QmlEvents::MouseReleased &event) {};
void EngineVisitor::operator()(const QmlEvents::ButtonPressed &event)
{
    engine.EventButtonPressed(event.buttonName);
};
void EngineVisitor::operator()(const QmlEvents::ButtonReleased &event) {};
void EngineVisitor::operator()(const QmlEvents::KeyPressed &event) {};
void EngineVisitor::operator()(const QmlEvents::KeyReleased &event) {};
void EngineVisitor::operator()(const QmlEvents::FocusChanged &event) {};
