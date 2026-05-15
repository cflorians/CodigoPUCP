cmake_minimum_required(VERSION 4.1)
project(BibliotecaClase2)

set(CMAKE_CXX_STANDARD 20)

add_library(MisFunciones STATIC Biblioteca/funciones.cpp)

add_executable(BibliotecaClase2 main.cpp)

target_link_libraries(BibliotecaClase2 MisFunciones)

