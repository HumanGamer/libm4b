cmake_minimum_required(VERSION 3.28)
project(libm4b)

add_subdirectory(src)

option(BUILD_EXAMPLE "Build example" ON)
if(BUILD_EXAMPLE)
    add_subdirectory(example)
endif()
