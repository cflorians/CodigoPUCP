cmake_minimum_required(VERSION 4.2)
project(ABBusqueda)

set(CMAKE_CXX_STANDARD 20)

add_executable(ABBusqueda main.cpp
        BibliotecaArbolBinarioBusqueda/ArbolBinario.h
        BibliotecaArbolBinarioBusqueda/Elemento.h
        BibliotecaArbolBinarioBusqueda/FuncionesAB.cpp
        BibliotecaArbolBinarioBusqueda/FuncionesAB.h
        BibliotecaArbolBinarioBusqueda/Nodo.h)
