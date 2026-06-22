cmake_minimum_required(VERSION 4.2)
project(AB)

set(CMAKE_CXX_STANDARD 20)

add_executable(AB main.cpp
        BibliotecaArbolBinario/Elemento.h
        BibliotecaArbolBinario/Nodo.h
        BibliotecaArbolBinario/ArbolBinario.h
        BibliotecaArbolBinario/FuncionesAB.cpp
        BibliotecaArbolBinario/FuncionesAB.h
)
