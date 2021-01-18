cmake_minimum_required(VERSION 3.17)
project(Hazel)

set(SOURCE_FILES src/Hazel/Application.cpp src/Hazel/Application.hpp src/Hazel/Core.hpp src/Hazel.hpp src/Hazel/EntryPoint.hpp src/Hazel/Log.cpp src/Hazel/Log.hpp src/Hazel/Events/Event.hpp src/Hazel/Events/ApplicationEvent.hpp src/Hazel/Events/KeyEvent.hpp src/Hazel/Events/MouseEvent.hpp src/hzpch.hpp)

add_library(Hazel SHARED ${SOURCE_FILES})

target_precompile_headers(Hazel PRIVATE src/hzpch.hpp)
target_compile_definitions(Hazel PRIVATE HZ_BUILD_DLL)
target_include_directories(Hazel PRIVATE ${SPDLOG_INCLUDE})
