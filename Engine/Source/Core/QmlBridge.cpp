#include "QmlBridge.h"
#include "EngineVisitor.h"

QmlBridge::QmlBridge(GameEngine &engine, QObject *parent)
    : m_engine(engine)
    , QObject(parent)
{}

void QmlBridge::sendClose()
{
    dispatcher(QmlEvents::Closed{});
}

void QmlBridge::sendButtonPress(const QString &buttonName)
{
    dispatcher(QmlEvents::ButtonPressed{buttonName});
}

void QmlBridge::sendMousePress(const qreal &x, const qreal &y, const int buttonType)
{
    dispatcher(QmlEvents::MousePressed{x, y, buttonType});
}

QmlBridge::~QmlBridge() {}

void QmlBridge::dispatcher(const QmlEvents::Event &event)
{
    std::visit(EngineVisitor{m_engine}, event);
}
