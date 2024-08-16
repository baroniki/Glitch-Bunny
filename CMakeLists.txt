cmake_minimum_required(VERSION 3.22)

project(JuceWorkflow)

set(CMAKE_CXX_STANDARD 20)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
include(cmake/cpm.cmake)

# Includes for juceaid
include_directories(    /usr/include/freetype2  
                        /usr/local/include/freetype2  
                        /usr/include/libpng16
)

CPMAddPackage(
    NAME JUCE
    GITHUB_REPOSITORY juce-framework/JUCE
    GIT_TAG 8.0.1
    VERSION v8.0.1
    SOURCE_DIR ${LIB_DIR}/juce
)

CPMAddPackage(
    NAME GOOGLETEST
    GITHUB_REPOSITORY google/googletest
    VERSION 1.14.0
    SOURCE_DIR ${LIB_DIR}/googletest
    OPTIONS
        "INSTALL_GTEST OFF"
        "gtest_forced_shared_crt ON"
)

enable_testing()

if(MSVC)
    add_compile_options(/Wall /Wx)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(plugin)
add_subdirectory(test)