#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[])
{
    int codPais;
    int edad, dni;

    ifstream datos("ArchivosDeDatos/codigos_paises.txt", ios::in);
    ofstream salida("ArchivosDeReporte/reporte.txt", ios::out);

    if (!datos.is_open() or !salida.is_open())
    {
        cout << "Error al abrir el archivo de datos" << endl;
        exit(1);
    }

    while (datos >> codPais)
    {
        salida << codPais;
        leerTexto(datos, salida);
        salida << endl;
        obtenerDnis(codPais, dni, edad, datos, salida);
    }


    datos.close();
    salida.close();

    return 0;
}