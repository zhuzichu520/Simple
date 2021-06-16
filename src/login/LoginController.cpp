#include <login/LoginController.h>

LoginController::LoginController(QObject *parent) : BaseController(parent) {
    SPDLOG_INFO("执行LoginController的构造函数");
}

LoginController::~LoginController() {
    SPDLOG_INFO("执行LoginController的构造函数");
}

const QString &LoginController::getUsername() const {
    return m_username;
}

void LoginController::setUsername(const QString &username) {
    m_username = username;
    Q_EMIT usernameChanged(username);
}

const QString &LoginController::getPassword() const {
    return m_password;
}

void LoginController::setPassword(const QString &password) {
    m_password = password;
    Q_EMIT passwordChanged(m_password);
}

void LoginController::initView() {
    setUsername("zhuzichu520@gmail.com");
    setPassword("qaioasd520");
}

void LoginController::onClickLogin() {
    SPDLOG_INFO("用户名：{}", m_username.toStdString());
    SPDLOG_INFO("密码：{}", m_password.toStdString());
    QMap<QString, QString> paramMap;
    paramMap["username"] = m_username;
    paramMap["password"] = m_password;
    Request *request = HttpManager::instance().post("https://www.wanandroid.com/user/login", paramMap);
    connect(request, &Request::onSuccess, this, [this](const QString &response) {
        toast(response);
    });
}