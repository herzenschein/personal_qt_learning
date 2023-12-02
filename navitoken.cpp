#include "navitoken.h"
#include <QRandomGenerator>
#include <QCryptographicHash>

NaviToken::NaviToken()
{
    quint32 randomNumber = QRandomGenerator::securelySeeded().bounded(11111111,99999999);
    this->salt.setNum(randomNumber);
    this->token = QCryptographicHash::hash(password + salt, QCryptographicHash::Md5).toHex();
    qInfo() << "=====" << Q_FUNC_INFO;
    qInfo() << "This salt is generated upon NaviToken construction:" << this->salt;
    qInfo() << "This token is generated upon NaviToken construction" << this->token;
}
