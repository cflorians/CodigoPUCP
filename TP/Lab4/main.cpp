#include <iostream>
#include <iomanip>
#include <fstream>
#include "Bibliotecas/FuncionesAdicionales.h"
using namespace std;
#define MAX_DIGITOS 50

int main(int argc, char *argv[])
{
    int numeroGrande1[MAX_DIGITOS]{}, numeroGrande2[MAX_DIGITOS]{}, totalGrande[MAX_DIGITOS]{};

    sumarNumerosMuyGrandes(numeroGrande1, numeroGrande2, totalGrande);

    return 0;
}