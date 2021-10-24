hello("${CMAKE_CURRENT_SOURCE_DIR}")

set(${PROJECT_NAME}_SRCS
  SparseMatrix.cpp
  COO.cpp
  BCRS.cpp
  ELLPACK.cpp
)

set(${PROJECT_NAME}_LIBS
  coverage_config
)

set(${PROJECT_NAME}_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_LIBS})

target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_INCLUDE_DIRS})
