#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Biblioteca/CadenaDeCaracteres.h"
#include "Biblioteca/MisFunciones.h"

int main(int argc, char** argv) {
    
    ifstream arch("Archivos/Infracciones_de_transito.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo Infracciones_de_transito.txt" << endl;
        exit(1);
    }
    int* dni;
    struct CadenaDeCaracteres* conductor = nullptr;
    struct CadenaDeCaracteres* placa = nullptr;
    ofstream reporte("Reportes/reporte.txt", ios::out);

    leerArchivo(arch, dni,  conductor, placa);
    emitirReporte(reporte, dni, conductor, placa);
    
    return 0;
}
