cmake_minimum_required(VERSION 3.17)
project(Hazel)

add_compile_definitions(HZ_BUILD_DLL)

set(SOURCE_FILES src/Hazel/Application.cpp src/Hazel/Application.hpp src/Hazel/Core.hpp src/Hazel.hpp src/Hazel/EntryPoint.hpp src/Hazel/Log.cpp src/Hazel/Log.hpp)

add_library(Hazel SHARED ${SOURCE_FILES})

target_include_directories(Hazel PRIVATE ${SPDLOG_INCLUDE})
