#include <iostream>
using namespace std;

#include "Biblioteca/Gato.h"
#include "Biblioteca/Perro.h"

int main() {

    Gato gato("Dali", 5, 5.6, true);
    // gato.setNombre("Dali");
    // gato.setEdad(5);
    // gato.setPeso(5.6);
    gato.mostrar();

    Perro perro("Rocky", 10, 11.5, true);
    // perro.setNombre("Rocky");
    // perro.setEdad(10);
    // perro.setPeso(11.5);
    perro.mostrar();

    return 0;
}
