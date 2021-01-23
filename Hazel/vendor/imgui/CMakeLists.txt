cmake_minimum_required(VERSION 3.17)
project(imgui)

set(IMGUI_SRCS src/imconfig.h src/imgui.cpp src/imgui.h src/imgui_demo.cpp src/imgui_draw.cpp src/imgui_internal.h src/imgui_tables.cpp src/imgui_widgets.cpp src/imstb_rectpack.h src/imstb_textedit.h src/imstb_truetype.h)

add_library(imgui ${IMGUI_SRCS})

target_compile_definitions(imgui PRIVATE HZ_BUILD_DLL)
target_include_directories(imgui PUBLIC src/)