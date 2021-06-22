#ifndef SIMPLE_TOOLCONTROLLER_H
#define SIMPLE_TOOLCONTROLLER_H

#include <base/BaseController.h>
#include <QString>
#include <qdebug.h>
#include <QNetworkReply>
#include <QObject>
#include <application/Application.h>
#include <http/HttpManager.h>
#include <spdlog/spdlog.h>

class ToolController : public BaseController {
Q_OBJECT
public:
    explicit ToolController(QObject *parent = nullptr);

    ~ToolController() override;

};

#endif
