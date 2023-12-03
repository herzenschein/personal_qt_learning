#include "naviauthenticator.h"


NaviAuthenticator::NaviAuthenticator(QObject *parent)
    : QObject{parent}, client{"QNaviLib"}, version{"1.16.1"}
{
    qInfo() << Q_FUNC_INFO;
}

void NaviAuthenticator::getRequest()
{
    qInfo() << Q_FUNC_INFO;
    ping.setUrl(generateCall());
    reply = manager.get(ping);

    QObject::connect(reply, &QIODevice::readyRead, this, &NaviAuthenticator::readyRead);
    QObject::connect(reply, &QNetworkReply::errorOccurred, this,
                     [this](){qInfo() << "An error occurred!" << reply->readAll();});

}

QUrl NaviAuthenticator::generateCall()
{
    qInfo() << Q_FUNC_INFO;
    generateToken();
    return QUrl(server + ":4533/rest/ping"
                     + "?u=" + user
                     + "&t=" + token
                     + "&s=" + salt
                     + "&c=" + client
                     + "&v=" + version);
}

void NaviAuthenticator::generateToken()
{
    qInfo() << Q_FUNC_INFO;
    quint32 randomNumber = QRandomGenerator::securelySeeded().bounded(11111111,99999999);
    this->salt.setNum(randomNumber);
    this->token = QCryptographicHash::hash(password + salt, QCryptographicHash::Md5).toHex();
}

void NaviAuthenticator::readyRead()
{
    qInfo() << Q_FUNC_INFO;
    QByteArray response = reply->readAll();
    QDebug info = qInfo();
    info.noquote();
    info << "Response!" << response;
}

