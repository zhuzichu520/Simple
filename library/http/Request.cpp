#include <http/Request.h>

Request::Request(QNetworkReply *reply, const QString &url, int timeout)
        : reply(reply), url(url), timeout(timeout), hasQuit(false), hasError(false), hasTimeout(false) {
    LOG(INFO) << "request url : " << url.toStdString();

    connect(reply, &QIODevice::readyRead, this, &Request::onReplyRedyRead);
    connect(reply, &QNetworkReply::finished, this, &Request::onReplyFinished);
    connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), this,
            &Request::onReplyError);
    connect(reply, &QNetworkReply::sslErrors, this, &Request::onReplysslError);
    connect(this, &Request::onFinish, this, &QObject::deleteLater);

    setTimeout(timeout);
}

Request::~Request() {
    timer.stop();

    if (reply != nullptr) {
        reply->abort();

        delete reply;

        reply = nullptr;
    }
}

void Request::quit() {
    LOG(INFO) << "quit request : " << url.toStdString();

    hasQuit = true;

    timer.stop();

    if (reply != nullptr)
        reply->abort();
}

const QString &Request::getUrl() {
    return url;
}

void Request::onReplyRedyRead() {
    QByteArray data = reply->readAll();

    response.append(data);
}

void Request::onReplyFinished() {
    if (hasQuit) {
        emit onQuit();
        emit onFinish();
    }

    if (hasQuit || hasError || hasTimeout)
        return;

    timer.stop();

    saveCookie();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(response, &err);

    if (err.error != QJsonParseError::NoError) {
        LOG(INFO) << "request json fail :" << response.toStdString();

        emit onFail(UPClassHttpError::HTTP_JSON_ERROR, ERROR_CODE_JSON, "json parse error !");

        emit onFinish();

        return;
    }

    QJsonObject obj = doc.object();

    if (obj["errorCode"].toInt() != 0) {
        LOG(INFO) << "response " << response.toStdString();

        LOG(INFO) << "request " << url.toStdString() << "error, code : " << obj["errorCode"].toInt() << ", errorMsg : "
                  << obj["msg"].toString().toStdString();
        LOG(INFO) << response.toStdString();

        emit onFail(UPClassHttpError::HTTP_VALUE_ERROR, obj["errorCode"].toInt(), obj["msg"].toString());

        emit onFinish();

        return;
    }

    LOG(INFO) << "request finish : " << url.toStdString();

    emit onSuccess(response);

    emit onSuccessByte(response);

    emit onFinish();
}

void Request::onReplyError(QNetworkReply::NetworkError code) {

    if (hasQuit || hasTimeout)
        return;

    timer.stop();

    hasError = true;

    LOG(INFO) << "request network error :" << url.toStdString() << code
              << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    emit onFail(UPClassHttpError::HTTP_NETWORK_ERROR,
                reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), "network error !");

    emit onFinish();
}

void Request::onReplysslError(const QList<QSslError> &errors) {
    if (hasQuit || hasTimeout)
        return;

    timer.stop();

    hasError = true;

    LOG(INFO) << "request ssl error :" << url.toStdString();

    emit onFail(UPClassHttpError::HTTP_SSL_ERROR, ERROR_CODE_SSL, "ssl error !");

    emit onFinish();
}

void Request::onTimeout() {
    if (hasError || hasQuit)
        return;

    hasTimeout = true;

    if (reply != nullptr)
        reply->abort();

    LOG(INFO) << "request time out :" << url.toStdString();

    emit onFail(UPClassHttpError::HTTP_TIMEOUT_ERROR, ERROR_CODE_TIMEOUT, "http timeout !");

    emit onFinish();
}

void Request::saveCookie() {
    QVariant varRequestCookies = reply->request().header(QNetworkRequest::CookieHeader);

    QVariant varResponseCookies = reply->header(QNetworkRequest::SetCookieHeader);

    QList<QNetworkCookie> cookies = varRequestCookies.value<QList<QNetworkCookie> >();

    //dosomething
}

QVariant Request::getUserData() const {
    return userData;
}

void Request::setUserData(const QVariant &value) {
    userData = value;
}

bool Request::isQuit() {
    return hasQuit;
}

void Request::setTimeout(int value) {
    timeout = value;

    if (timeout != 0) {
        timer.setInterval(timeout);

        timer.setSingleShot(true);

        timer.start();

        connect(&timer, &QTimer::timeout, this, &Request::onTimeout);
    }
}