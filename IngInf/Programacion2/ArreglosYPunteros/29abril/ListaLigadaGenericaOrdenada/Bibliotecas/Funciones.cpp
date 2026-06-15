#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Funciones.h"

enum paciente{ID, NOMBRE, EDAD, GENERO};
enum lista{DATO, SIGUIENTE};

void crearLista(void*& lista, void*(*leer)(ifstream&),
                int(*comparar)(const void*, const void*),
                const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    void* dato;
    while (true) {
        dato = leer(arch);
        if (arch.eof()) break;
        insertar(lista, dato, compararDato);
    }
}

void* leerDato(ifstream& arch) {
    void* dato;
    void** reg = new void*[4];
    char* genero;
    int* dni = new int;
    char* nombre;
    int* edad = new int;

    arch >> *dni;
    arch.get();
    nombre = leerCadena(arch, ',');
    arch >> *edad;
    arch.get();
    genero = leerCadena(arch, '\n');

    reg[ID] = dni;
    reg[NOMBRE] = nombre;
    reg[EDAD] = edad;
    reg[GENERO] = genero;

    return reg;
}

char* leerCadena(ifstream& arch, char limit) {
    char cadena[100]{};
    char* cadenaExacta;
    arch.getline(cadena, 100, limit);
    cadenaExacta = new char[strlen(cadena)+1];
    strcpy(cadenaExacta, cadena);
    return cadenaExacta;
}

void insertar(void*& lista, void* dato, int(*comparar)(const void*, const void*)) {
    void** recorrido = (void**)lista;
    void** anterior = nullptr;
    void** nuevo = new void*[2]{};
    nuevo[DATO] = dato;
    nuevo[SIGUIENTE] = nullptr;

    while (recorrido) {
        if (comparar(dato, recorrido[DATO]) < 0) break;
        anterior = recorrido;
        recorrido = (void**)recorrido[SIGUIENTE];
    }

    nuevo[SIGUIENTE] = recorrido;
    if (anterior) anterior[SIGUIENTE] = nuevo;
    else lista = nuevo;
}