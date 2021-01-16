cmake_minimum_required(VERSION 3.17)
project(myHazel)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(HZ_PLATFORM_WINDOWS)
endif()

set(HAZEL_SOURCE ${CMAKE_SOURCE_DIR}/Hazel/src)

add_subdirectory(Sandbox)
add_subdirectory(Hazel)

install(TARGETS Sandbox Hazel RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})
