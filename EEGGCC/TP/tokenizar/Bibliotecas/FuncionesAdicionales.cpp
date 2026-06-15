#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAdicionales.h"
#include "Estructuras.h"

void leerDatos(struct Nodo*& lista) {
    ifstream arch("ArchivosDeDatos/datos.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir datos.txt" << endl;
        exit(1);
    }

    char coment[100];
    char *comentPreprocesado;
    while (true) {
        arch.getline(coment, 100, '\n');

        char nueva[100];
        char c;

        int j=0;
        for (int i=0; coment[i]; i++) {
            c = coment[i];
            if (isalpha(c) or c == ' ') {
                nueva[j] = tolower(c);
                j++;
            }
        }
        nueva[j] = '\0';

        insertarEnLista(lista, nueva);

        if (arch.eof()) break;
    }
}

void mostrarLista(const struct Nodo* lista) {
    while (lista) {
        cout << lista->comentario.comentario << endl;
        lista = lista->sgte;
    }
}

void insertarEnLista(struct Nodo*& lista, char* coment) {
    struct Nodo* ptr = new struct Nodo;

    strcpy(ptr->comentario.comentario, coment);

    ptr->sgte = lista;
    lista = ptr;
}

// char* preprocesar(char* cadena) {
//
//
//     cout << nueva << endl;
//     return nueva;
// }

void procesar(struct Nodo *&lista) {
    struct Nodo* ptr = lista;

    while (ptr) {
        if (strcmp(ptr->comentario.comentario, "") == 0) {}
    }
}