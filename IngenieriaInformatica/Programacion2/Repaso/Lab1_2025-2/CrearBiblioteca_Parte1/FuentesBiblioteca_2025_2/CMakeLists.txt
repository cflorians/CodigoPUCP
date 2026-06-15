cmake_minimum_required(VERSION 4.2)
project(FuentesBiblioteca_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_library(MisFunciones STATIC Bibliotecas/Funciones.cpp)

add_executable(FuentesBiblioteca_2025_2 main.cpp)

target_link_libraries(FuentesBiblioteca_2025_2 MisFunciones)
