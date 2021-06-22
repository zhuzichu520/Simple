#ifndef SIMPLE_HOMECONTROLLER_H
#define SIMPLE_HOMECONTROLLER_H

#include <base/BaseController.h>
#include <QString>
#include <qdebug.h>
#include <QNetworkReply>
#include <QObject>
#include <application/Application.h>
#include <http/HttpManager.h>
#include <spdlog/spdlog.h>

class HomeController : public BaseController {
Q_OBJECT
public:
    explicit HomeController(QObject *parent = nullptr);

    ~HomeController() override;

    Q_INVOKABLE void loadData(int page);

    void onLazy() override;
};

#endif
