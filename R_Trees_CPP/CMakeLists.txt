cmake_minimum_required(VERSION 2.6)
project(r_trees_cpp)

add_executable(r_trees_cpp main.cpp Rectangle.cpp Rectangle.h RTree.cpp RTree.h)

install(TARGETS r_trees_cpp RUNTIME DESTINATION bin)
