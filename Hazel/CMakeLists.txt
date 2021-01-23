cmake_minimum_required(VERSION 3.17)
project(Hazel)

add_subdirectory(vendor/GLFW EXCLUDE_FROM_ALL)
add_subdirectory(vendor/spdlog EXCLUDE_FROM_ALL)
add_subdirectory(vendor/GLAD EXCLUDE_FROM_ALL)
add_subdirectory(vendor/imgui EXCLUDE_FROM_ALL)
add_subdirectory(vendor/glm EXCLUDE_FROM_ALL)

set(HAZEL_SRCS src/Hazel/Application.cpp src/Hazel/Application.hpp src/Hazel/Core.hpp src/Hazel.hpp src/Hazel/EntryPoint.hpp src/Hazel/Log.cpp src/Hazel/Log.hpp src/Hazel/Events/Event.hpp src/Hazel/Events/ApplicationEvent.hpp src/Hazel/Events/KeyEvent.hpp src/Hazel/Events/MouseEvent.hpp src/hzpch.hpp src/Hazel/Window.hpp src/Platform/Windows/WindowsWindow.cpp src/Platform/Windows/WindowsWindow.hpp src/Hazel/Layer.cpp src/Hazel/Layer.hpp src/Hazel/LayerStack.cpp src/Hazel/LayerStack.hpp src/Hazel/ImGui/ImGuiLayer.cpp src/Hazel/ImGui/ImGuiLayer.hpp src/Platform/OpenGL/imgui_impl_opengl3.cpp src/Hazel/Input.hpp src/Platform/Windows/WindowsInput.cpp src/Platform/Windows/WindowsInput.hpp src/Hazel/KeyCodes.hpp src/Hazel/MouseButtonCodes.hpp)
add_library(Hazel SHARED ${HAZEL_SRCS})

target_compile_definitions(Hazel PRIVATE GLFW_INCLUDE_NONE)
target_compile_definitions(Hazel PRIVATE HZ_BUILD_DLL)
target_include_directories(Hazel PRIVATE vendor/imgui/src)
target_precompile_headers(Hazel PUBLIC src/hzpch.hpp)

target_link_libraries(Hazel glfw)
target_link_libraries(Hazel glad)
target_link_libraries(Hazel spdlog)
target_link_libraries(Hazel imgui)
target_link_libraries(Hazel glm)

if(MSVC)
    install(TARGETS Hazel RUNTIME DESTINATION ${MYHAZEL_INSTALL_DIR})
elseif(UNIX AND NOT APPLE) # needs to run export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
    install(TARGETS Hazel LIBRARY DESTINATION ${MYHAZEL_INSTALL_DIR})
endif()
