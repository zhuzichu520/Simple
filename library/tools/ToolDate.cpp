#include <tools/ToolDate.h>

ToolDate::ToolDate() {
}

QString ToolDate::getCurrTimeStr() {
    return QTime::currentTime().toString("hh:mm:ss.zzz");
}

QString ToolDate::getCurrDateTimeStr(QString formatStr) {
    return QDateTime::currentDateTime().toString(formatStr);
}

