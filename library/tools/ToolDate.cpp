//
// Created by Administrator on 2021/6/6 0006.
//
#include <QTime>
#include <ToolDate.h>

ToolDate::ToolDate() {
}

QString ToolDate::getCurrTimeStr() {
    return QTime::currentTime().toString("hh:mm:ss.zzz");
}

QString ToolDate::getCurrDateTimeStr(QString formatStr) {
    return QDateTime::currentDateTime().toString(formatStr);
}

