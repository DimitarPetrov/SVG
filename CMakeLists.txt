cmake_minimum_required(VERSION 3.7)
project(SVG)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SOURCE_FILES main.cpp FileCommands.cpp FileCommands.h Shape.cpp Shape.h Rectangle.cpp Rectangle.h Circle.cpp Circle.h Line.cpp Line.h ShapeArr.cpp ShapeArr.h)
add_executable(SVG ${SOURCE_FILES})