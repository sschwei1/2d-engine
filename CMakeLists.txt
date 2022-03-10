# minimum version of CMake required
cmake_minimum_required(VERSION 3.15)


#define constants
set(PROJECT_NAME 2d-engine)
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/source/*.cpp" "${CMAKE_SOURCE_DIR}/source/*.h")

# project name
project(${PROJECT_NAME})

# c++ version
set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# link external libaries
target_link_libraries(
        ${PROJECT_NAME}
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)

# add config files to output
# also tried copying files to output via custom command using copy_directory
# however this did not update files when settings were changed
file(GLOB CONFIG_FILES "${CMAKE_SOURCE_DIR}/source/config/*.ini")
foreach(CONFIG_FILE ${CONFIG_FILES})
    get_filename_component(CONFIG_FILE_NAME ${CONFIG_FILE} NAME)
    configure_file(
            ${CONFIG_FILE}
            config/${CONFIG_FILE_NAME}
            COPYONLY
    )
endforeach()