#include <base/BaseController.h>


BaseController::BaseController(QObject *parent) {

}


BaseController::~BaseController() {
    LOG(INFO)<<"执行BaseController的析构函数";
}

void BaseController::onCreateView(QObject *root) {
    m_root = root;
}


void BaseController::onDestroyView() {

}


void BaseController::onStart() {

}

void BaseController::onStop() {

}

void BaseController::onLazy() {

}

void BaseController::startActivity(const QVariant &url) {
    Q_EMIT startActivityEvent(url);
}

void BaseController::startFragment(const QVariant &url) {
    Q_EMIT startFragmentEvent(url);
}

void BaseController::back() {
    Q_EMIT backEvent();
}

void BaseController::toast(const QString &text) {
    Q_EMIT toastEvent(text);
}