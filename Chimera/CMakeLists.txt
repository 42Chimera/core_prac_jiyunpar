cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME Chimera)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# 헤더 파일 디렉토리 포함
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)