cmake_minimum_required(VERSION 3.15)
project(main)

# Specify the include directories for the project
include_directories(/usr/local/include)

# Specify the source files for the project
set(SOURCES main.cpp)

# Create the executable
add_executable(main ${SOURCES})

# Link against the static raylib library
target_link_libraries(main PRIVATE /usr/local/lib/libraylib.a)
