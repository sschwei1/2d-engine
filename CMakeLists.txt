# minimum version of CMake required
cmake_minimum_required(VERSION 3.15)


#define constants
set(PROJECT_NAME 2d-engine)
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/source/*.cpp" "${CMAKE_SOURCE_DIR}/source/*.h")

# project name
project(${PROJECT_NAME})

# c++ version
set(CMAKE_CXX_STANDARD 20)

# add static libaries in case mingw was used
if(MINGW)
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
endif()

# add static sfml libs
set(SFML_STATIC_LIBRARIES TRUE)

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