cmake_minimum_required(VERSION 4.2)
project(Colas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Colas main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
        Bibliotecas/Elemento.h
        Bibliotecas/Nodo.h
        Bibliotecas/Cola.h
)
