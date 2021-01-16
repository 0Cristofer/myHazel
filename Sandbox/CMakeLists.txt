cmake_minimum_required(VERSION 3.17)
project(Sandbox)

set(SOURCE_FILES src/SandboxApp.cpp)

add_executable(Sandbox ${SOURCE_FILES})

target_include_directories(Sandbox PRIVATE ${HAZEL_SOURCE})
target_include_directories(Sandbox PRIVATE ${SPDLOG_INCLUDE})
target_link_libraries(Sandbox Hazel)
