cmake_minimum_required(VERSION 3.17)
# add library executable
file(GLOB solver_SRC
    "src/*.h"
    "src/*.cpp"
)

add_library(Solver ${solver_SRC})
target_include_directories(Solver PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

target_compile_features(Solver PUBLIC cxx_std_17)
set_target_properties(Solver PROPERTIES CXX_EXTENSIONS OFF)

# include libs
target_link_libraries(Solver PUBLIC EqNode)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor)
target_link_libraries(Solver PRIVATE minpack)

# Setup Eigen3
INCLUDE_DIRECTORIES ( ${EIGEN3_INCLUDE_DIR} )

# Setup nlopt
find_package(nlopt REQUIRED)
target_include_directories(Solver PUBLIC "${NLOPT_INCLUDE_DIRS}")
target_link_directories(Solver PUBLIC "${NLOPT_LIBRARY_DIRS}")
target_link_libraries(Solver PUBLIC nlopt)
target_link_libraries(Solver PUBLIC spdlog_header_only)
