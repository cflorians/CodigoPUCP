#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    
    void *lista = nullptr;
    crearLista(lista, leerDato, compararDato, "Archivos/pacientes.csv");
    
    return 0;
}
