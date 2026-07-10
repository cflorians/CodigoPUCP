cmake_minimum_required(VERSION 4.2)
project(Ex2_2024_1_P1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ex2_2024_1_P1 main.cpp
        BibliotecaPila/Elemento.h
        BibliotecaPila/Funciones.cpp
        BibliotecaPila/Funciones.h
        BibliotecaPila/Nodo.h
        BibliotecaPila/Pila.h)
