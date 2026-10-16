#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define MAX_NUMEROS 50

#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[]) {

    int arrNumeros[MAX_NUMEROS]{}, cantDatos, pos, numero;
    ifstream arch;
    ofstream reporte;

    abrirArchivos(arch, "ArchivosDeDatos/datos.txt");
    abrirArchivos(reporte, "ArchivosDeReporte/reporte.txt");

    cargarDatos(arch, arrNumeros, cantDatos);
    reporte << "ARREGLO ORIGINAL: " << endl;
    mostrarArreglo(reporte, arrNumeros, cantDatos);

    ordenarArreglo(arrNumeros, cantDatos);
    reporte << endl << "ARREGLO ORDENADO: " << endl;
    mostrarArreglo(reporte, arrNumeros, cantDatos);

    invertirArreglo(arrNumeros, cantDatos);
    reporte << endl << "ARREGLO INVERTIDO: " << endl;
    mostrarArreglo(reporte, arrNumeros, cantDatos);

    // invertirArreglo(arrNumeros, cantDatos);
    // cout << "INGRESE EL NUMERO A BUSCAR: " << endl;
    // cin >> numero;
    // pos = buscarNumero(numero, arrNumeros, cantDatos);
    // reporte << endl << "EL NUMERO " << arrNumeros[pos] << " ESTA EN LA POSICION " << pos+1 << endl;

    cargarOrdenado(arch, arrNumeros, cantDatos);
    reporte << endl << "EL ARREGLO CARGADO Y ORDENADO ES: " << endl;
    mostrarArreglo(reporte, arrNumeros, cantDatos);

    return 0;
}