cmake_minimum_required(VERSION 3.17)
project(myHazel)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(HZ_PLATFORM_WINDOWS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(HZ_PLATFORM_LINUX)
endif()

set(HAZEL_SOURCE ${CMAKE_SOURCE_DIR}/Hazel/src)
add_compile_definitions($<$<CONFIG:Debug>:HZ_DEBUG> $<$<CONFIG:Release>:HZ_RELEASE> $<$<CONFIG:MinSizeRel>:HZ_DIST>)

add_subdirectory(Hazel/vendor/GLFW)
add_subdirectory(Hazel/vendor/spdlog)
add_subdirectory(Sandbox)
add_subdirectory(Hazel)

# Install
set(INSTALL_DIR ${CMAKE_SOURCE_DIR}/out/release/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

install(TARGETS Sandbox RUNTIME DESTINATION ${INSTALL_DIR})
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    install(TARGETS Hazel RUNTIME DESTINATION ${INSTALL_DIR})
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux") # needs to run export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
    install(TARGETS Hazel LIBRARY DESTINATION ${INSTALL_DIR})
endif()
