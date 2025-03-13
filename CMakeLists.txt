cmake_minimum_required(VERSION 3.0.2)
project(single_instance_test)

# set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_STANDARD 11)
# find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread") # very important

add_executable(ins_test_1 ins_test_1.cpp)
target_link_libraries(ins_test_1 pthread)

add_executable(ins_test_2 ins_test_2.cpp)

add_executable(ins_test_3 ins_test_3.cpp)
target_link_libraries(ins_test_3 pthread)