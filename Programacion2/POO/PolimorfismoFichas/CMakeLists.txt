cmake_minimum_required(VERSION 4.2)
project(PolimorfismoFichas)

set(CMAKE_CXX_STANDARD 20)

add_executable(PolimorfismoFichas main.cpp
        Bibliotecas/Ficha.cpp
        Bibliotecas/Ficha.h
        Bibliotecas/Alfil.cpp
        Bibliotecas/Alfil.h
        Bibliotecas/Torre.cpp
        Bibliotecas/Torre.h)
