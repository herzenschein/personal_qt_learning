cmake_minimum_required(VERSION 3.20)

project(hello_app)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

# If this gets uncommented, undefined reference to printHello()
#include(KDECompilerSettings)
include(KDEInstallDirs)
include(KDECMakeSettings NO_POLICY_SCOPE)

add_executable(hello_bin main.cpp)

target_include_directories(hello_bin
  PRIVATE
  lib/
)

target_link_libraries(hello_bin PRIVATE hello_lib)

add_subdirectory(lib)
