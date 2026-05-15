cmake_minimum_required(VERSION 4.0)
project(tokenizar)

set(CMAKE_CXX_STANDARD 20)

add_executable(tokenizar main.cpp
        Bibliotecas/FuncionesAdicionales.cpp
        Bibliotecas/FuncionesAdicionales.h
        Bibliotecas/Estructuras.h)
