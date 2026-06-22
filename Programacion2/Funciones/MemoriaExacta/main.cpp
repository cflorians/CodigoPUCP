#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Bibliotecas/funciones.h"

int main(int argc, char** argv) {

    /* La asignacion exacta
     * Leer los datos en un buffer temporal
     * cuenta cuantos hay
     * crea memoria dinamica exacta de tamaño necesario
     * copia los datos
     * Ventaja: No desperdicia memoria
     */
    // Con número de datos
    int *datos, numDatos;
    leerDatosExactos(datos, numDatos, "Archivos/datos.txt");
    imprimirDatos(datos, numDatos, "Reportes/reporte.txt");

    // Sin número de datos
    leerDatosExactos(datos, "Archivos/datos.txt");
    imprimirDatos(datos, "Reportes/reporteSinNumDatos.txt");

    return 0;
}