project(PointArray)

as_library()

project_link_projects(Point)
include_projects_directories(Point)

with_test(PointArray gtest_main)