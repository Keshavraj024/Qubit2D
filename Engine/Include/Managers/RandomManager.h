#pragma once

#include <QColor>
#include <QRandomGenerator>
#include <QVector2D>
#include <QVector3D>

class RandomManager
{
public:
    RandomManager();

    // Basic Types
    int Int(int min, int max);
    float Float(float min, float max);
    bool Bool(float probability = 0.5f);

    // Engine/Geometry Types
    QVector2D Position(const QVector2D &min, const QVector2D &max);

    float Angle(float min = 0.0f, float max = 360.0f);
    QColor Color(const QColor &min = Qt::black, const QColor &max = Qt::white);

private:
    QRandomGenerator m_generator;
};
