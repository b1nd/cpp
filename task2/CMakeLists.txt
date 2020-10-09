project(task2)

single_executable(src/1_power2.cpp)
single_executable_link_projects(src/1_power2.cpp gtest_main)

single_executable(src/2_first_1_bit.cpp)
single_executable_link_projects(src/2_first_1_bit.cpp gtest_main)

single_executable(src/3_invert_bit.cpp)
single_executable_link_projects(src/3_invert_bit.cpp gtest_main)

single_executable(src/4_dec2bin.cpp)
single_executable_link_projects(src/4_dec2bin.cpp gtest_main)

single_executable(src/5_delete_bit.cpp)
single_executable_link_projects(src/5_delete_bit.cpp gtest_main)
