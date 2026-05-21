cmake_minimum_required(VERSION 4.2)
project(P1)

set(CMAKE_CXX_STANDARD 20)

add_executable(P1 main.cpp
        Bibliotecas/Elemento.h
        Bibliotecas/Nodo.h
        Bibliotecas/Pila.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
)
