project(Photogrammetry)

cmake_minimum_required(VERSION 2.6)
find_package(Imagine REQUIRED)

add_executable(Photogrammetry main.cpp)
ImagineUseModules(Photogrammetry Graphics)
