cmake_minimum_required(VERSION 4.0)
project(TADs)

set(CMAKE_CXX_STANDARD 20)

add_executable(TADs main.cpp
        Biblioteca/FuncionesAdicionales.cpp
        Biblioteca/FuncionesAdicionales.h
        Biblioteca/Curso.h
        Biblioteca/Escala.h
        Biblioteca/Alumno.h
        Biblioteca/Nodo.h)
