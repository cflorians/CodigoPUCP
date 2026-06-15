cmake_minimum_required(VERSION 4.2)
project(2023_1_E1)

set(CMAKE_CXX_STANDARD 20)

add_executable(2023_1_E1 main.cpp
        BibliotecaPila/Funciones.cpp
        BibliotecaPila/Funciones.h
        BibliotecaPila/Elemento.h
        BibliotecaPila/Nodo.h
        BibliotecaPila/Pila.h
)
