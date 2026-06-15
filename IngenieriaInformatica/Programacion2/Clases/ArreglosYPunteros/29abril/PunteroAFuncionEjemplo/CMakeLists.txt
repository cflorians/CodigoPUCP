cmake_minimum_required(VERSION 4.2)
project(PunteroAFuncionEjemplo)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunteroAFuncionEjemplo main.cpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h
        Bibliotecas/Persona.h)
