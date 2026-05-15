#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

#include "ListaConEnteros.h"

enum lista{INICIO, FIN, CANTNODOS};
enum dupla{DATO, ARREGLO};
enum nodo{DUPLA, SGTE};

void* leenumeros(ifstream& arch) {
    void** reg = new void*[2]{};
    int* num = new int;
    arch >> *num;
    reg[0] = num;
    return reg;
}

int compruebanumero(const void* dat, const void* reg) {
    void** dato = (void**)dat;
    void** registro = (void**)reg;
    int* num1 = (int*)dato[0];
    int* num2 = (int*)registro[0]; // :v

    return (*num1) == (*num2);
}

void* leeregnumeros(ifstream& arch) {
    void** reg = new void*[2]{};
    int* num = new int;
    int* nuevoNum = new int;
    arch >> *num;
    arch>> *nuevoNum;
    reg[0] = num;
    reg[1] = nuevoNum;
    return reg;
}

void imprimenumeros(ofstream& arch, const void* act) {
    void** actual = (void**)act;
    void** duplaActual = (void**)actual[DUPLA];
    void** dato = (void**)duplaActual[DATO];
    void** arreglo = (void**)duplaActual[ARREGLO];

    arch << *(int*)dato[0] << endl;
    for (int i=0; arreglo[i]; i++) {
        arch << *(int*)arreglo[i] << " ";
    }
    arch << endl << endl;
}
