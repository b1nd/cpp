project(task1)

single_executable(src/1_sum.cpp)
single_executable_link_projects(src/1_sum.cpp gtest_main)

single_executable(src/2_power.cpp)
single_executable_link_projects(src/2_power.cpp gtest_main)

single_executable(src/3_fibonacci.cpp)
single_executable_link_projects(src/3_fibonacci.cpp gtest_main)

single_executable(src/4_prime.cpp)
single_executable_link_projects(src/4_prime.cpp gtest_main)

single_executable(src/5_binary_power.cpp)
single_executable_link_projects(src/5_binary_power.cpp gtest_main)

single_executable(src/6_my_sqrt.cpp)
single_executable_link_projects(src/6_my_sqrt.cpp gtest_main)