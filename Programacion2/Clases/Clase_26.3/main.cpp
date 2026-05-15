#include <iostream>
using namespace std;

#include "Bibliotecas/ListaPedidos.h"
#include "Bibliotecas/funciones.h"

using namespace std;

int main(int argc, char** argv) {
    ListaPedidos lista{};

    //leer todos los pedidos usando operadores sobrecargados
    lista >> "Archivos/pedidos.csv";

    "Reportes/reporte.txt" << lista;

    return 0;
}