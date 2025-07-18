# Shoutout to CMake guide: https://eliasdaler.github.io/using-cmake/
cmake_minimum_required(VERSION 3.30) # Update to cmake 3.3

IF (WIN32)
    set(CMAKE_C_COMPILER C:/msys64/mingw64/bin/gcc.exe)
    set(CMAKE_CXX_COMPILER C:/msys64/mingw64/bin/g++.exe)
    # this makes sure that .dll-files are build into build/ folder
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
ELSEIF (APPLE)
    # run 'where clang' and 'where clang++' to get paths
    set(CMAKE_C_COMPILER /usr/bin/clang)
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
ELSEIF (UNIX AND NOT APPLE)
    # run 'which gcc' and 'which g++' to get paths
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)
ENDIF()
# Static Linking
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")

    
# Get project name from folder name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

# Use c++ 17
set(CMAKE_CXX_STANDARD 17)
# Enable additional warnings and debug mode
# https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html
set (CMAKE_CXX_FLAGS "-g -W -pedantic")

# All .cpp-files
set(SOURCES src/main.cpp
        src/main.hpp
        src/trixune/collision.cpp
        src/trixune/collision.hpp
)
# folder with .h files, e.g. include/
include_directories(src)
#include_directories(src/trixune)

# TrixUne Linking
file(GLOB TRIXUNE_SOURCES src/trixune/*.cpp)
list(APPEND SOURCES ${TRIXUNE_SOURCES})
#add_executable(trixune
#	main.cpp ${TRIXUNE_SOURCES})

# 3rd party dependencies
add_subdirectory(lib)

# Here the .c/.cpp files get linked
add_executable(${PROJECT_NAME} ${SOURCES})

# Here we link 3rd party library ImGui-SFML
# No need to link SFML implicitly as ImGui-SFML does it for you!
# Refer to https://eliasdaler.github.io/using-cmake/
target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)

# Additional resources like images and fonts
# We want the to copy from permanent folder "res" to temporary folder "build"
# configure_file(res/OpenSans-Regular.ttf OpenSans-Regular.ttf COPYONLY)

# Output is the file name on finish
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "output")
