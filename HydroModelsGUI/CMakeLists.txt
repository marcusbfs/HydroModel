cmake_minimum_required(VERSION 3.17)

file(GLOB HYDROMODELSGUI_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/wxfb/*" 
)

add_executable(HydroModelsGUI WIN32 ${HYDROMODELSGUI_SRC})


target_compile_definitions(HydroModelsGUI PRIVATE NDEBUG)
target_compile_definitions(HydroModelsGUI PRIVATE _UNICODE)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

target_compile_features(HydroModelsGUI PUBLIC cxx_std_17)
set_target_properties(HydroModelsGUI PROPERTIES CXX_EXTENSIONS OFF)

# include libs
target_link_libraries(HydroModelsGUI PRIVATE HydroModels2)
# setup wxwidgets
if(NOT (DEFINED "ENV{CPP_LIBS}"))
    message (FATAL_ERROR  "Couldnt find cpp libs on env variable")
endif()

set(wxdir "$ENV{CPP_LIBS}/wx313")
set(wx_lib  "${wxdir}/lib/vc_x64_lib")
set(wx_include "${wxdir}/include/msvc" "${wxdir}/include")
target_include_directories(HydroModelsGUI PRIVATE "${wx_include}")
target_link_directories(HydroModelsGUI PRIVATE "${wx_lib}")

# copy after build
add_custom_command(TARGET HydroModelsGUI POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_if_different
               "${CMAKE_CURRENT_SOURCE_DIR}/../HydroModels2/vendor/antlr4/lib/x64/Release_DLL/antlr4-runtime.dll"
                "${CMAKE_CURRENT_BINARY_DIR}/Release"
)
add_custom_command(TARGET HydroModelsGUI POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_if_different
               "${CMAKE_BINARY_DIR}/HydroModels2/Release/HydroModels2.dll"
                "${CMAKE_CURRENT_BINARY_DIR}/Release"
)