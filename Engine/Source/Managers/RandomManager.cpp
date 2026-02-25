#include "RandomManager.h"

RandomManager::RandomManager()
    : m_generator(QRandomGenerator::securelySeeded())
{}

int RandomManager::Int(int min, int max)
{
    if (min > max)
        std::swap(min, max);
    return m_generator.bounded(min, max + 1);
}

float RandomManager::Float(float min, float max)
{
    if (min > max)
        std::swap(min, max);
    // generateDouble() returns [0, 1.0]
    return static_cast<float>(min + (m_generator.generateDouble() * (max - min)));
}

bool RandomManager::Bool(float probability)
{
    return m_generator.generateDouble() < static_cast<double>(probability);
}

QVector2D RandomManager::Position(const QVector2D &min, const QVector2D &max)
{
    return QVector2D(Float(min.x(), max.x()), Float(min.y(), max.y()));
}

float RandomManager::Angle(float min, float max)
{
    return Float(min, max);
}

QColor RandomManager::Color(const QColor &min, const QColor &max)
{
    return QColor::fromRgb(Int(min.red(), max.red()),
                           Int(min.green(), max.green()),
                           Int(min.blue(), max.blue()),
                           Int(min.alpha(), max.alpha()));
}
