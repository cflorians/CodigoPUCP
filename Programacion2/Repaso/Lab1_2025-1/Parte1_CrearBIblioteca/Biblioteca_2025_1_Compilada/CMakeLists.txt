cmake_minimum_required(VERSION 4.2)
project(Biblioteca_2025_1_Compilada)

set(CMAKE_CXX_STANDARD 20)

add_library(BibliotecaEstatica Bibliotecas/Funciones.cpp)

add_executable(Biblioteca_2025_1_Compilada main.cpp)

target_link_libraries(Biblioteca_2025_1_Compilada BibliotecaEstatica)