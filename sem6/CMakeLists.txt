project(sem6)

single_executable(src/iterators.cpp)
single_executable(src/algorithms.cpp)

single_executable(src/sequence/array.cpp)
single_executable(src/sequence/vector.cpp)
single_executable(src/sequence/deque.cpp)
single_executable(src/sequence/list.cpp)
single_executable(src/sequence/forward_list.cpp)

single_executable(src/associative/map.cpp)
single_executable(src/associative/unordered_map.cpp)
single_executable(src/associative/set.cpp)
single_executable(src/associative/unordered_set.cpp)

single_executable(src/associative/multi/multimap.cpp)
single_executable(src/associative/multi/unordered_multimap.cpp)
single_executable(src/associative/multi/multiset.cpp)
single_executable(src/associative/multi/unordered_multiset.cpp)

single_executable(src/adapters/stack.cpp)
single_executable(src/adapters/queue.cpp)
single_executable(src/adapters/priority_queue.cpp)
