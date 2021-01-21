cmake_minimum_required(VERSION 3.17)
project(glad)

set(GLAD_SRCS src/glad.c)

add_library(glad ${GLAD_SRCS})

target_include_directories(glad PUBLIC include/)