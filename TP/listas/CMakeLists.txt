cmake_minimum_required(VERSION 4.0)
project(listas)

set(CMAKE_CXX_STANDARD 20)

add_executable(listas main.cpp
        Bibliotecas/FuncionesAdicionales.cpp
        Bibliotecas/FuncionesAdicionales.h
        Bibliotecas/Estructuras.h)
