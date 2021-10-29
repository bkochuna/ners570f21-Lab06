hello("${CMAKE_CURRENT_SOURCE_DIR}")

set(${PROJECT_NAME}_SRCS
  SparseMatrix.cpp
  COO.cpp
  CRS.cpp
  BCRS.cpp
  ELLPACK.cpp
  JDS.cpp
)

set(${PROJECT_NAME}_LIBS
  coverage_config
)

set(${PROJECT_NAME}_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_LIBS})

target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_INCLUDE_DIRS})

# Only build tests if we are the top-level project
# Allows this to be used by super projects with `add_subdirectory`
if (BUILD_PYTHON)
  pybind11_add_module(${PYTHON_PROJECT_NAME} pythonWrap.cpp)
  target_link_libraries(${PYTHON_PROJECT_NAME} PRIVATE ${PROJECT_NAME})
endif(BUILD_PYTHON)
