#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/CadenaDeCaracteres.h"

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {

    // struct CadenaDeCaracteres cadena;
    // !cadena;
    // cout << cadena.capacidad << endl;
    //
    // cadena <= "el pepe";
    // cout << cadena.cadena << endl;
    // cout << cadena.capacidad << endl;
    // cout << cadena.longitud << endl;

    struct CadenaDeCaracteres cad1, cad2;
    !cad1;
    !cad2;
    cad1 <= "ESO ";
    cad2 <= "tilin";
    // cad1 <= cad2;
    //
    // cout << cad1.cadena << endl;
    // cout << cad1.longitud << endl;

    cout << (cad1 < cad2) << endl;

    // cad1 += cad2;
    // strlwr(cad1.cadena);
    // cout << cad1.cadena << endl;


    cad1 += cad2;
    cout << cad1.cadena << endl;

    // ifstream arch("Archivos/prueba.txt", ios::in);
    // if (not arch.is_open()) {
    //     cout << "Error al abrir " << endl;
    //     exit(1);
    // }
    //
    // arch >> cad1;
    // cout << cad1.cadena << endl;

    return 0;
}
