cmake_minimum_required(VERSION 3.10)

project(SpMV VERSION 0.1.0)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(hello)

hello("Some directory")

# Define default value for config option for testing (default to on)
if(NOT DEFINED SpMV_ENABLE_TESTING)
  set(SpMV_ENABLE_TESTING ON)
endif()

# Process package
add_subdirectory(src)

# Process testing
if(SpMV_ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()


# Packaging support

include(CPack)

set(CPACK_PACKAGE_VENDOR "NERS570")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Sparse Matrix Library developed by NERS 570 class")
set(CPACK_PACKAGE_VERSION_MAJOR ${0.1})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENCE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES
    /.git 
    /\\\\.DS_Store
)
