cmake_minimum_required(VERSION 4.2)
project(Ex2_2024_2_P3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ex2_2024_2_P3 main.cpp
        BibliotecaArbol/ArbolBinario.h
        BibliotecaArbol/Elemento.h
        BibliotecaArbol/FuncionesAB.cpp
        BibliotecaArbol/FuncionesAB.h
        BibliotecaArbol/Nodo.h
        BibliotecaCola/Cola.h
        BibliotecaCola/Elemento.h
        BibliotecaCola/Funciones.cpp
        BibliotecaCola/Funciones.h
        BibliotecaCola/Nodo.h
        BibliotecaPila/Elemento.h
        BibliotecaPila/Funciones.cpp
        BibliotecaPila/Funciones.h
        BibliotecaPila/Nodo.h
        BibliotecaPila/Pila.h)
