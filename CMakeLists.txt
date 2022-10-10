cmake_minimum_required(VERSION 3.20)

project(timekcm)

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDEInstallDirs)
include(KDECMakeSettings)

find_package(Qt5 REQUIRED COMPONENTS
    Quick
)

find_package(KF5 REQUIRED COMPONENTS
    I18n
    KCMUtils
    Declarative
    Config
)

kcoreaddons_add_plugin(kcm_time INSTALL_NAMESPACE "plasma/kcms/systemsettings")

kconfig_add_kcfg_files(kcm_time myconfig.kcfgc)

target_sources(kcm_time PRIVATE timesettings.cpp)

target_link_libraries(kcm_time
    Qt5::Core
    KF5::CoreAddons
    KF5::I18n
    KF5::QuickAddons
    KF5::ConfigCore
)

kpackage_install_package(package kcm_time kcms)

kcmutils_generate_desktop_file(kcm_time)
