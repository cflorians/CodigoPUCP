cmake_minimum_required(VERSION 4.2)
project(ArbolBinario)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolBinario main.cpp
        Biblioteca/Elemento.h
        Biblioteca/Nodo.h
        Biblioteca/Arbol.h
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h
        BibliotecaCola/Cola.h
        BibliotecaCola/Funciones.cpp
        BibliotecaCola/Funciones.h
        BibliotecaCola/Nodo.h
        BibliotecaCola/Cola.h
        BibliotecaCola/Funciones.cpp
        BibliotecaCola/Funciones.h
        BibliotecaCola/Nodo.h
)
