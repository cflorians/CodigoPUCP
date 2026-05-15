#include <iostream>
using namespace std;

#include "Bibliotecas/Sistema.h"

int main(int argc, char** argv) {
    
    class Sistema sistema;

    sistema << "Archivos/datos.txt";
    sistema < "Archivos/accesorios.txt";
    sistema >> "Reportes/salida.txt";

    return 0;
}
