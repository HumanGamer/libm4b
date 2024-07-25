project(libm4b_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} "")
target_link_libraries(${PROJECT_NAME} libm4b)

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)