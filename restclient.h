#pragma once

#include <QObject>
#include <QtQml>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "naviauthenticator.h"

class RestClient : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(NaviAuthenticator *auth MEMBER auth)
public:
    explicit RestClient(QObject *parent = nullptr);

    NaviAuthenticator *auth;
    QNetworkAccessManager manager;
    QNetworkRequest ping;
    QNetworkReply *reply;

public slots:
    void getRequest();
    void readyRead();

};
