cmake_minimum_required(VERSION 3.4.1)

add_library( hello_cmake

             SHARED

             hello.c )

find_library(log-lib

              log )

target_link_libraries( hello_cmake
                       ${log-lib} )
