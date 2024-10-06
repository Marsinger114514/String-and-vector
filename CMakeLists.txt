cmake_minimum_required(VERSION 3.10)
project(work4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(work4 main.cpp test_string.cpp String.cpp test_vector.cpp)
