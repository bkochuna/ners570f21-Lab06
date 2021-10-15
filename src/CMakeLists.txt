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
  # Find python and Boost - both are required dependencies
  find_package(PythonInterp 3)
  find_package(PythonLibs 3 REQUIRED)
  find_package(Boost COMPONENTS python3 REQUIRED)
  # Without this, any build libraries automatically have names "lib{x}.so"
  set(CMAKE_SHARED_MODULE_PREFIX "")

  # Add a shared module - modules are intended to be imported at runtime.
  # - This is where you add the source files
  add_library(${PYTHON_PROJECT_NAME} MODULE pythonWrap.cpp)

  # Set up the libraries and header search paths for this target
  target_link_libraries(${PYTHON_PROJECT_NAME} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${PROJECT_NAME})
  target_include_directories(${PYTHON_PROJECT_NAME} PRIVATE ${PYTHON_INCLUDE_DIRS})

endif(BUILD_PYTHON)
