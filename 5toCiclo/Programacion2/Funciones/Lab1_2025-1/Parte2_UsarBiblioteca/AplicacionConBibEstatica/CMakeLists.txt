cmake_minimum_required(VERSION 4.2)
project(AplicacionConBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicacionConBibEstatica main.cpp
        Biblioteca/MisFunciones.cpp
        Biblioteca/MisFunciones.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Biblioteca")

target_link_libraries(AplicacionConBibEstatica PRIVATE BibliotecaEstatica)
