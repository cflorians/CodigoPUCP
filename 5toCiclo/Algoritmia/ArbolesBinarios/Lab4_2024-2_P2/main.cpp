#include <iostream>
using namespace std;

#include "Bibliotecas/Arbol.h"
#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {

    Arbol almacen;

    construir(almacen);

    ingresaLote(almacen, {2018,100});
    ingresaLote(almacen, {2011,150});
    ingresaLote(almacen, {2022,50});
    ingresaLote(almacen, {2010,175});
    ingresaLote(almacen, {2017,25});
    ingresaLote(almacen, {2019,125});
    ingresaLote(almacen, {2023,200});
    ingresaLote(almacen, {2020,75});

    imprimir(almacen);

    return 0;
}
