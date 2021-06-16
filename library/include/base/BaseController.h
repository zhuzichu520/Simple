#ifndef SIMPLE_BASECONTROLLER_H
#define SIMPLE_BASECONTROLLER_H

#include <QObject>
#include <qdebug.h>

class BaseController : public QObject {
Q_OBJECT
public:
    explicit BaseController(QObject *parent = nullptr);

    ~BaseController() override;

    Q_INVOKABLE void onCreateView(QObject *root);

    virtual void initView() = 0;

    void startActivity(const QString &url);

    void startFragment(const QString &url);

    void toast(const QString &text);

    void back();

private:
    QObject *m_root = nullptr;
};

#endif
