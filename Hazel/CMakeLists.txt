cmake_minimum_required(VERSION 3.17)
project(Hazel)

add_compile_definitions(HZ_BUILD_DLL)

set(SOURCE_FILES src/Hazel/Application.cpp src/Hazel/Application.hpp src/Hazel/Core.hpp src/Hazel.hpp src/Hazel/EntryPoint.hpp)

add_library(Hazel SHARED ${SOURCE_FILES})
