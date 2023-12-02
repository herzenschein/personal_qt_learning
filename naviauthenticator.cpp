#include "naviauthenticator.h"
#include <QCryptographicHash>


NaviAuthenticator::NaviAuthenticator(QObject *parent)
    : QObject{parent}, client{"QNaviLib"}, version{"1.16.1"}
{
    generator = new NaviToken;
    password = generator->password;
    token = generator->token;
    qInfo() << "Is token empty?" << token;
    qInfo() << "Is generator token empty?" << generator->token;
    salt = generator->salt;
}

QUrl NaviAuthenticator::generateCall()
{
    qInfo() << "=====" << Q_FUNC_INFO;
    qInfo() << "Entered user:" << user;
    qInfo() << "This salt should NOT be the same as that from NaviToken\n"
               "since it should be based on the user password:" << salt;
    qInfo() << "This token should NOT be the same as that from NaviToken\n"
               "since it should be based on the user password:" << token;
    return QUrl(server + ":4533/rest/ping"
                     + "?u=" + user
                     + "&t=" + token
                     + "&s=" + salt
                     + "&c=" + client
                     + "&v=" + version);
}
