# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(game-engine-core VERSION 1.0)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(LIBRARY_NAME game-engine-core)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# Define the source files for your project
set(SOURCES
    src/renderer/Window.cpp
    src/Engine.cpp
)

# Add an executable target
if(BUILD_SHARED_LIBS)
    add_library(${LIBRARY_NAME} SHARED ${SOURCES})
else()
    add_library(${LIBRARY_NAME} ${SOURCES})
endif()

# Optional: Set include directories if needed
target_include_directories(${LIBRARY_NAME} PRIVATE src)

find_package(Boost REQUIRED)
find_package(SDL2 REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(spdlog REQUIRED)

# SDL2 include directories
include_directories(${SDL2_INCLUDE_DIRS} ${YAML_INCLUDE_DIRS})

# Optional: Link libraries to your executable
# For example, linking against a library named "my_lib"
target_link_libraries(${LIBRARY_NAME} PRIVATE Boost::boost ${SDL2_LIBRARIES} yaml-cpp::yaml-cpp spdlog::spdlog)
