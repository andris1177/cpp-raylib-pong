cmake_minimum_required(VERSION 3.22.0)
project(pong LANGUAGES CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Add cpp files
file(GLOB_RECURSE source CONFIGURE_DEPENDS "src/*.cpp")

# Include raylib
add_subdirectory(external/raylib)

# Include raygui
include_directories(external/raygui/src)

# Include json
include_directories(external/json/single_include/nlohmann)

# Add the pong.cpp
set(SOURCES app.cpp ${source})

# Create the executable
add_executable(pong ${SOURCES})

# Include the headers 
target_include_directories(pong PRIVATE header)

# Link raylib
target_link_libraries(pong PRIVATE raylib)
