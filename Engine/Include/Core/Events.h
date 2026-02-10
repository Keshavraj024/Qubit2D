#pragma once
#include <QString>
#include <qtypes.h>

// void operator()(const sf::Event::Closed &);
// void operator()(const sf::Event::Resized &);
// void operator()(const sf::Event::FocusLost &);
// void operator()(const sf::Event::FocusGained &);
// void operator()(const sf::Event::JoystickConnected &);
// void operator()(const sf::Event::JoystickDisconnected &);
// void operator()(const sf::Event::MouseButtonPressed &);
// void operator()(const sf::Event::KeyPressed &);
// void operator()(const sf::Event::JoystickButtonPressed &);

namespace QmlEvents {
struct Closed
{};

struct Resized
{
    size_t width;
    size_t height;
};

struct MousePressed
{
    qreal x;
    qreal y;
    int buttonType;
};

struct MouseReleased
{
    qreal x;
    qreal y;
    int buttonType;
};

struct ButtonPressed
{
    QString buttonName;
};

struct ButtonReleased
{
    QString buttonName;
};

struct KeyPressed
{
    int key;
};

struct KeyReleased
{
    int key;
};

struct FocusChanged
{
    bool isWindowActive;
};

using Event = std::variant<Closed,
                           Resized,
                           MousePressed,
                           MouseReleased,
                           ButtonPressed,
                           ButtonReleased,
                           KeyPressed,
                           KeyReleased,
                           FocusChanged>;
} // namespace QmlEvents
