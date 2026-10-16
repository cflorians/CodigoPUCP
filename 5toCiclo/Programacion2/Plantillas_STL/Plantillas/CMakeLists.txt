cmake_minimum_required(VERSION 4.2)
project(Plantillas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Plantillas main.cpp
        Biblioteca/miPlantilla.h
        Biblioteca/Plantilla.cpp
        Biblioteca/Plantilla.h
        Biblioteca/Persona.cpp
        Biblioteca/Persona.h
)
