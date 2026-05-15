#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#include "Bibliotecas/Estructuras.h"

int main(int argc, char *argv[]) {
    struct Nodo* lista = nullptr;

    leerDatos(lista);
    mostrarLista(lista);

    return 0;
}