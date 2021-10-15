hello("${CMAKE_CURRENT_BINARY_DIR}")

include_directories(../src)

add_unit_test(test_example test_example.cpp)
add_unit_test(test_another_example test_another_example.cpp)
