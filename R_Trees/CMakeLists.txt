cmake_minimum_required(VERSION 2.6)
project(r_trees)

add_executable(r_trees main.cpp Rectangle.cpp Rectangle.h RTree.cpp RTree.h)

install(TARGETS r_trees RUNTIME DESTINATION bin)
