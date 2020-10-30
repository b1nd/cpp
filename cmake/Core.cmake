function(as_library)
    file(GLOB SOURCE_LIB src/*.cpp)
    add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})
    set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
            CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
    include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})
endfunction()

function(as_executable)
    file(GLOB SOURCE_EXE src/*.cpp)
    add_executable(${PROJECT_NAME} ${SOURCE_EXE})
endfunction()

function(with_test)
    file(GLOB SOURCE_TEST test/*.cpp)
    add_executable(${PROJECT_NAME}_test ${SOURCE_TEST})
    target_link_libraries(${PROJECT_NAME}_test ${ARGN})
endfunction()

function(single_executable)
    list(GET ARGN 0 FILE_NAME)
    file(GLOB SOURCE_EXE ${FILE_NAME})
    get_filename_component(FILE_NAME_WE ${FILE_NAME} NAME_WE)
    add_executable(${PROJECT_NAME}_${FILE_NAME_WE} ${SOURCE_EXE})
endfunction()

function(single_executable_link_projects)
    list(GET ARGN 0 FILE_NAME)
    get_filename_component(FILE_NAME_WE ${FILE_NAME} NAME_WE)
    list(REMOVE_AT ARGN 0)
    target_link_libraries(${PROJECT_NAME}_${FILE_NAME_WE} ${ARGN})
endfunction()

function(project_link_projects)
    target_link_libraries(${PROJECT_NAME} ${ARGN})
endfunction()

function(include_projects_directories)
    set(dirs ${ARGN})
    list(TRANSFORM dirs APPEND _INCLUDE_DIRS)

    set(include_dirs "")
    foreach (dir ${dirs})
        list(APPEND include_dirs ${${dir}})
    endforeach ()

    include_directories(${include_dirs})
endfunction()
