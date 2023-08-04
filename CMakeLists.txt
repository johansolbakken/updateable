cmake_minimum_required(VERSION 3.10)

project(updateable)

set(CMAKE_CXX_STANDARD 23)

set(BUILD_EXAMPLES OFF CACHE BOOL "Build examples")

add_subdirectory(loader)
add_subdirectory(updateable)

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()