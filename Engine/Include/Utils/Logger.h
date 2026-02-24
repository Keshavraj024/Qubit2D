#pragma once

#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QMutex>
#include <QTextStream>
// #include <QtGlobal>

namespace EngineLogger {
void installHandler();
void cleanupLogger();
} // namespace EngineLogger
