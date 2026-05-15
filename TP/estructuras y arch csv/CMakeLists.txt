cmake_minimum_required(VERSION 4.0)
project(estructuras_y_arch_csv)

set(CMAKE_CXX_STANDARD 20)

add_executable(estructuras_y_arch_csv main.cpp
        Bibliotecas/FuncionesAdicionales.cpp
        Bibliotecas/FuncionesAdicionales.h
        Bibliotecas/Estructuras.h)
