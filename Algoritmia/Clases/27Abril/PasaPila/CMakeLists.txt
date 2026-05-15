cmake_minimum_required(VERSION 4.2)
project(PasaPila)

set(CMAKE_CXX_STANDARD 20)

add_executable(PasaPila main.cpp
            Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h
        Biblioteca/Elemento.h
        Biblioteca/Nodo.h
        Biblioteca/Pila.h)
