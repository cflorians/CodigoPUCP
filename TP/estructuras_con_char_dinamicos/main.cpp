#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/Estructuras.h"
#include "Bibliotecas/FuncionesAdicionales.h"

int main(int argc, char *argv[]) {

    struct Persona empleados[10];
    int cantEmpleados;

    leerEmpleados(empleados, cantEmpleados);
    ordenarPorDni(empleados, cantEmpleados);
    mostrar(empleados, cantEmpleados);

    ordenarPorSueldo(empleados, cantEmpleados);
    mostrar(empleados, cantEmpleados);

    return 0;
}
