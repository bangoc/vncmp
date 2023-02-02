cmake_minimum_required(VERSION 2.8)
project(cgen)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(vncmp STATIC utf8.c vncmp.c)
add_executable(vnsort vnsort.c)
target_link_libraries(vnsort vncmp)