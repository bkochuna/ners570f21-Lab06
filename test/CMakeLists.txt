hello("${CMAKE_CURRENT_BINARY_DIR}")

#Set include directories for executables
include_directories(../src)

#Define test executable
add_executable(testSparseMatrix
               testSparseMatrix.cpp
              )

#Specify link options for executable (what directories and where)
target_link_libraries(testSparseMatrix spmv)
target_link_directories(testSparseMatrix PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)

# Declare test and have it run test executable
add_test(NAME testSparseMatrix_test
         COMMAND testSparseMatrix
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )

# Set additional pass/fail conditions for test, other than return code
#set_tests_properties(testSparseMatrix_test PROPERTIES
#    PASS_REGULAR_EXPRESSION "Called SparseMatrix Constructor"
#)
# COMMENTING THESE OUT SINCE WE ARE NO LONGER PRINTING THESE IN THE CONSTRUCTOR
# LEAVING IT AS AN EXAMPLE FOR HOW TO DO IT

add_unit_test(test_example)
add_unit_test(test_another_example)

