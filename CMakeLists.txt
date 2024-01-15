cmake_minimum_required(VERSION 3.22.0)
project(pong LANGUAGES CXX)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set build type
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

# add cpp files
file(GLOB_RECURSE source CONFIGURE_DEPENDS "src/*.cpp")

# include raylib
add_subdirectory(external/raylib)

# add the app.cpp
set(SOURCES app.cpp ${source})

# create the excutable
add_executable(app ${SOURCES})

# include the headers 
target_include_directories(app PRIVATE header)

# link raylib
target_link_libraries(app PRIVATE raylib)

# static raylib link
# target_link_libraries(app PRIVATE raylib_static)
