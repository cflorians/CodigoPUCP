#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Bibliotecas/funciones.h"

int main(int argc, char** argv) {
    int* datos, numDatos;
    //Con numero de datos
    // leerDatosPorIncrementos(datos, numDatos, "Archivos/datos.txt");
    // imprimirDatos(datos, numDatos, "Reportes/reporteNumDatos.txt");
    //
    // //Sin numero de datos
    leerDatosPorIncrementos(datos, "Archivos/datos.txt");
    for (int i=0; datos[i] ; i++) {
        cout << datos[i] << endl;
    }
    // imprimirDatos(datos, "Reportes/reporteSinNumDatos.txt");

    return 0;
}