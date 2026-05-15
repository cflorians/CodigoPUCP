cmake_minimum_required(VERSION 4.2)
project(EjercicioLista)

set(CMAKE_CXX_STANDARD 20)

add_executable(EjercicioLista main.cpp
        Bibliotecas/Elemento.h
        Bibliotecas/Lista.h
        Bibliotecas/Nodo.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h)
