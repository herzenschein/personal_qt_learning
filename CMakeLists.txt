cmake_minimum_required(VERSION 3.20)
project(kconfigxttest)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(KDEInstallDirs5)
include(KDECMakeSettings)

find_package(Qt5 REQUIRED COMPONENTS Quick)
find_package(KF5 REQUIRED COMPONENTS Kirigami2 Config)

add_subdirectory(src)
