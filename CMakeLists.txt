cmake_minimum_required(VERSION 3.8)

project(cpp)

set(CMAKE_CXX_STANDARD 14)

include(cmake/Core.cmake)
include(cmake/DownloadProject.cmake)

download_project(
        PROJ           googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

add_subdirectory(sem1)
add_subdirectory(sem2)
add_subdirectory(sem3)
add_subdirectory(task1)
add_subdirectory(Point)
add_subdirectory(PointArray)
add_subdirectory(CyclicQueue)
