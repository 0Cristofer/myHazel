cmake_minimum_required(VERSION 3.17)
project(Sandbox)

set(SANDOBOX_SRCS src/SandboxApp.cpp)

add_executable(Sandbox ${SANDOBOX_SRCS})

target_include_directories(Sandbox PRIVATE ${HAZEL_INCLUDE})
target_link_libraries(Sandbox Hazel)

install(TARGETS Sandbox RUNTIME DESTINATION ${MYHAZEL_INSTALL_DIR})
