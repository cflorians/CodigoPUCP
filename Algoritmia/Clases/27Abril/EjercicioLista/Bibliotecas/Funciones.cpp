#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Lista.h"
#include "Funciones.h"

void construir(struct Lista& lista) {
    lista.inicio = nullptr;
    lista.longitud = 0;
}
