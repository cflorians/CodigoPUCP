#include <iostream>
using namespace std;

#include "Bibliotecas/Lista.h"
#include "Bibliotecas/Funciones.h"

int main() {

    Lista lista;
    int n = 5;

    construir(lista);

    for (int i = 1; i <= n; i++) insertar(lista,{10*i, true});

    calcular_skip_next(lista);
    imprimir(lista);

    return 0;
}
