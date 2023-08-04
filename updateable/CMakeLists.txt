cmake_minimum_required(VERSION 3.10)

project(updateable)

add_library(updateable 
    src/updateable/updateable.h
    src/updateable/core/application.h src/updateable/core/application.cpp
    )