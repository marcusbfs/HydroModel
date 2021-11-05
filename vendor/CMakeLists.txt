cmake_minimum_required(VERSION 3.17)

SET(EIGEN3_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/eigen3" PARENT_SCOPE)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/spdlog")
