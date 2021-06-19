#include <base/BaseController.h>


BaseController::BaseController(QObject *parent) {
    SPDLOG_INFO("执行BaseController的构造函数");
}


BaseController::~BaseController() {
    SPDLOG_INFO("执行BaseController的析构函数");
}

void BaseController::onCreateView(QObject *root) {
    SPDLOG_INFO("执行BaseController的onCreateView方法");
    m_root = root;
    initView();
}

void BaseController::startActivity(const QVariant &url) {
    QMetaObject::invokeMethod(m_root, "startActivity", Q_ARG(QVariant, url));
}

void BaseController::startFragment(const QVariant &url) {
    QMetaObject::invokeMethod(m_root, "startFragment", Q_ARG(QVariant, url));
}

void BaseController::back() {
    QMetaObject::invokeMethod(m_root, "back");
}

void BaseController::toast(const QString &text) {
    Q_EMIT toastEvent(text);
}