#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[])
{
    ifstream clientes, platos, repartidores, repartos;
    ofstream reporte;
    double totalRecaudado=0, totalAPagar=0;

    abrirArch(clientes, "ArchivosDeDatos/Clientes.txt");
    abrirArch(platos, "ArchivosDeDatos/PlatosOfrecidos.txt");
    abrirArch(repartidores, "ArchivosDeDatos/Repartidores.txt");
    abrirArch(repartos, "ArchivosDeDatos/RepartosARealizar.txt");
    abrirArch(reporte, "ArchivosDeReporte/Reporte.txt");

    //total del pedido sin descuentos
    //descuento por platos suma de descuento de cada plato
    //descuento de cliente sobre el total sin descuentos
    //pago repartidor 10% pedido en moto, 5% en bicicleta
    //total pagado por el cliente es el total sin descuentos menos el descuento por plato menos el descuento de cliente

    emitirTitulo(reporte);
    procesarCliente(clientes, platos, repartidores, repartos, reporte, totalRecaudado, totalAPagar);

    return 0;
}