cmake_minimum_required(VERSION 3.10)

project(SpMV VERSION 0.1.0)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(hello)
include(add_unit_test)

hello("Some directory")

if(NOT DEFINED SpMV_ENABLE_TESTING)
    set(SpMV_ENABLE_TESTING ON)
endif()

add_subdirectory(src)

if(SpMV_ENABLE_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
