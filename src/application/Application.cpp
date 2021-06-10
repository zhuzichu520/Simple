#include <application/Application.h>
#include <QDateTime>
#include <tools/ToolLog.h>

Q_GLOBAL_STATIC(Application, application)

Application *Application::instance() {
    return application();
}

void Application::init(int argc, char *argv[]) {
    LOG(INFO) << "main函数参数长度:" << argc;
    LOG(INFO) << "开始初始化:" << QDateTime::currentDateTimeUtc().toTime_t();
    ToolLog toolLog(argv);
    registerQmlType();
    initHttp();
    LOG(INFO) << "结束初始化:" << QDateTime::currentDateTimeUtc().toTime_t();
}

void Application::registerQmlType() {
    qmlRegisterType<LoginController>("UI.Controller", 1, 0, "LoginController");
}

void Application::initHttp() {
    netManager = new QNetworkAccessManager();
}
