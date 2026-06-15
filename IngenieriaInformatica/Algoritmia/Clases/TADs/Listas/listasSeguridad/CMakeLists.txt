cmake_minimum_required(VERSION 4.2)
project(listasSeguridad)

set(CMAKE_CXX_STANDARD 20)

add_executable(listasSeguridad main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
        Bibliotecas/Lista.h
        Bibliotecas/Nodo.h
        Bibliotecas/Elemento.h)
