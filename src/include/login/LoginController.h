#ifndef SIMPLE_LOGINCONTROLLER_H
#define SIMPLE_LOGINCONTROLLER_H

#include <base/BaseController.h>
#include <QString>
#include <qdebug.h>
#include <QNetworkReply>
#include <QObject>
#include <application/Application.h>
#include <http/HttpManager.h>
#include <tools/ToolLog.h>

class LoginController : public BaseController {
Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
public:
    explicit LoginController(QObject *parent = nullptr);

    ~LoginController() override;

    Q_INVOKABLE void onClickLogin();

    const QString &getUsername() const;

    void setUsername(const QString &username);

    const QString &getPassword() const;

    void setPassword(const QString &password);

signals:

    void usernameChanged(const QString &);

    void passwordChanged(const QString &);

private:
    QString m_password;
    QString m_username;
};

#endif
