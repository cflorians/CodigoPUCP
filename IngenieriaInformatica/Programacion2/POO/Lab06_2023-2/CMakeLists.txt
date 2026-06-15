cmake_minimum_required(VERSION 4.2)
project(Lab06_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab06_2023_2 main.cpp
        Bibliotecas/ProductoEntregado.cpp
        Bibliotecas/ProductoEntregado.h
        Bibliotecas/Cliente.cpp
        Bibliotecas/Cliente.h
        Bibliotecas/Producto.cpp
        Bibliotecas/Producto.h
        Bibliotecas/Pedido.cpp
        Bibliotecas/Pedido.h
        Bibliotecas/Almacen.cpp
        Bibliotecas/Almacen.h)
