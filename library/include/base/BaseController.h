#ifndef SIMPLE_BASECONTROLLER_H
#define SIMPLE_BASECONTROLLER_H

#include <QObject>
#include <tools/ToolLog.h>

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

    Q_INVOKABLE void onDestroyView();

    Q_INVOKABLE void onStart();

    Q_INVOKABLE void onStop();

    Q_INVOKABLE virtual void onLazy();

    void startActivity(const QVariant &url);

    Q_SIGNAL void startActivityEvent(const QVariant &url);

    void startFragment(const QVariant &url);

    Q_SIGNAL void startFragmentEvent(const QVariant &url);

    void toast(const QString &text);

    Q_SIGNAL void toastEvent(const QString &text);

    void back();

    Q_SIGNAL void backEvent();

private:
    QObject *m_root = nullptr;
};

#endif
