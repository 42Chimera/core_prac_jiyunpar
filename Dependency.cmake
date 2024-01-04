# ExternalProject 관련 명령어 셋 추가
include(ExternalProject)

# spdlog: fast logger library
ExternalProject_Add(
    dep_spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.x"
    GIT_SHALLOW 1
    UPDATE_COMMAND "" 
    TEST_COMMAND "" 
    PATCH_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
    )
# Dependency 리스트 및 라이브러리 파일 리스트 추가
set(DEP_LIST ${DEP_LIST} dep_spdlog)

# os에 따라 생성되는 라이브러리 이름이 다르기 때문에 설정 필요
if(APPLE)
  #mac 에서는 config가 디버그 모드여도음라이브러리 뒤에 d가 안붙음
  set(DEP_LIBS ${DEP_LIBS} spdlog)
elseif(WIN32)
  set(DEP_LIBS ${DEP_LIBS} spdlog$<$<CONFIG:Debug>:d>) 
endif()