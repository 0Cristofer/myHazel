cmake_minimum_required(VERSION 3.17)
project(Hazel)

set(SOURCE_FILES src/Test.cpp src/Test.h)

add_library(Hazel SHARED ${SOURCE_FILES})
