#include <iostream>
#include <iomanip>

#include "Bibliotecas/FuncionesAdicionales.h"
using namespace std;
#define MAX_PRODUCTOS 75

int main(int argc, char *argv[])
{
    //codigo fecha precio cantidad descripcion
    int arrCodigo[MAX_PRODUCTOS]{}, arrCodigoNoRep[MAX_PRODUCTOS]{};
    double arrPrecio[MAX_PRODUCTOS]{}, arrPrecioNoRep[MAX_PRODUCTOS]{}, precioMin, precioMax, precioEncontrado;
    int cantProductos, cantNoRep, codigoBuscado;

    cargarProductos(arrCodigo, arrPrecio, cantProductos);
    //mostrarArreglos(arrCodigo, arrPrecio, cantProductos);
    eliminarRepetidos(arrCodigo, arrPrecio, cantProductos, arrCodigoNoRep, arrPrecioNoRep, cantNoRep);
    ordenarArreglo(arrCodigoNoRep, arrPrecioNoRep, cantNoRep);
    mostrarArreglos(arrCodigoNoRep, arrPrecioNoRep, cantNoRep);
    hallarMinYMax(arrPrecioNoRep, cantNoRep, precioMin, precioMax);
    cin >> codigoBuscado;
    precioEncontrado= buscadorPrecio(codigoBuscado, arrCodigoNoRep, arrPrecioNoRep, cantNoRep);
    if (precioEncontrado != -1)
    {
        cout << "El precio del producto " << codigoBuscado << " es: " << fixed << setprecision(2) << precioEncontrado << endl;
    }

    return 0;
}