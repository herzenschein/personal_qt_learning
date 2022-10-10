#include "timesettings.hpp"
#include "myconfig.h"

#include <KPluginFactory>
#include <KSharedConfig>
#include <KConfigGroup>

K_PLUGIN_CLASS_WITH_JSON(TimeSettings, "kcm_time.json")

TimeSettings::TimeSettings(QObject *parent, const KPluginMetaData &data, const QVariantList &args)
    : KQuickAddons::ManagedConfigModule(parent, data, args)
    , m_config(new Time::Config(this))
{
    setButtons(Help | Apply | Default);
    qmlRegisterAnonymousType<Time::Config>("org.kde.timesettings.private", 1);

}

Time::Config *TimeSettings::config() const
{
    return m_config;
}

#include "timesettings.moc"
