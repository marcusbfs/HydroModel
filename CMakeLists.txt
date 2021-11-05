cmake_minimum_required(VERSION 3.17)

project(HydroModels2)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/EqNode")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/BipartiteGraph")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Solver")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/HydroModels2")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/HydroModelsGUI")