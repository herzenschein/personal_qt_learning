#include "restclient.h"
#include <QDebug>

RestClient::RestClient(QObject *parent)
    : QObject{parent}
{
    if (!auth)
    {
        auth = new NaviAuthenticator;
    }
}

void RestClient::getRequest()
{
    ping.setUrl(auth->generateCall());
    reply = manager.get(ping);

    QObject::connect(reply, &QIODevice::readyRead, this, &RestClient::readyRead);
    QObject::connect(reply, &QNetworkReply::errorOccurred, this,
                     [this](){qInfo() << "An error occurred!" << reply->readAll();});

}

void RestClient::readyRead()
{
    QByteArray response = reply->readAll();
    QDebug info = qInfo();
    info.noquote();
    info << "Response!" << response;
}
