#include "EngineConfig.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

EngineConfig::EngineConfig()
{
    QFile file(":/Content/EngineConfig.json");

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open config file!";
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    QJsonObject obj = doc.object();

    QJsonObject graphics = obj["graphics"].toObject();

    if (graphics.contains("windowWidth")) {
        m_width = graphics["windowWidth"].toInt();
    }
    if (graphics.contains("windowHeight")) {
        m_height = graphics["windowHeight"].toInt();
    }

    QJsonObject logging = obj["logging"].toObject();

    if (logging.contains("logToFile")) {
        m_logToFile = logging["logToFile"].toBool();
    }
    if (logging.contains("logPath")) {
        m_logPath = logging["logPath"].toString();
    }

    qDebug() << "Config Loaded Successfully";
}
