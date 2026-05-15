#include <iostream>
using namespace std;

#include "Cola.h"
#include "Funciones.h"


void construir(struct Cola& cola){
    cola.inicio = nullptr;
    cola.fin = nullptr;
    cola.longitud = 0;
}

void encolar(struct Cola& cola, const struct ElementoCola& elemento) {
    struct NodoCola* nuevo = new struct NodoCola;
    nuevo->elemento = elemento;
    nuevo->sgte = nullptr;
    // si es el primero
    if (cola.inicio == nullptr) {
        cola.inicio = nuevo;
        cola.fin = nuevo;
    }
    else { // si no es el primero va al final
        cola.fin->sgte = nuevo;
            cola.fin = nuevo;
    }
    cola.longitud++;
}

struct ElementoCola desencolar(struct Cola& cola) {
    struct NodoCola* desencolado = new struct NodoCola;
    if (cola.inicio != nullptr) {
        desencolado = cola.inicio;
        cola.inicio = cola.inicio->sgte;
        cola.longitud--;
    }
    return desencolado->elemento;
}

void imprimir(const struct Cola& cola) {
    struct NodoCola* actual = cola.inicio;
    for (int i = 0; i < cola.longitud; i++) {
        if (i==0) cout << "[";
        cout << actual->elemento.numero;
        if (i != cola.longitud-1) cout << ", ";
        else cout << "]";
        actual = actual->sgte;
    }
    cout << endl;
}

void ordenarCola(struct Cola& cola, int n) {
    struct ElementoCola aux, menor;
    int k = 0; // Cantidad de Nodos ordenados
    for (int i = 1; i <= n; i++) { // total de iteraciones = 10
        menor = desencolar(cola); // el Nodo que voy a terminar ordenando
        for (int j = 1; j <= n-i; j++) { // total de iteraciones = 9
            aux = desencolar(cola);
            if (aux.numero < menor.numero) { // Si encuentro un nuevo menor
                encolar(cola, menor);
                menor = aux; // lo asignamos
            }
            else {
                encolar(cola, aux);
            }
        }
        // Tengo Nodos que YA ESTAN ORDENADOS, por lo que no los toco
        // Es decir, desencolo y encolo, más nada
        for (int m=0; m < k; m++) {
            encolar(cola, desencolar(cola));
        }// luego de aqui es que aumento mi cantiad de ordenados
        k++; // Cantidad de nodos ya ordenados
        encolar(cola, menor);
    }
}

void ordenarRecursivo(struct Cola& cola, int n) {
    // CASO BASE
    if (cola.longitud == 0) return;

    ElementoCola mayor= desencolar(cola), aux;
    for (int i = 1; i < n; i++) {
        aux = desencolar(cola);
        if (aux.numero > mayor.numero) {
            // Por como funciona la recursividad, tenemos que usar el mayor
            encolar(cola, mayor);
            mayor = aux;
        }
        else {
            encolar(cola, aux);
        }
    } // Hasta aqui me quedo con el menor de la cola

    ordenarRecursivo(cola, n-1);

    encolar(cola, mayor);
}