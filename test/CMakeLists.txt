hello("${CMAKE_CURRENT_BINARY_DIR}")
project(test)

set(${PROJECT_NAME}_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_unit_test(test_example)
add_unit_test(test_another_example)
