cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Chimera_PJT)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)
set(DEP_LIST)
set(DEP_LIBS)

include(Dependency.cmake)

add_subdirectory(Chimera)
add_subdirectory(App)

add_dependencies(Chimera ${DEP_LIST})
add_dependencies(App ${DEP_LIST})