cmake_minimum_required(VERSION 4.1)
project(MochilaBasica)

set(CMAKE_CXX_STANDARD 20)

add_executable(MochilaBasica main.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h)
