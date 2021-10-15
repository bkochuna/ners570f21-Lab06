macro(add_unit_test name)
    add_executable(${name}_float
                   ${name}.cpp
                  )
    add_executable(${name}_double
                   ${name}.cpp
                  )

    # add compilier options for making single/double precision tests
    target_compile_options(${name}_float PRIVATE -DFP_TYPE=float)
    target_compile_options(${name}_double PRIVATE -DFP_TYPE=double)

    # Currently no spmv library for linking
    #target_link_libraries(${name} spmv)
    target_link_directories(${name}_float PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)
    target_link_directories(${name}_double PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)
    
    add_test(NAME ${name}_float
             COMMAND ${name}_float
             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            )

    add_test(NAME ${name}_double
             COMMAND ${name}_double
             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            )
endmacro(add_unit_test)
