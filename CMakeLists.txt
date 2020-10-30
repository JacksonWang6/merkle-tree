cmake_minimum_required(VERSION 3.17)
project(bigdata_lab3 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
add_executable(bigdata_lab3 main.c sha256.c sha256.h mttree.c mttree.h queue.c queue.h)