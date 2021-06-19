#include <application/Application.h>

Q_GLOBAL_STATIC(Application, application)

Application *Application::instance() {
    return application();
}

void Application::init(int argc, char *argv[]) {
    SPDLOG_INFO("main函数参数长度:{}",argc);
    SPDLOG_INFO("OpenSSL支持情况:{}",QSslSocket::supportsSsl());
    SPDLOG_INFO("开始初始化:{}",QDateTime::currentDateTimeUtc().toTime_t());
    registerQmlType();
    SPDLOG_INFO("结束初始化:{}",QDateTime::currentDateTimeUtc().toTime_t());
}

void Application::registerQmlType() {
    qmlRegisterType<LoginController>("UI.Controller", 1, 0, "LoginController");
    qmlRegisterType<HomeController>("UI.Controller", 1, 0, "HomeController");
    qmlRegisterType<ToolController>("UI.Controller", 1, 0, "ToolController");
}