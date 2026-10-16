cmake_minimum_required(VERSION 4.2)
project(P2_Ex1_2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2_Ex1_2025_1 main.cpp
        Bibliotecas/Elemento.h
        Bibliotecas/Nodo.h
        Bibliotecas/Lista.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
        BibliotecaCola/Elemento.h
        BibliotecaCola/Nodo.h
        BibliotecaCola/Cola.h
        BibliotecaCola/Funciones.cpp
        BibliotecaCola/Funciones.h)
