#ifndef SIMPLE_HTTPMANAGER_H
#define SIMPLE_HTTPMANAGER_H

#include <QMap>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QHttpPart>
#include <QJsonObject>
#include <QJsonDocument>
#include <spdlog/spdlog.h>
#include <http/Request.h>

class HttpManager {
public:

    static HttpManager &instance() {
        static HttpManager manager;

        return manager;
    }

    Request *get(const QString &urlString, const QMap<QString, QString> &params, int timeout = 100000);

    Request *postJson(const QString &urlString, const QMap<QString, QString> &params, int timeout = 100000);

    Request *post(const QString &urlString, const QMap<QString, QString> &params, int timeout = 100000);

private:
    HttpManager();

    ~HttpManager();

private:

    QNetworkAccessManager *networkAccessManager;
};


#endif
