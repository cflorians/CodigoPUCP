#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char* argv[])
{
    ifstream archDatos("ArchivosDeDatos/productos.txt", ios::in);
    ofstream archReporte("ArchivosDeReporte/reporte.txt", ios::out);

    while (archDatos.peek() != EOF)
    {
        archReporte << "Producto:" << setw(3) << ' ';
        leerNumero(archDatos, archReporte);
        archReporte << "Precio:" << setw(3) << ' ';
        leerNumero(archDatos, archReporte);
        archReporte << endl;
    }

    archDatos.close();
    archReporte.close();

    return 0;
}