cmake_minimum_required(VERSION 4.0)
project(estructuras_con_char_dinamicos)

set(CMAKE_CXX_STANDARD 20)

add_executable(estructuras_con_char_dinamicos main.cpp
        Bibliotecas/FuncionesAdicionales.cpp
        Bibliotecas/FuncionesAdicionales.h
        Bibliotecas/Estructuras.h)
