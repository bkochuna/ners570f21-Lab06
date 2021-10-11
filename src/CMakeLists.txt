hello("${CMAKE_CURRENT_SOURCE_DIR}")

# Declare a target library and associated sources
add_library(spmv
             hello.cpp
           )
