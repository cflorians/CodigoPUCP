#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#include "Biblioteca/Plantilla.h"
#include "Biblioteca/miPlantilla.h"
#include "Biblioteca/Persona.h"


int main(int argc, char** argv) {

    cout << "Suma: " << sumar(3, 6.3) << endl;

    // para manejar la clase
    Plantilla <int> plantilla;
    plantilla.setDato(4);
    // plantilla.leerDato();
    plantilla.imprimirDato();

    Plantilla<string> cadena;
    cadena.setDato("Programacion 3");
    // cadena.leerDato();
    cadena.imprimirDato();

    Plantilla<Persona> personas;
    personas.leerDato();
    personas.imprimirDato();

    return 0;
}
