cmake_minimum_required(VERSION 4.2)
project(Lab10_2022_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab10_2022_2 main.cpp
        Bibliotecas/Medicamento.cpp
        Bibliotecas/Medicamento.h
        Bibliotecas/Generico.cpp
        Bibliotecas/Generico.h
        Bibliotecas/Marca.cpp
        Bibliotecas/Marca.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Arbol.cpp
        Bibliotecas/Arbol.h
        Bibliotecas/Almacen.cpp
        Bibliotecas/Almacen.h
)
