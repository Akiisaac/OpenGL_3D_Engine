cmake_minimum_required(VERSION 3.10)
project(OpenGL)

# Set C++ standard to C17
set (CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES
    "src/main.cpp"
)

# Compiler flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lGLEW")

# Create the executable
add_executable(OpenGL ${SOURCES})
