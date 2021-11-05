cmake_minimum_required(VERSION 3.17)

# add library executable (header only)
add_library(BipartiteGraph INTERFACE)

target_include_directories(BipartiteGraph INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
