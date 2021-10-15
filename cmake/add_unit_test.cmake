macro(add_unit_test name source)
    add_executable(${name} 
                   ${source}
                  )

    # Currently no spmv library for linking
    #target_link_libraries(${name} spmv)
    target_link_directories(${name} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)
    
    add_test(NAME ${name}
             COMMAND ${name}
             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            )

endmacro(add_unit_test)
