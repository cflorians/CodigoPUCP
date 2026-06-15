cmake_minimum_required(VERSION 4.2)
project(ArbolABB)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolABB main.cpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Arbol.cpp
        Bibliotecas/Arbol.h
        Bibliotecas/Persona.cpp
        Bibliotecas/Persona.h)
