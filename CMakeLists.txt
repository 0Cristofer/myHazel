cmake_minimum_required(VERSION 3.17)
project(myHazel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Sandbox)
add_subdirectory(Hazel)

install(TARGETS Sandbox Hazel RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})
