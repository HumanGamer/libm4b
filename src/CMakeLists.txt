project(libm4b)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC "")
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${PROJECT_NAME}
    PRIVATE
        m4b.cpp
        m4b.hpp

    PUBLIC
        ${CMAKE_SOURCE_DIR}/include/libm4b.h
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
