
cmake_minimum_required(VERSION 3.24.0)

project(sort
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# add the executable
add_executable(test tests/test.cpp src/sort.cpp src/utils.cpp)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)


