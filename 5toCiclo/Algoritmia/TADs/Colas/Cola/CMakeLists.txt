cmake_minimum_required(VERSION 4.2)
project(Cola)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cola main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
        Bibliotecas/Elemento.h
        Bibliotecas/Nodo.h
        Bibliotecas/Cola.h
)
