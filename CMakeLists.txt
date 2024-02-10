cmake_minimum_required(VERSION 3.16.1)

set(PROJECT_NAME mystring)

project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable(my_string main.cpp my_string.hpp my_string.cpp)