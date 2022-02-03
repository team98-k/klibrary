# Miminum required version of CMake.
cmake_minimum_required(VERSION 3.11)

# Project info
project(
    klibrary
    VERSION 1.0.0
    DESCRIPTION "klibrary"
    LANGUAGES CXX
)

# Set variable 'srcPath' to ./src
set(srcPath ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Make executable files.
add_executable(
    ${PROJECT_NAME}
    ${srcPath}/main.cpp
)