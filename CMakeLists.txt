cmake_minimum_required(VERSION 3.16)

project(qnavi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Xml)

qt_standard_project_setup()

qt_add_executable(appqnavi
    main.cpp
)

qt_add_qml_module(appqnavi
    URI qnavi
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES restclient.h restclient.cpp
    SOURCES naviauthenticator.h naviauthenticator.cpp
    SOURCES navitoken.h navitoken.cpp
)

target_link_libraries(appqnavi
    PRIVATE Qt6::Quick Qt6::Xml
)

include(GNUInstallDirs)
install(TARGETS appqnavi
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
