cmake_minimum_required(VERSION 4.2)
project(Lab4_2022_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4_2022_2 main.cpp
        Bibliotecas/ArbolBinario.h
        Bibliotecas/Elemento.h
        Bibliotecas/FuncionesAB.cpp
        Bibliotecas/FuncionesAB.h
        Bibliotecas/Nodo.h)
