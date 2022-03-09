# minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

#define constants
set(PROJECT_NAME 2d-engine)
set(SOURCE_FILE source/main.cpp)

# project name
project(${PROJECT_NAME})

# c++ version
set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

file(GLOB files "source/*.cpp" "source/*.hpp")
foreach(file ${files})
    get_filename_component(fileName ${file} NAME)
    message(STATUS "${fileName}")
endforeach()

# add config files to output
# also tried copying files to output via custom command using copy_directory
# however this did not update files when settings were changed
file(GLOB files "source/config/*.ini")
foreach(file ${files})
    get_filename_component(fileName ${file} NAME)
    configure_file(
            ${file}
            config/${fileName}
            COPYONLY
    )
endforeach()