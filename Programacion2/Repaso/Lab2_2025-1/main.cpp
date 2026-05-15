#include <iostream>
using namespace std;

#include "Bibliotecas/Faltas.h"
#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    Faltas faltas{};

    cargar_faltas_de_los_conductores(faltas);

    
    return 0;
}
