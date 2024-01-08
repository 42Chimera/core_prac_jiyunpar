cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Chimera)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# macros for platfrom
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC CM_PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(${PROJECT_NAME} PUBLIC CM_PLATFORM_MACOS)
endif()

# link library
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

#precompiled header
target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h)

# 헤더 파일 디렉토리 포함
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${DEP_INCLUDE_DIR})