#include "authenticator.h"

Authenticator::Authenticator(QObject *parent) {}

void Authenticator::setUser(const QByteArray &newUser)
{
    m_user = newUser;
}

void Authenticator::setPassword(const QByteArray &newPassword)
{
    m_password = newPassword;
}

void Authenticator::setToken(const QByteArray &newToken)
{
    m_token = newToken;
}

void Authenticator::setSalt(const QByteArray &newSalt)
{
    m_salt = newSalt;
}

void Authenticator::setClient(const QByteArray &newClient)
{
    m_client = newClient;
}

void Authenticator::setVersion(const QByteArray &newVersion)
{
    m_version = newVersion;
}

QByteArray Authenticator::user() const
{
    return m_user;
}

QByteArray Authenticator::password() const
{
    return m_password;
}

QByteArray Authenticator::token() const
{
    return m_token;
}

QByteArray Authenticator::salt() const
{
    return m_salt;
}

QByteArray Authenticator::client() const
{
    return m_client;
}

QByteArray Authenticator::version() const
{
    return m_version;
}
