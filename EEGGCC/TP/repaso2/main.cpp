#include <iomanip>
#include <iostream>
using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main(int argv, char** argc)
{
    int frecuencia, canales, bits, duracion;
    double prueba;

    cin >> frecuencia;
    prueba = transformarBinario(frecuencia);
    cout << fixed << setprecision(0) << prueba << endl;
    prueba = transformarBaseDiez(prueba);
    cout << fixed << setprecision(0) << prueba << endl;

    return 0;
}