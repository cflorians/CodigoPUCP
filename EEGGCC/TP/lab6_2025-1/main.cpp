#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#define MAX_MULTAS 150
#define MAX_INFRACCIONES 700

int main(int argc, char const *argv[]) {

    int arrCodigoInfraccion[MAX_MULTAS]{}, cantInfracciones;
    double arrMultasInfraccion[MAX_MULTAS]{};
    int arrDni[MAX_INFRACCIONES]{}, arrMasMultaAntigua[MAX_INFRACCIONES]{}, arrUltimaPendiente[MAX_INFRACCIONES]{};
    double arrTotalMutacion[MAX_INFRACCIONES]{}, arrTotalPagadas[MAX_INFRACCIONES]{}, arrTotalPendientes[MAX_INFRACCIONES]{};

    leerTablaInfracciones(arrCodigoInfraccion, arrMultasInfraccion, cantInfracciones);
    verificarCorrectoLlenadoDatos(arrCodigoInfraccion, arrMultasInfraccion, cantInfracciones);


    return 0;
}