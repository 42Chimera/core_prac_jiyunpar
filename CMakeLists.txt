cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Chimera_PJT)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)
set(DEP_LIST)
set(DEP_LIBS)

if(APPLE)
	INCLUDE_DIRECTORIES(/System/Library/Frameworks)
	FIND_LIBRARY(COCOA_LIBRARY Cocoa)
	FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
	FIND_LIBRARY(IOKit_LIBRARY IOKit)
	FIND_LIBRARY(CoreVideo_LIBRARY CoreVideo)
	MARK_AS_ADVANCED(COCOA_LIBRARY OpenGL_LIBRARY)
	SET(DEP_LIBS ${COCOA_LIBRARY} ${IOKit_LIBRARY} ${OpenGL_LIBRARY} ${CoreVideo_LIBRARY})
endif(APPLE)

include(Dependency.cmake)

add_subdirectory(Chimera)
add_subdirectory(App)

add_dependencies(Chimera ${DEP_LIST})
add_dependencies(App ${DEP_LIST})