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
    pila.longitud++;
}

struct Nodo* cima(const struct Pila& pila) {
    return pila.inicio;
}

void imprimirPila(const struct Pila& pila) {
    struct Nodo* actual = pila.inicio;
    cout << "[";
    while (actual != nullptr) {
        cout << actual->elemento.numero;
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
            operando2 = desapilar(pila)->elemento.numero;
            operando1 = desapilar(pila)->elemento.numero;
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
        pila.longitud--;
        return aux;
    }
}

void pasaPila(struct Pila& pila1, struct Pila& pila2) {
    int valor, aux;
    int n;
    while (pila1.inicio != nullptr) {
        valor = desapilar(pila1)->elemento.numero;
        n = 0; // numero de elementos que apilo en pila 2
        while (pila1.inicio != nullptr) {
            apilar(pila2,{valor});
            n++;
            valor = desapilar(pila1)->elemento.numero;
        } // me quedo con el ultimo elemento de la pila.
        while (n>0) {
            aux = desapilar(pila2)->elemento.numero;
            apilar(pila1, {aux});
            n--;
        } // pase los n elemento de pila 2 a pila 1
        // asigno el que me quede a la pila 2
        apilar(pila2,{valor});
        // con esto he pasado los n elementos;
    }
}

void pasaPilaRecursiva(struct Pila& pila1, struct Pila& pila2) {
    // CASO BASE
    if (pila1.inicio == nullptr) return;
    // PARTE RECURSIVA
    int valor = desapilar(pila1)->elemento.numero;
    pasaPilaRecursiva(pila1,pila2);
    apilar(pila2,{valor});
}