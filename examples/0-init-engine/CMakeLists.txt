# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(0-init-engine VERSION 1.0)

set(EXECUTABLE_NAME init-engine)

# Define the source files for your project
set(SOURCES
    main.cpp
)

# Add an executable target
add_executable(${EXECUTABLE_NAME} ${SOURCES})

find_package(Boost REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(spdlog REQUIRED)

MESSAGE(${CMAKE_SOURCE_DIR})

target_include_directories(${EXECUTABLE_NAME} PUBLIC
                            "${CMAKE_SOURCE_DIR}/lib/game-engine-core/src"
                            )

# Optional: Link libraries to your executable
# For example, linking against a library named "my_lib"
target_link_libraries(${EXECUTABLE_NAME} PRIVATE Boost::boost ${SDL2_LIBRARIES} yaml-cpp::yaml-cpp spdlog::spdlog game-engine-core)
