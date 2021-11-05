cmake_minimum_required(VERSION 3.17)

# add library executable
add_library(EqNode src/EqNode.h src/EqNode.cpp)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

target_compile_features(EqNode PUBLIC cxx_std_17)
set_target_properties(EqNode PROPERTIES CXX_EXTENSIONS OFF)

# include  target library
target_include_directories(EqNode PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")