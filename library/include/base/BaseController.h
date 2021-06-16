#ifndef SIMPLE_BASECONTROLLER_H
#define SIMPLE_BASECONTROLLER_H

#include <QObject>
#include <spdlog/spdlog.h>

class BaseController : public QObject {
Q_OBJECT
public:
    explicit BaseController(QObject *parent = nullptr);

    ~BaseController() override;

    Q_INVOKABLE void onCreateView(QObject *root);

    Q_INVOKABLE static void logi(const QString &info);

    virtual void initView() = 0;

    void startActivity(const QVariant &url);

    void startFragment(const QVariant &url);

    void toast(const QVariant &text);

    void back();

private:
    QObject *m_root = nullptr;
};

#endif
