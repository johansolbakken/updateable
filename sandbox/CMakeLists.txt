cmake_minimum_required(VERSION 3.10)

project(sandbox)

add_executable(sandbox src/main.cpp)
target_include_directories(sandbox PRIVATE ../loader/src)
target_link_libraries(sandbox PRIVATE updatableloader)