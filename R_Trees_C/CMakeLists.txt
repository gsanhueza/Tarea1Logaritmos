cmake_minimum_required(VERSION 3.6)
project(R_Trees_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.c
    rectangle.c
    rectangle.h
        )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/rodrigo/Documents/Algoritmos/Tarea1Logaritmos/R_Trees_C/")
set(CMAKE_RUNTIME_INPUT_DIRECTORY "/home/rodrigo/Documents/Algoritmos/Tarea1Logaritmos/R_Trees_C")

add_executable(R_Trees_C ${SOURCE_FILES})