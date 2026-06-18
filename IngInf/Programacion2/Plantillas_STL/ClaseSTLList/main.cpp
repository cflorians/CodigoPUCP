#include <iostream>
#include <algorithm>
#include <fstream>
#include <list>
#include <string>
using namespace std;

#include "Biblioteca/Alumno.h"

int main(int argc, char** argv) {

    list<string> frutas;
    frutas.push_back("Manzana");
    frutas.push_back("Pera");
    frutas.push_back("Platano");
    frutas.push_front("Arandano");
    frutas.push_front("Papaya");

    for (string fruta : frutas) cout << fruta << " ";
    cout << endl;

    cout << "Tamano: " << frutas.size() << endl;

    // recorremos la lista en orden inverso
    auto it = frutas.end();
    while (true) {
        it--; // IMPORTANTE REDUCIR ANTES DE MOSTRAR PORQUE .end() ES EL DATO FINAL +1
        cout << *it << " ";
        if (it == frutas.begin()) break;
    }
    cout << endl << endl;

    string primero, ultimo;
    primero = frutas.front();
    ultimo = frutas.back();

    // preparar la lectura
    list<Alumno> alumnos;
    // aperturar archivo
    ifstream arch("Archivos/", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    Alumno alumno;
    while (true) {
        arch >> alumno;
        if (arch.eof()) break;
        alumnos.push_back(alumno);
    }

    // Como se ordena
    alumnos.sort(); // Elegimos el orden usando la sobrecarga de < en la clase



    return 0;
}
