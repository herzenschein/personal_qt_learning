#pragma once

#include <QObject>
#include <QtQml>
#include <QByteArray>
#include <QCryptographicHash>

class NaviAuthenticator : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QByteArray server MEMBER server NOTIFY serverChanged)
    Q_PROPERTY(QByteArray user MEMBER user NOTIFY userChanged)
    Q_PROPERTY(QByteArray password MEMBER password NOTIFY passwordChanged)

public:
    NaviAuthenticator(QObject *parent = nullptr);

    QByteArray server;
    QByteArray user;
    QByteArray password;
    QByteArray token;
    QByteArray salt;
    QByteArray client;
    QByteArray version;

    QNetworkAccessManager manager;
    QNetworkRequest ping;
    QNetworkReply *reply;

public slots:
    void generateToken();
    QUrl generateCall();
    void getRequest();
    void readyRead();

signals:
    void serverChanged();
    void userChanged();
    void passwordChanged();
};
