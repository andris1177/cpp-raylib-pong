cmake_minimum_required(VERSION 3.22.0)
project(pong LANGUAGES CXX)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Relase)

file(GLOB_RECURSE source CONFIGURE_DEPENDS "src/*.cpp")

# Specify the source files for the project
set(SOURCES app.cpp)

# Create the executable
add_executable(app ${SOURCES} ${source})

target_link_libraries(app PRIVATE /usr/local/lib/libraylib.a)
