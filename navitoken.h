#pragma once

#include <QByteArray>
#include <QDebug>


class NaviToken
{
public:
    explicit NaviToken();
    QByteArray password;
    QByteArray token;
    QByteArray salt;
};
