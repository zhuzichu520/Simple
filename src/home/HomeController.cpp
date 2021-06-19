#include <home/HomeController.h>

HomeController::HomeController(QObject *parent) : BaseController(parent) {
    SPDLOG_INFO("执行HomeController的构造函数");
}

HomeController::~HomeController() {
    SPDLOG_INFO("执行HomeController的构造函数");
}

void HomeController::initView() {


}

void HomeController::loadData(const QString &page) {

}
