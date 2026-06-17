#include <iostream>
#include <vector>
using namespace std;

#include "Biblioteca/Alumno.h"

int main(int argc, char** argv) {

    // ============================================================
    /*
     * VECTOR con enteros y string
     */
    // DECLARACION de vector
    // arreglo de enteros dinamico
    vector<int> numeros;

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);
    numeros.push_back(40);
    numeros.push_back(50);

    // size();
    cout << numeros.size() << endl; // tamaño del arreglo

    for (int num : numeros) cout << num << " ";
    cout << endl << "-------------------------" << endl;
    // -------------------------------------------------
    // DECLARACION del vector con string
    // arreglo de strings dinamicos
    vector<string> nombres;
    // Si asignamos con el indice no funcionara
    // nombres[0] = "Miguel";
    // nombres[1] = "Ana";
    // nombres[2] = "Valentina";
    // nombres[3] = "Naomi";

    //nombres.push_back("Miguel");
    nombres.emplace_back("Miguel");
    nombres.emplace_back("Ana");
    nombres.emplace_back("Valentina");
    nombres.emplace_back("Naomi");

    for (const string& nombre : nombres) cout << nombre << " ";
    cout << endl << "-------------------------" << endl;
    // -------------------------------------------------
    vector<Alumno> alumnos;
    alumnos.emplace_back("Pepito", 15);
    alumnos.emplace_back("Robertito", 17);
    alumnos.emplace_back("Manuelito", 9);

    for (Alumno& alumno : alumnos) alumno.mostrar();
    cout << "-------------------------" << endl;
    // ============================================================

    return 0;
}
