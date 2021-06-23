#include <login/LoginController.h>

LoginController::LoginController(QObject *parent) : BaseController(parent) {

}

LoginController::~LoginController() {

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

void LoginController::onClickLogin() {
    QMap<QString, QString> paramMap;
    paramMap["username"] = m_username;
    paramMap["password"] = m_password;
    toast(m_username);
//    Request *request = HttpManager::instance().post("https://www.wanandroid.com/user/login", paramMap);
//    connect(request, &Request::onSuccess, this, [this](const QString &response) {
//        toast(response);
//    });
}