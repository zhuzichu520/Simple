#ifndef SIMPLE_BASECONTROLLER_H
#define SIMPLE_BASECONTROLLER_H

#include <QObject>
#include <spdlog/spdlog.h>

class BaseController : public QObject {
Q_OBJECT
public:
    explicit BaseController(QObject *parent = nullptr);

    ~BaseController() override;

    /**
    * onCreateView 当QML中的跟布局执行Component.onCompleted的时候触发
    * @param root 根布局的指针
     */
    Q_INVOKABLE void onCreateView(QObject *root);

    virtual void initView() = 0;

    void startActivity(const QVariant &url);

    void startFragment(const QVariant &url);

    void toast(const QString &text);

    void back();

    Q_SIGNAL void toastEvent(const QString &text);

private:
    QObject *m_root = nullptr;
};

#endif
