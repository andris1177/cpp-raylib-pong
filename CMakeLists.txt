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

# Add the pong.cpp
set(SOURCES app.cpp ${source})

# Create the executable
add_executable(pong ${SOURCES})

# Include the headers 
target_include_directories(pong PRIVATE header)

# Link raylib
target_link_libraries(pong PRIVATE raylib)

# Set destination dir
if (CMAKE_GENERATOR MATCHES "Visual Studio")
    set(SOUNDS_DESTINATION_DIR ${CMAKE_BINARY_DIR}/Release/sounds)
    set(CONFIG_DESTINATION_DIR ${CMAKE_BINARY_DIR}/Release/config)
else()
    set(SOUNDS_DESTINATION_DIR ${CMAKE_BINARY_DIR}/sounds)
    set(CONFIG_DESTINATION_DIR ${CMAKE_BINARY_DIR}/config)
endif()

# Create the destination directories
file(MAKE_DIRECTORY ${SOUNDS_DESTINATION_DIR})
file(MAKE_DIRECTORY ${CONFIG_DESTINATION_DIR})

# Copy the sounds folder
file(COPY ${CMAKE_SOURCE_DIR}/sounds/ DESTINATION ${SOUNDS_DESTINATION_DIR})

# Copy the game.config 
file(COPY ${CMAKE_SOURCE_DIR}/config/game.config DESTINATION ${CONFIG_DESTINATION_DIR})
