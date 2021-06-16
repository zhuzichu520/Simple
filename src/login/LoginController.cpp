#include <login/LoginController.h>


LoginController::LoginController(QObject *parent) : BaseController(parent) {
    qDebug() << "执行LoginController的构造函数";
}

LoginController::~LoginController() {
    qDebug() << "执行LoginController的构造函数";
}

const QString &LoginController::getUsername() const {
    return username;
}

void LoginController::setUsername(const QString &username) {
    LoginController::username = username;
    Q_EMIT usernameChanged(username);
}

const QString &LoginController::getPassword() const {
    return password;
}

void LoginController::setPassword(const QString &password) {
    LoginController::password = password;
    Q_EMIT passwordChanged(username);
}

void LoginController::initView() {
    setUsername("zhuzichu520@gmail.com");
    setPassword("qaioasd520");
}

void LoginController::onClickLogin() {
    qDebug() << "用户名：" + username;
    qDebug() << "密码：" + password;
    QMap<QString, QString> paramMap;
    paramMap["username"] = username;
    paramMap["password"] = password;
    Request *request = HttpManager::instance().post("https://www.wanandroid.com/user/login", paramMap);
    connect(request, &Request::onSuccess, this, [this](QString response) {
        toast(response);
    });
}