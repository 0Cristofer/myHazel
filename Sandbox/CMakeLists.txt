cmake_minimum_required(VERSION 3.17)
project(Sandbox)

set(SOURCE_FILES src/Application.cpp)

add_executable(Sandbox ${SOURCE_FILES})

target_link_libraries(Sandbox Hazel)
