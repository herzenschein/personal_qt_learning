add_executable(${PROJECT_NAME} main.cpp resources.qrc)

kconfig_add_kcfg_files(${PROJECT_NAME} GENERATE_MOC window.kcfgc)

target_link_libraries(${PROJECT_NAME} Qt5::Quick KF5::Kirigami2 KF5::ConfigGui KF5::ConfigCore)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
