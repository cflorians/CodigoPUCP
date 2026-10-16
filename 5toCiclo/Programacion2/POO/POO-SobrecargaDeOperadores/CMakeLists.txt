cmake_minimum_required(VERSION 4.2)
project(POO_SobrecargaDeOperadores)

set(CMAKE_CXX_STANDARD 20)

add_executable(POO_SobrecargaDeOperadores main.cpp
        Bibliotecas/Cadena.cpp
        Bibliotecas/Cadena.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
)
