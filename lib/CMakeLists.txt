find_package(Qt5 REQUIRED COMPONENTS Core)

add_library(hello_lib
  print.cpp
  print.hpp
)

#generate_export_header(hello_lib)

#ecm_generate_export_header(hello_lib VERSION 1.0.0)

target_link_libraries(hello_lib PRIVATE Qt5::Core)
