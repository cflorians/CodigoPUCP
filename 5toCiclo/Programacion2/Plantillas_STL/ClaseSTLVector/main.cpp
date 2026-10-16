#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

    for (int num : numeros) cout << num << " ";
    cout << endl;

    // size();
    cout << "Tamano: " << numeros.size() << endl; // tamaño del arreglo
    // capacidad
    cout << "Capacidad: " << numeros.capacity() << endl;
    // reduce espacios
    cout << "Reduce espacios: " << endl;
    numeros.shrink_to_fit();
    cout << "Capacidad: " << numeros.capacity()  << " Tamano: " << numeros.size() << endl;

    for (int num : numeros) cout << num << " ";
    cout << endl << "-------------------------" << endl;
    // -------------------------------------------------

    // DECLARACION del vector con string
    // arreglo de strings dinamicos
    vector<string> nombres; // con los parentesis asignamos el tamaño
    // Si asignamos con el indice no funcionara, debemos reservar el esepacio primero
    // nombres[0] = "Miguel";
    // nombres[1] = "Ana";
    // nombres[2] = "Valentina";
    // nombres[3] = "Naomi";

    // nombres.push_back("Miguel"); esto funcionara solo si vector ya tiene un espacio asignado
    nombres.emplace_back("Miguel");
    nombres.emplace_back("Ana");
    nombres.emplace_back("Valentina");
    nombres.emplace_back("Naomi");

    for (const string& nombre : nombres) cout << nombre << " ";
    cout << endl << "-------------------------" << endl;
    // -------------------------------------------------

    vector<Alumno> alumnos;
    alumnos.push_back(Alumno("Robertito", 15));
    alumnos.push_back(Alumno("Pepito", 17));
    alumnos.push_back(Alumno("Manuelito", 9));
    sort(alumnos.begin(), alumnos.end());
    for (Alumno& alumno : alumnos) alumno.mostrar();

    // it es el iterador
    // *it es el alumno
    // (*it).metodo()
    cout << endl;
    for (auto it = alumnos.begin(); it != alumnos.end(); ++it) {
        cout << *it;
    }

    // Llenar desde un archivo
    ifstream arch("Archivos/alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout << endl << "Error al abrir alumnos.csv" << endl;
        exit(1);
    }
    Alumno alum;
    while (true) {
        arch >> alum;
        if (arch.eof()) break;
        alumnos.push_back(alum);
    }
    for (Alumno alumno : alumnos) cout << alumno;

    cout << "-------------------------" << endl;
    // -------------------------------------------------

    vector<int> numeros2 = {25,20,18,21,22,30,45};
    cout << "Con for:         ";
    for (int numero: numeros2) cout << numero << " ";
    // con iterator
    cout << endl << "Con iterator:    ";
    for (auto it = numeros2.begin(); it != numeros2.end(); ++it) cout << *it << " ";
    // ordenar los datos
    cout << endl << endl << "Datos ordenados: ";
    sort(numeros2.begin(), numeros2.end());

    for (int numero : numeros2) cout << numero << " ";
    cout << endl << "-------------------------" << endl;
    // ============================================================

    return 0;
}
