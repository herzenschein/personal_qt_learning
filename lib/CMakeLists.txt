find_package(Qt5 REQUIRED COMPONENTS Core)

add_library(hello_lib
  print.cpp
  print.hpp
)

generate_export_header(hello_lib
  # This will be the name of the exported header
  # in ${CMAKE_BINARY_DIR}/lib
  # a.k.a. build/lib/libhello_export.h
  EXPORT_FILE_NAME
    libhello_export.h
  # Inside libhello_export.h there is
  # a macro called LIBHELLO_EXPORT
  # that is based on this BASE_NAME!
  BASE_NAME
    libhello

  # After all this, we need to
  # #include "libhello_export.h"
  # in lib/print.h to expose its macros,
  # then use the LIBHELLO_EXPORT macro
  # to expose its functions or classes!
  # This is done after the return type, so
  # void LIBHELLO_EXPORT print();,
  # or something like
  # class LIBHELLO_EXPORT Hello { public: void print(); };
)

#ecm_generate_export_header(hello_lib VERSION 1.0.0)

target_link_libraries(hello_lib PRIVATE Qt5::Core)
