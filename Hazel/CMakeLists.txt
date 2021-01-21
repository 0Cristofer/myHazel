cmake_minimum_required(VERSION 3.17)
project(Hazel)

find_package(OpenGL REQUIRED)

set(HAZEL_SRCS src/Hazel/Application.cpp src/Hazel/Application.hpp src/Hazel/Core.hpp src/Hazel.hpp src/Hazel/EntryPoint.hpp src/Hazel/Log.cpp src/Hazel/Log.hpp src/Hazel/Events/Event.hpp src/Hazel/Events/ApplicationEvent.hpp src/Hazel/Events/KeyEvent.hpp src/Hazel/Events/MouseEvent.hpp src/hzpch.hpp src/Hazel/Window.hpp src/Platform/Windows/WindowsWindow.cpp src/Platform/Windows/WindowsWindow.hpp src/Hazel/Layer.cpp src/Hazel/Layer.hpp src/Hazel/LayerStack.cpp src/Hazel/LayerStack.hpp)

add_library(Hazel SHARED ${HAZEL_SRCS})

target_compile_definitions(Hazel PRIVATE GLFW_INCLUDE_NONE)
target_precompile_headers(Hazel PUBLIC src/hzpch.hpp)
target_compile_definitions(Hazel PRIVATE HZ_BUILD_DLL)

target_link_libraries(Hazel glfw)
target_link_libraries(Hazel glad)
target_link_libraries(Hazel spdlog)
target_link_libraries(Hazel OpenGL::GL)
