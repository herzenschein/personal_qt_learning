#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <QByteArray>
#include <QObject>
#include <QtQml>

class Authenticator : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QByteArray user MEMBER m_user READ user WRITE setUser)
public:
    explicit Authenticator(QObject *parent = nullptr);

    void setUser(const QByteArray &newUser);
    void setPassword(const QByteArray &newPassword);
    void setToken(const QByteArray &newToken);
    void setSalt(const QByteArray &newSalt);
    void setClient(const QByteArray &newClient);
    void setVersion(const QByteArray &newVersion);

    QByteArray user() const;
    QByteArray password() const;
    QByteArray token() const;
    QByteArray salt() const;
    QByteArray client() const;
    QByteArray version() const;

private:
    QByteArray m_user;
    QByteArray m_password;
    QByteArray m_token;
    QByteArray m_salt;
    QByteArray m_client;
    QByteArray m_version;
};

#endif // AUTHENTICATOR_H
