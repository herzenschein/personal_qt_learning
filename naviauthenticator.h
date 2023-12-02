#pragma once

#include <QObject>
#include <QtQml>
#include <QByteArray>
#include "navitoken.h"

class NaviAuthenticator : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QByteArray server MEMBER server NOTIFY serverChanged)
    Q_PROPERTY(QByteArray user MEMBER user NOTIFY userChanged)
    Q_PROPERTY(QByteArray password MEMBER password NOTIFY passwordChanged)

public:
    NaviAuthenticator(QObject *parent = nullptr);

    NaviToken *generator;

    QByteArray server;
    QByteArray user;
    QByteArray password;
    QByteArray token;
    QByteArray salt;
    QByteArray client;
    QByteArray version;

public slots:
    QUrl generateCall();

signals:
    void serverChanged();
    void userChanged();
    void passwordChanged();
};
