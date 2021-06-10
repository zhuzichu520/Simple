#include <application/Application.h>
#include <QDateTime>

Q_GLOBAL_STATIC(Application, application)

Application *Application::instance() {
    return application();
}

void Application::init() {
    qDebug() << "开始初始化:" << QDateTime::currentDateTimeUtc().toTime_t();
    registerQmlType();
    initHttp();
    qDebug() << "结束初始化:" << QDateTime::currentDateTimeUtc().toTime_t();
}

void Application::registerQmlType() {
    qmlRegisterType<WindowFramelessHelper>("QtShark.Window", 1, 0, "FramelessHelper");
    qmlRegisterType<LoginController>("UI.Controller", 1, 0, "LoginController");
}

void Application::initHttp() {
    netManager = new QNetworkAccessManager();
}
