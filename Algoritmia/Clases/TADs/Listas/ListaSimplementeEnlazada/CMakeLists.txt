cmake_minimum_required(VERSION 4.2)
project(ListaSimplementeEnlazada)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaSimplementeEnlazada main.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h
        Biblioteca/Lista.h
        Biblioteca/Nodo.h
        Biblioteca/Elemento.h)
