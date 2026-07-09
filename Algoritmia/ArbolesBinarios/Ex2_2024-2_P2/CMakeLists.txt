cmake_minimum_required(VERSION 4.2)
project(Ex2_2024_2_P2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ex2_2024_2_P2 main.cpp
        BibliotecaArbol/Elemento.h
        BibliotecaArbol/Nodo.h
        BibliotecaArbol/Arbol.h
        BibliotecaArbol/Funciones.cpp
        BibliotecaArbol/Funciones.h
)
