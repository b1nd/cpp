cmake_minimum_required(VERSION 3.8)

project(cpp)

set(CMAKE_CXX_STANDARD 17)

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
add_subdirectory(sem4)
add_subdirectory(sem5)
add_subdirectory(sem6)
add_subdirectory(sem8)
add_subdirectory(task1)
add_subdirectory(task2)
add_subdirectory(task3)
add_subdirectory(task4)
add_subdirectory(Point)
add_subdirectory(PointArray)
add_subdirectory(CyclicQueue)
add_subdirectory(BinaryTree)
add_subdirectory(Timer)
