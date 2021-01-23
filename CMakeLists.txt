cmake_minimum_required(VERSION 3.17)
project(myHazel)

set(CMAKE_CXX_STANDARD 17)
set(MYHAZEL_INSTALL_DIR ${CMAKE_SOURCE_DIR}/out/release/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

if(MSVC)
    add_compile_definitions(HZ_PLATFORM_WINDOWS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
elseif(UNIX AND NOT APPLE)
    add_compile_definitions(HZ_PLATFORM_LINUX)
endif()

add_compile_definitions($<$<CONFIG:Debug>:HZ_DEBUG> $<$<CONFIG:Release>:HZ_RELEASE> $<$<CONFIG:MinSizeRel>:HZ_DIST>)

add_subdirectory(Hazel)
add_subdirectory(Sandbox)
