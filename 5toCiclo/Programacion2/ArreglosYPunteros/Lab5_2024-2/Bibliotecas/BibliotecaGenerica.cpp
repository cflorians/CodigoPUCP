#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

#include "BibliotecaGenerica.h"

enum lista{INICIO, FIN, CANTNODOS};
enum dupla{DATO, ARREGLO};
enum nodo{DUPLA, SGTE};

void crealista(void*& lista, void* (*leer)(ifstream&), const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }
    construir(lista);

    void* reg = nullptr;
    while (true) {
        reg = leer(arch);
        if (arch.eof()) break;
        insertarfinal(lista, reg);
    }
}

void construir(void*& list) {
    void** lista = new void*[3]{};
    lista[INICIO] = nullptr;
    lista[FIN] = nullptr;
    lista[CANTNODOS] = nullptr;
    list = lista;
}

void insertarfinal(void*& list, void* reg) {
    void** lista = (void**)list;

    // creamos la dupla
    void** nuevaDupla = new void*[2]{};
    nuevaDupla[DATO] = reg;
    nuevaDupla[ARREGLO] = new void*[20]{};

    // creamos el nodo
    void** nuevoNodo = new void*[2]{};
    nuevoNodo[DUPLA] = nuevaDupla;
    nuevoNodo[SGTE] = nullptr;

    if (eslistavacia(lista)) { // si la lista esta vacia
        lista[INICIO] = nuevoNodo;
        lista[FIN] = nuevoNodo;
        // solo creamos cantNodos la primera vez
        int* cantNodos = new int;
        *cantNodos = 1;
        lista[CANTNODOS] = cantNodos;
    }
    else { // si la lista ya tiene datos
        // usamos el nodo anterior para apuntar al nuevo
        insertar(nuevoNodo, lista[FIN]);
        lista[FIN] = nuevoNodo;
        (*(int*)lista[CANTNODOS]) += 1;
    }
}

void insertar(void* dupla, void*& list) {
    void** nodoFin = (void**)list;
    nodoFin[SGTE] = dupla;
}

bool eslistavacia(const void* list) {
    void** lista = (void**)list;
    return lista[INICIO] == nullptr;
}

void cargalista(void* list, int (*comprueba)(const void*, const void*),
                void* (*leer)(ifstream&), const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    void* reg = nullptr;
    void** lista = (void**)list;
    void** actual = nullptr;

    while (true) {
        reg = leer(arch);
        if (arch.eof()) break;
        //reiniciamos el actual en cada vuelta
        actual = (void**)lista[INICIO];

        while (actual) {
            void** duplaActual = (void**)actual[DUPLA];
            void** datoActual = (void**)duplaActual[DATO];

            if (comprueba(datoActual, reg)) {
                void** arreglo = (void**)duplaActual[ARREGLO];
                int cantNum = 0;

                while (arreglo[cantNum]) cantNum++;

                void** registroLeido = (void**)reg;
                arreglo[cantNum] = registroLeido[1];
            }

            actual = (void**)actual[SGTE];
        }
    }
}

void muestralista(const void* list, void (*imprime)(ofstream&,const void*), const char* nombArch) {
    ofstream arch(nombArch, ios::out);

    void** lista = (void**)list;
    void** actual = (void**)lista[INICIO];
    while (actual) {
        imprime(arch, actual);
        actual = (void**)actual[SGTE];
    }
}