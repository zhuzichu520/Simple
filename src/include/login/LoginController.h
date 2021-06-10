#ifndef SIMPLE_LOGINCONTROLLER_H
#define SIMPLE_LOGINCONTROLLER_H

#include <base/BaseController.h>
#include <QString>
#include <qdebug.h>
#include <QNetworkReply>

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

    void initView() override;

    void requestFinished(QNetworkReply *reply);

signals:

    void usernameChanged(const QString &);

    void passwordChanged(const QString &);

private:
    QString password;
    QString username;
};

#endif
