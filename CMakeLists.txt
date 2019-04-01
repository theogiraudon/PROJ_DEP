project(Photogrammetry)

file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)

cmake_minimum_required(VERSION 2.6)
find_package(Imagine REQUIRED)

add_executable(Photogrammetry main.cpp geometry.h)
ImagineUseModules(Photogrammetry Graphics LinAlg Images)
