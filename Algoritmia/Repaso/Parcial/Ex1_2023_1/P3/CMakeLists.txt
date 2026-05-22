cmake_minimum_required(VERSION 4.2)
project(P3)

set(CMAKE_CXX_STANDARD 20)

add_executable(P3 main.cpp
        Bibliotecas/Elemento.h
        Bibliotecas/Nodo.h
        Bibliotecas/Lista.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h)
