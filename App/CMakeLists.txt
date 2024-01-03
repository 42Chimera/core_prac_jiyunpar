cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME App)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC CM_PLATFORM_WINDOWS CM_BUILD_DLL)
elseif(APPLE)
    target_compile_definitions(${PROJECT_NAME} PUBLIC CM_PLATFORM_MACOS)
endif()

target_link_libraries(${PROJECT_NAME} Chimera)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Chimera)

