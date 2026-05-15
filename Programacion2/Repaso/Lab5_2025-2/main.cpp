#include <iostream>
#include <fstream>
using namespace std;

#include "Biblioteca/Gestor.h"

#include "Biblioteca/Funciones.h"
#include "Biblioteca/Streamer.h"

int main(int argc, char** argv) {

    GestorStreamers gestor;

    gestor.mostrarMenu();

    return 0;
}
