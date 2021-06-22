#include <home/HomeController.h>

HomeController::HomeController(QObject *parent) : BaseController(parent) {
    SPDLOG_INFO("执行HomeController的构造函数");
}

HomeController::~HomeController() {
    SPDLOG_INFO("执行HomeController的构造函数");
}

void HomeController::loadData(int page) {
    QMap<QString, QString> paramMap;
    Request *request = HttpManager::instance().get(
            QString("https://www.wanandroid.com/article/list/%1/json").arg(page),
            paramMap);
    connect(request, &Request::onSuccess, this, [this](const QString &response) {
        toast(response);
    });
}

void HomeController::onLazy() {
    loadData(1);
}
