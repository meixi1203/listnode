cmake_minimum_required(VERSION 3.16)
project(main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(LIST_SRC  ${CMAKE_SOURCE_DIR}/list.cpp)
add_library(mylist SHARED ${LIST_SRC})

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} mylist)

enable_testing()
add_executable(test_node test.cpp)
target_link_libraries(test_node mylist gtest gtest_main -pthread)
add_test(NAME test COMMAND test_node)
