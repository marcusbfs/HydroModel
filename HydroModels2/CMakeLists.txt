cmake_minimum_required(VERSION 3.17)
# add library executable
file(GLOB HYDROMODELS2_SRC
    "src/*.h"
    "src/*.cpp"
    "src/interpreter/*.h"
    "src/interpreter/*.cpp"
)

add_library(HydroModels2 SHARED ${HYDROMODELS2_SRC})

# tell compile that it is shared lib
target_compile_definitions(HydroModels2 PUBLIC HYDROMOELS_DLL)
target_compile_definitions(HydroModels2 PRIVATE HYDROMODELS_UIAPI_EXPORTS)

# include folder
target_include_directories(HydroModels2 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")


set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

target_compile_features(HydroModels2 PUBLIC cxx_std_17)
set_target_properties(HydroModels2 PROPERTIES CXX_EXTENSIONS OFF)

# include libs
target_link_libraries(HydroModels2 PRIVATE BipartiteGraph)
target_link_libraries(HydroModels2 PRIVATE EqNode)
target_link_libraries(HydroModels2 PRIVATE Solver)

# antlr4
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor")
target_include_directories(HydroModels2 PRIVATE "${ANTLR4_INCLUDE_DIR}")
target_link_directories(HydroModels2 PRIVATE "${ANTLR4_LIBRARY_DIR}")
target_link_libraries(HydroModels2 PRIVATE antlr4-runtime)


