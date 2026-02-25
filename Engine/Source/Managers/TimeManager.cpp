#include "TimeManager.h"
#include <Logger.h>

const float MAX_DELTA_TIME = 0.1f;

TimeManager::TimeManager()
    : m_lastFrameTimeNs(0)
    , m_deltaTime(0.0f)
{
    m_timer.start();
}

void TimeManager::Update()
{
    qint64 currentElapsedTimeNs = m_timer.nsecsElapsed();

    qint64 diff = currentElapsedTimeNs - m_lastFrameTimeNs;

    m_deltaTime = static_cast<float>(diff) / 1000000000.0f;

    m_deltaTime = std::min(m_deltaTime, MAX_DELTA_TIME);

    qDebug() << "Delta time : " << m_deltaTime;

    m_lastFrameTimeNs = currentElapsedTimeNs;
}

float TimeManager::GetDeltaTime() const
{
    return m_deltaTime;
}

float TimeManager::GetElapsedTime() const
{
    return static_cast<float>(m_timer.nsecsElapsed()) / 1000000000.0f;
}
