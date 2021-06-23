#include <QObject>
#include <glog/logging.h>
#include <QStandardPaths>
#include <QDir>

#ifndef SIMPLE_TOOLLOG_H
#define SIMPLE_TOOLLOG_H

class ToolLog {
public:
    explicit ToolLog(char *argv[]);

    ~ToolLog();

private:
    void configureGoogleLog();

    static void messageHandler(QtMsgType, const QMessageLogContext &context, const QString &message);
};

#endif
