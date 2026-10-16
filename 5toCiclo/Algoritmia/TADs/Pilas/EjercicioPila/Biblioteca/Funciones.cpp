//
// Created by carlo on 4/27/2026.
//

#include "Funciones.h"

#include <cstring>
#include <iostream>
using namespace std;

#include "Pila.h"

#define MAX 10

void construir(struct Pila& pila) {
    pila.inicio = nullptr;
    pila.longitud = 0;
}

void apilar(struct Pila& pila, struct Elemento elemento) {
    struct Nodo* nodo = new struct Nodo;
    nodo->elemento = elemento;
    nodo->sgte = pila.inicio;
    pila.inicio = nodo;
}

struct Nodo* cima(const struct Pila& pila) {
    return pila.inicio;
}

void imprimirPila(const struct Pila& pila) {
    struct Nodo* actual = pila.inicio;
    cout << "[";
    while (actual != nullptr) {
        cout << actual->elemento.codigo;
        if (actual->sgte != nullptr) {
            cout << ", ";
        }
        actual = actual->sgte;
    }
    cout << "]" << endl;
}

void notacionPostFija(struct Pila& pila) {
    int operando1;
    int operando2;
    int resultado;

    char expresion[MAX];
    cout << "Ingrese la expresión postfija: " << endl;
    //Iteración para analizar cada elemento de la expresión
    while (!cin.eof()) {
        cin >> expresion;
        if (esOperador(expresion)) {
            operando2 = desapilar(pila)->elemento.codigo;
            operando1 = desapilar(pila)->elemento.codigo;
            resultado = opera(expresion, operando1, operando2);
            apilar(pila,{resultado});
        }
        else {
            apilar(pila,{atoi(expresion)});
        }
        imprimirPila(pila);
    }
}

int opera(char* c,int operando1,int operando2) {
    int resultado;
    if (strcmp(c,"+") == 0) {
        resultado = operando1 + operando2;
    }
    else if (strcmp(c,"-") == 0) {
        resultado = operando1 - operando2;
    }
    else if (strcmp(c,"*") == 0) {
        resultado = operando1 * operando2;
    }
    else if (strcmp(c,"/") == 0) {
        resultado = operando1 / operando2;
    }
    return resultado;
}

bool esOperador(char* c) {
    return (strcmp(c,"+") == 0 or
            strcmp(c,"-") == 0 or
            strcmp(c,"*") == 0 or
            strcmp(c,"/") == 0);
}

struct Nodo* desapilar(struct Pila& pila) {
    if (pila.inicio != nullptr) {
        struct Nodo* aux = pila.inicio;
        pila.inicio = aux->sgte;
        return aux;
    }
}
