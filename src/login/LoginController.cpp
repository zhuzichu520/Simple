#include <login/LoginController.h>
#include <QObject>
#include <application/Application.h>

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
    setUsername("haha");
    setPassword("haha");
}

void LoginController::onClickLogin() {
    qDebug() << "用户名：" + username;
    qDebug() << "密码：" + password;
//    QNetworkRequest request;
//    QMetaObject::Connection connRet = QObject::connect(
//            APP->netManager,
//            SIGNAL(finished(QNetworkReply * )),
//            this,
//            SLOT(requestFinished(QNetworkReply * ))
//    );
//    Q_ASSERT(connRet);
//    QString url = "https://www.wanandroid.com/user/login";
//    request.setUrl(url);
//    APP->netManager->post(request,"test");
    startFragment("qrc:/layout/FragmentLogin.qml");
//    back()

}

void LoginController::requestFinished(QNetworkReply *reply) {
    // 获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (statusCode.isValid())
        qDebug() << "status code=" << statusCode.toInt();

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if (reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    if (err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    } else {
        // 获取返回内容
        qDebug() << reply->readAll();
    }
}