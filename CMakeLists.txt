cmake_minimum_required(VERSION 3.20)

project(hello_app)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

# KDECompilerSettings defines CMAKE_CXX_VISIBILITY_PRESET hidden
# which in turn translates to -fvisibility=hidden
# causing an undefined reference error for printHello()
include(KDECompilerSettings)
include(KDEInstallDirs)
include(KDECMakeSettings NO_POLICY_SCOPE)

# Neither of these two seem to fix the issue
include(GenerateExportHeader)
include(ECMGenerateExportHeader)

add_executable(hello_bin main.cpp)

target_include_directories(hello_bin
  PRIVATE
  lib/
)

target_link_libraries(hello_bin PRIVATE hello_lib)

add_subdirectory(lib)
