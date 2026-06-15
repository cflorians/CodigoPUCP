#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

#include "ListaConRegistros.h"

enum lista{INICIO, FIN, CANTNODOS};
enum dupla{DATO, ARREGLO};
enum nodo{DUPLA, SGTE};
enum registro{CODIGO, NOMBRE, UNIDAD};
enum orden{DNI, CANT, PLATO};

void* leeregistros(ifstream& arch) {
    void** reg = new void*[3]{};
    // JNV387,Justino Norabuena Virginia Karina,Motocicleta
    char *codigo, *nombre, *unidad;
    codigo = leerCadena(arch);
    nombre = leerCadena(arch);
    unidad = leerCadena(arch, '\n');
    reg[CODIGO] = codigo;
    reg[NOMBRE] = nombre;
    reg[UNIDAD] = unidad;
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

int compruebaregistro(const void* a, const void* b) {
    void** repartidor = (void**)a;
    void** paqueteOrden = (void**)b;

    char* idRepartidor = (char*)repartidor[CODIGO];
    char* idBuscado = (char*)paqueteOrden[0];

    return strcmp(idRepartidor, idBuscado) == 0;
}

// int compruebanumero(const void* dat, const void* reg) {
//     void** dato = (void**)dat;
//     void** registro = (void**)reg;
//     int* num1 = (int*)dato[0];
//     int* num2 = (int*)registro[0]; // :v
//
//     return (*num1) == (*num2);
// }

void* leeordenes(ifstream& arch) {
    void** reg = new void*[3]{};
    // 12484697,2,AD-546,LAF361
    // DNI, cant ,plato, codRepartidor
    char *plato, *codRepartidor;
    int *dni = new int, *cant = new int;
    arch >> *dni;
    arch.get();
    arch >> *cant;
    arch.get();
    plato = leerCadena(arch);
    codRepartidor = leerCadena(arch, '\n');

    reg[DNI] = dni;
    reg[CANT] = cant;
    reg[PLATO] = plato;

    void** dupla = new void*[2]{};
    dupla[0] = codRepartidor;
    dupla[1] = reg;
    return dupla;
}

void imprimeregistros(ofstream& arch, const void* act) {
    void** actual = (void**)act;
    void** duplaActual = (void**)actual[DUPLA];
    void** dato = (void**)duplaActual[DATO];
    void** arreglo = (void**)duplaActual[ARREGLO];

    arch << left << setw(10) << (char*)dato[CODIGO];
    arch << (char*)dato[NOMBRE] << endl;
    arch << "Ordenes:" << endl;

    for (int i=0; arreglo[i]; i++) {
        void** orden = (void**)arreglo[i];
        arch << left << setw(15) << *(int*)orden[DNI]
             << setw(5) << *(int*)orden[CANT]
             << (char*)orden[PLATO] << endl;
    }
}
// void imprimenumeros(ofstream& arch, const void* act) {
//     void** actual = (void**)act;
//     void** duplaActual = (void**)actual[DUPLA];
//     void** dato = (void**)duplaActual[DATO];
//     void** arreglo = (void**)duplaActual[ARREGLO];
//
//     arch << *(int*)dato[0] << endl;
//     for (int i=0; arreglo[i]; i++) {
//         arch << *(int*)arreglo[i] << " ";
//     }
//     arch << endl << endl;
// }
