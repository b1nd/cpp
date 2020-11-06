project(task4)

single_executable(src/1_unique_elements.cpp)
single_executable_link_projects(src/1_unique_elements.cpp gtest_main)

single_executable(src/2_array_intersection.cpp)
single_executable_link_projects(src/2_array_intersection.cpp gtest_main)

single_executable(src/3_delete_most_frequent.cpp)
single_executable_link_projects(src/3_delete_most_frequent.cpp gtest_main)

single_executable(src/4_is_correct_brackets.cpp)
single_executable_link_projects(src/4_is_correct_brackets.cpp gtest_main)

single_executable(src/5_min_window.cpp)
single_executable_link_projects(src/5_min_window.cpp gtest_main)
