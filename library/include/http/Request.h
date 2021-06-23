#ifndef SIMPLE_REQUEST_H
#define SIMPLE_REQUEST_H

#include <QNetworkReply>
#include <QTimer>
#include <QIODevice>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkCookie>
#include <tools/ToolLog.h>

#define ERROR_CODE_MD5 -555
#define ERROR_CODE_JSON -333
#define ERROR_CODE_SSL  -1000
#define ERROR_CODE_TIMEOUT -10000

class Request : public QObject {
Q_OBJECT
public:

    enum UPClassHttpError {
        HTTP_JSON_ERROR,

        HTTP_VALUE_ERROR,

        HTTP_NETWORK_ERROR,

        HTTP_SSL_ERROR,

        HTTP_TIMEOUT_ERROR,

        FILE_CREATE_ERROR,

        FILE_ERROR
    };

    Request(QNetworkReply *reply, const QString &url, int timeout);

    virtual ~Request();

    void quit();

    const QString &getUrl();

    void setTimeout(int value);

    QVariant getUserData() const;

    void setUserData(const QVariant &value);

    bool isQuit();

signals:

    void onQuit();

    void onSuccess(const QString &response);

    void onSuccessByte(const QByteArray &byte);

    void onFail(int errType, int errCode, const QString &err);

    void onFinish();

protected:

    void onReplyRedyRead();

    void onReplyFinished();

    void onReplyError(QNetworkReply::NetworkError code);

    void onReplysslError(const QList<QSslError> &errors);

    void onTimeout();

    void saveCookie();

private:

    QNetworkReply *reply;

    QTimer timer;

    QString url;

    int timeout;

    QByteArray response;

    bool hasQuit;

    bool hasError;

    bool hasTimeout;

    QVariant userData;
};

#endif
