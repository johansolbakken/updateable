cmake_minimum_required(VERSION 3.10)

project(sandbox)

add_executable(sandbox main.cpp)
target_include_directories(sandbox PRIVATE ../../loader/src)
target_link_libraries(sandbox PRIVATE updatableloader)

add_library(sandboxapp SHARED 
    src/sandboxapp.h src/sandboxapp.cpp)
target_include_directories(sandboxapp PRIVATE ../../updateable/src)
target_link_libraries(sandboxapp PRIVATE updateable)