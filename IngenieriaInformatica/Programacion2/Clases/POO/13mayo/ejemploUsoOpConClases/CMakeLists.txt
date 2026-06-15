cmake_minimum_required(VERSION 4.2)
project(ejemploUsoOpConClases)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejemploUsoOpConClases main.cpp
        Bibliotecas/Sistema.cpp
        Bibliotecas/Sistema.h
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.h
        Bibliotecas/Accesorio.cpp
        Bibliotecas/Accesorio.h
)
