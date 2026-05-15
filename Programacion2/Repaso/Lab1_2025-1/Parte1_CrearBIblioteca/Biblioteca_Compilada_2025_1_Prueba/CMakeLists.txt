cmake_minimum_required(VERSION 4.2)
project(Biblioteca_Compilada_2025_1_Prueba)

set(CMAKE_CXX_STANDARD 20)

add_executable(Biblioteca_Compilada_2025_1_Prueba main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(Biblioteca_Compilada_2025_1_Prueba PRIVATE BibliotecaEstatica)