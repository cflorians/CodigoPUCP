cmake_minimum_required(VERSION 4.2)
project(ListaClase)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaClase main.cpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Lista.cpp
        Bibliotecas/Lista.h
        Bibliotecas/Persona.cpp
        Bibliotecas/Persona.h)
