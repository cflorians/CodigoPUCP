#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#include "Bibliotecas/Estructuras.h"

int main(int argc, char* argv[]) {

    struct Empresa empresas[50];
    int cantEmpresas;

    leerDatos(empresas, cantEmpresas);
    for (int i = 0; i < cantEmpresas; i++) {
        toMayusIniciales(empresas[i].representante);
        toMayus(empresas[i].distrito);
    }

    ordenarPorDistrito(empresas, cantEmpresas);

    mostrarDatos(empresas, cantEmpresas);

    return 0;
}