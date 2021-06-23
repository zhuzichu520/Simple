#ifndef SIMPLE_APPLICATION_H
#define SIMPLE_APPLICATION_H

#include <QGlobalStatic>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <login/LoginController.h>
#include <home/HomeController.h>
#include <tool/ToolController.h>
#include <tools/ToolDate.h>
#include <tools/ToolLog.h>
#include <QNetworkAccessManager>

#define APP Application::instance()

class Application {
public:

    Application() = default;

    virtual ~Application() = default;

    static Application *instance();

    void init(int argc, char *argv[]);

private:
    void registerQmlType();
};

#endif
