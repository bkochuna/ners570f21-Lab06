hello("${CMAKE_CURRENT_BINARY_DIR}")

include_directories(../src)

add_unit_test(test_example)
add_unit_test(test_another_example)
