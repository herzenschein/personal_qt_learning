#pragma once

#include <KQuickAddons/ManagedConfigModule>
#include <myconfig.h>

class TimeSettings : public KQuickAddons::ManagedConfigModule
{
    Q_OBJECT
    Q_PROPERTY(Time::Config *config READ config CONSTANT)

public:
    TimeSettings(QObject *parent, const KPluginMetaData &data, const QVariantList &args);

    Time::Config *config() const;

private:
  Time::Config *m_config;

};
