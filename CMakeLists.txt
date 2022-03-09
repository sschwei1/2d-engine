# minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

#define constants
set(PROJECT_NAME 2d-engine)
set(SOURCE_FILE main.cpp)

# project name
project(${PROJECT_NAME})

# c++ version
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)