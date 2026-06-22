#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "BibliotecaGenerica.h"

enum lista{BLOQUE1, BLOQUE2};
enum nodo{DATO, SGTE};
enum dato{LICENCIA, FECHA, INFRACCION, NOMBRE};

void crearLista(void*& lista, void* (*leenum)(ifstream&), int (*clasifica)(const void*),
                const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    generaLista(lista);
    void* reg = nullptr;

    while (true) {
        reg = leenum(arch);
        if (arch.eof()) break;
        insertarLista(lista, reg, clasifica);
    }
}

void generaLista(void*& list){
    void** lista = new void*[2]{};
    lista[BLOQUE1] = nullptr;
    lista[BLOQUE2] = lista[BLOQUE1];
    list = lista;
}

void insertarLista(void*& list, void* dat, int (*comparar)(const void*)) {
    void** lista = (void**)list;
    void** nodo = new void*[2]{};
    nodo[DATO] = dat;
    nodo[SGTE] = nullptr;
    int bloque = comparar(dat);
    void** actual;

    if (bloque == 0) {
        nodo[SGTE] = lista[BLOQUE2];
        actual = (void**)lista[BLOQUE1];
        if (lista[BLOQUE1] == nullptr) { // caso que bloque 1 este vacio
            lista[BLOQUE1] = nodo;
        }
        else { // si es que no esta vacio
            for (int i=0; actual[SGTE] != lista[BLOQUE2]; i++) {
                actual = (void**)actual[SGTE];
            }
            actual[SGTE] = nodo;
        }
    }
    else {
        if (lista[BLOQUE2] == nullptr) { // caso que bloque 2 este vacio
            void* antiguoB2 = lista[BLOQUE2];
            lista[BLOQUE2] = nodo;
            if (lista[BLOQUE1] != nullptr) {
                actual = (void**)lista[BLOQUE1];
                for (int i=0; actual[SGTE] != antiguoB2; i++) {
                    actual = (void**)actual[SGTE];
                }
                actual[SGTE] = lista[BLOQUE2];
            }
        }
        else { // si es que ya existen datos en el bloque 2
            actual = (void**)lista[BLOQUE2];
            for (int i=0; actual[SGTE]; i++) {
                actual = (void**)actual[SGTE];
            }
            actual[SGTE] = nodo;
        }
    }
}

int clasificaEntero(const void* num) {
    void** reg = (void**)num;
    if (*(int*)reg[0] < 10) return 0;
    else return 1;
}

void* leerNumero(ifstream& arch) {
    void** reg = new void*[1]{};
    int* num = new int;
    arch >> *num;
    reg[0] = num;
    return reg;
}

void imprimeLista(void* list,void (*imprimeDato)(ofstream&, const void*), const char* nombArch) {
    void** lista = (void**)list;
    void** actual = (void**)lista[BLOQUE1];
    ofstream arch(nombArch, ios::out);

    for (int i=0; actual; i++) {
        imprimeDato(arch, actual[DATO]);
        actual = (void**)actual[SGTE];
    }
}

void imprimenum(ofstream& arch, const void* reg) {
    void** registro = (void**)reg;
    int* num = (int*)registro[0];
    arch << *num << endl;
}

void* leeregistro(ifstream& arch) {
    void** reg = new void*[4]{};
    //47844324,X7J-719,14/09/2019,101,VILCA LEE NESTOR HUGO
    //licencia, placa, fecha, infraccion, nombre
    char *placa, *fecha, *nombre;
    int* infraccion = new int, * licencia = new int;
    arch >> *licencia;
    arch.get();
    placa = leerCadena(arch, ',');
    fecha = leerCadena(arch, ',');
    arch >> *infraccion;
    arch.get();
    nombre = leerCadena(arch, '\n');

    reg[LICENCIA] = licencia;
    reg[FECHA] = fecha;
    reg[INFRACCION] = infraccion;
    reg[NOMBRE] = nombre;
    return reg;
}

char* leerCadena(ifstream& arch, char limit) {
    char cadena[200]{};
    char* cadenaExacta;
    arch.getline(cadena, 200, limit);
    cadenaExacta = new char[strlen(cadena)+1];
    strcpy(cadenaExacta, cadena);
    return cadenaExacta;
}

int clasificaregistro(const void* reg) {
    void** registro = (void**)reg;
    if (*(int*)registro[INFRACCION] < 200) return 0;
    else return 1;
}

void imprimeregistro(ofstream& arch, const void* reg) {
    void** registro = (void**)reg;
    arch << setw(12) << left << (char*)registro[FECHA];
    arch << right << *(int*)registro[LICENCIA] << "  ";
    arch << setw(50) << left << (char*)registro[NOMBRE];
    arch << right << *(int*)registro[INFRACCION] << endl;
}