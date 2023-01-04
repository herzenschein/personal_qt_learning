find_package(Qt5 REQUIRED COMPONENTS Core)

add_library(hello_lib
  print.cpp
  print.hpp
)

target_link_libraries(hello_lib PRIVATE Qt5::Core)
