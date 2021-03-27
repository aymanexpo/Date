cmake_minimum_required(VERSION 3.15)
project(Date)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SRC src)

add_executable(date main.cpp ${SRC}/Date.cpp)
