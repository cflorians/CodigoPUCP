cmake_minimum_required(VERSION 4.2)
project(Lab5_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab5_2024_2 main.cpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.h
        Bibliotecas/ListaConEnteros.cpp
        Bibliotecas/ListaConEnteros.h
        Bibliotecas/ListaConRegistros.cpp
        Bibliotecas/ListaConRegistros.h)
