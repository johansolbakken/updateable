cmake_minimum_required(VERSION 3.10)

project(updatableloader)

set(CMAKE_CXX_STANDARD 23)

add_library(updatableloader STATIC 
    src/loader/loader.h  src/loader/loader.cpp
)
target_include_directories(updatableloader PUBLIC src ../updateable/src)
target_link_libraries(updatableloader PUBLIC updateable)