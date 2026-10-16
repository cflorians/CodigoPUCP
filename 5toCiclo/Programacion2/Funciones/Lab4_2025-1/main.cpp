#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/BibliotecaGenerica.h"

int main(int argc, char** argv) {
    
    void* lista;

    crearLista(lista, leerNumero, clasificaEntero, "Archivos/numeros2.txt");
    imprimeLista(lista, imprimenum, "Reportes/Repnum.txt");

    crearLista(lista, leeregistro, clasificaregistro, "Archivos/RegistroDeFaltas1.csv");
    imprimeLista(lista, imprimeregistro, "Reportes/Repfalta.txt");
    
    return 0;
}
