#include "Logger.h"
#include <QCoreApplication>
#include "EngineConfig.h"
#include <iostream>

static QMutex s_logMutex;
static QFile *logFile;

void messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QMutexLocker locker(&s_logMutex);

    // 1. Format Timestamp
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");

    // 2. Identify Log Level
    const char *levelStr;
    const char *colorCode; // Reset

    switch (type) {
    case QtDebugMsg:
        levelStr = "DEBUG";
        colorCode = "\033[36m";
        break; // Cyan
    case QtInfoMsg:
        levelStr = "INFO ";
        colorCode = "\033[32m";
        break; // Green
    case QtWarningMsg:
        levelStr = "WARN ";
        colorCode = "\033[33m";
        break; // Yellow
    case QtCriticalMsg:
        levelStr = "CRIT ";
        colorCode = "\033[31m";
        break; // Red
    case QtFatalMsg:
        levelStr = "FATAL";
        colorCode = "\033[41m";
        break; // Red Background
    default:
        levelStr = "DEBUG";
        colorCode = "\033[0m";
    }

    QString filePath = context.file;
    QString fileName = filePath.section('/', -1);

    // Format: [2026-02-24 10:00:00.000] [DEBUG] [Main.cpp:42] Message
    QString output = QString("[%1] [%2] [%3:%4] %5")
                         .arg(timestamp)
                         .arg(levelStr)
                         .arg(fileName)
                         .arg(context.line)
                         .arg(msg);

    std::cerr << colorCode << output.toStdString() << "\033[0m" << std::endl;

    if (!logFile && gEngineConfig.m_logToFile) {
        logFile = new QFile(QCoreApplication::applicationDirPath() + "/engine.log");
        if (!logFile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            // It might trigger recursion when used with qDebug()
            std::cerr << "Failed to create log file" << std::endl;
        } else {
            qAddPostRoutine(EngineLogger::cleanupLogger);
        }
    }

    if (logFile && logFile->isOpen()) {
        logFile->write(output.toUtf8() + "\n");
        logFile->flush();
    }

    if (type == QtFatalMsg)
        abort();
}

namespace EngineLogger {

void installHandler()
{
    qInstallMessageHandler(messageOutput);
}

void cleanupLogger()
{
    if (logFile) {
        logFile->flush();
        logFile->close();
        logFile = nullptr;
    }
}

} // namespace EngineLogger
