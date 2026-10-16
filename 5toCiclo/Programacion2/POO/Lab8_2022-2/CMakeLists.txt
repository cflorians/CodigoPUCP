cmake_minimum_required(VERSION 4.2)
project(Lab8_2022_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab8_2022_2 main.cpp
        Bibliotecas/Medico.cpp
        Bibliotecas/Medico.h
        Bibliotecas/Medicamentos.cpp
        Bibliotecas/Medicamentos.h
        Bibliotecas/ConReceta.cpp
        Bibliotecas/ConReceta.h
        Bibliotecas/SinReceta.cpp
        Bibliotecas/SinReceta.h
        Bibliotecas/Farmacia.cpp
        Bibliotecas/Farmacia.h)
