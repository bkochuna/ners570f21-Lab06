hello("${CMAKE_CURRENT_BINARY_DIR}")

#Set include directories for executables
include_directories(../src)

#Define test executable
add_executable(testHello
               testHello.cpp
              )

#Specify link options for executable (what directories and where)
target_link_libraries(testHello spmv)
target_link_directories(testHello PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)

# Declare test and have it run test executable
add_test(NAME testHello_test
         COMMAND testHello
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )

# Set additional pass/fail conditions for test, other than return code
set_tests_properties(testHello_test PROPERTIES
    PASS_REGULAR_EXPRESSION "Called SparseMatrix Constructor"
    PASS_REGULAR_EXPRESSION "Called SparseMatrix Destructor"
)
