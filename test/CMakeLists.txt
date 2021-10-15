hello("${CMAKE_CURRENT_BINARY_DIR}")
project(test)

set(${PROJECT_NAME}_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# test_hello
# TODO: Create CMake Module to help set these up?
set(TESTNAME ${PROJECT_NAME}_hello)
add_executable(${TESTNAME} hello_test.cpp)
target_link_libraries(${TESTNAME} PRIVATE ${CMAKE_PROJECT_NAME})
add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
set_tests_properties(${TESTNAME} PROPERTIES
  PASS_REGULAR_EXPRESSION "^Hello World!\n$"
)
