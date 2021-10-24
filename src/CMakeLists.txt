hello("${CMAKE_CURRENT_SOURCE_DIR}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Declare a target library and associated sources
add_library(spmv
             SparseMatrix.cpp
             COO.cpp
             BCRS.cpp
             ELLPACK.cpp
           )
