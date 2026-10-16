cmake_minimum_required(VERSION 4.2)
project(Lab9_2023_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab9_2023_1 main.cpp
        Bibliotecas/Alumno.cpp
        Bibliotecas/Alumno.h
        Bibliotecas/Escala.cpp
        Bibliotecas/Escala.h
        Bibliotecas/Presencial.cpp
        Bibliotecas/Presencial.h
        Bibliotecas/Semipresencial.cpp
        Bibliotecas/Semipresencial.h
        Bibliotecas/Virtual.cpp
        Bibliotecas/Virtual.h
        Bibliotecas/Boleta.cpp
        Bibliotecas/Boleta.h
        Bibliotecas/Tesoreria.cpp
        Bibliotecas/Tesoreria.h)
