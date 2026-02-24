#pragma once

#include <QString>
#include <cstdint>

struct EngineConfig
{
    uint32_t m_width;
    uint32_t m_height;

    bool m_logToFile{false};
    QString m_logPath{};

    EngineConfig();
};

inline const EngineConfig gEngineConfig;
