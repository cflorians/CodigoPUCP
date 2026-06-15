cmake_minimum_required(VERSION 4.2)
project(ListasEnlazadas)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListasEnlazadas main.cpp
        Bibliotecas/Listas.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
)
