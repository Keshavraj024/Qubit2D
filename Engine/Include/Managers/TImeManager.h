#pragma once

#include <QElapsedTimer>

class TimeManager
{
public:
    TimeManager();

    void Update();

    float extracted() const;
    float GetDeltaTime() const;   // Seconds since last frame
    float GetElapsedTime() const; // Seconds since manager started

private:
    QElapsedTimer m_timer;
    qint64 m_lastFrameTimeNs;
    float m_deltaTime;
};
