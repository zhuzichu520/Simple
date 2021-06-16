#include <base/BaseController.h>

/**
 * BaseController 构造函数
 * @param parent
 */
BaseController::BaseController(QObject *parent) {
    qDebug() << "执行BaseController的构造函数";
}

/**
 * BaseController 析构函数
 * @param parent
 */
BaseController::~BaseController() {
    qDebug() << "执行BaseController的析构函数";
}

/**
 * onCreateView 当QML中的跟布局执行Component.onCompleted的时候触发
 * @param root 根布局的指针
 */
void BaseController::onCreateView(QObject *root) {
    qDebug() << "执行BaseController的onCreateView方法";
    m_root = root;
    initView();
}

/**
 * 窗口跳转
 * @param url 跳转QML资源路径
 */
void BaseController::startActivity(const QString &url) {
    QMetaObject::invokeMethod(m_root, "startActivity", Q_ARG(QVariant, url));
}

/**
 * 窗口内的页面跳转
 * @param url 跳转QML资源路径
 */
void BaseController::startFragment(const QString &url) {
    QMetaObject::invokeMethod(m_root, "startFragment", Q_ARG(QVariant, url));
}

/**
 * 页面返回，如果没有子页面则退出窗口
 */
void BaseController::back() {
    QMetaObject::invokeMethod(m_root, "back");
}

void BaseController::toast(const QString &text) {
    QMetaObject::invokeMethod(m_root, "toast", Q_ARG(QVariant, text));
}
