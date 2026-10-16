cmake_minimum_required(VERSION 4.2)
project(colaIncidentes)

set(CMAKE_CXX_STANDARD 20)

add_executable(colaIncidentes main.cpp
        BibliotecaPila/Funciones.cpp
        BibliotecaPila/Funciones.h
        BibliotecaPila/Nodo.h
        BibliotecaPila/Pila.h

        BibliotecaCola/Cola.h
        BibliotecaCola/Elemento.h
        BibliotecaCola/Funciones.cpp
        BibliotecaCola/Funciones.h
        BibliotecaCola/Nodo.h
        BibliotecaPila/Elemento.h
)
