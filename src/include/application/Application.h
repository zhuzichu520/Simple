#ifndef SIMPLE_APPLICATION_H
#define SIMPLE_APPLICATION_H

#include <QGlobalStatic>
#include <QQmlApplicationEngine>
#include <qdebug.h>
#include <QGuiApplication>
#include <login/LoginController.h>
#include <tools/ToolDate.h>
#include <qdebug.h>
#include <QNetworkAccessManager>

#define APP Application::instance()

class Application {
public:

    QNetworkAccessManager *netManager;

    Application() = default;

    virtual ~Application() = default;

    static Application *instance();

    void init(int argc, char *argv[]);

private:
    void registerQmlType();

    void initHttp();
};

#endif
