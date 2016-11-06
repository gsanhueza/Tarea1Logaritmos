cmake_minimum_required(VERSION 2.6)
project(r_trees_cpp)

add_executable(r_trees_cpp main.cpp Node.cpp Rectangle.cpp)

install(TARGETS r_trees_cpp RUNTIME DESTINATION bin)
