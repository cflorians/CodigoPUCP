#include <iostream>

#include "BibliotecaCola/Elemento.h"
#include "BibliotecaPila/Elemento.h"
using namespace std;

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/Funciones.h"

#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/Funciones.h"

void OrdenaPila(Pila& pila1, Pila& pila2) {
    ElementoPila auxiliar{}, mayor{};
    int i, j;
    int tamano = pila1.longitud;

    for (i=0; i<tamano; i++) {
        for (j=0; j<tamano - i; j++) {
            auxiliar = desapilar(pila1)->elemento;
            if (j==0) { // es el primero por lo que asumo que es el mayor
                mayor = auxiliar;
            }
            else {
                if (auxiliar.numero%100 > mayor.numero%100) { // encontre un nuevo mayor
                    //OJO que es con los 2 ultimos digitos
                    apilar(pila2, mayor); // apilo el que era mayor
                    mayor = auxiliar;
                }
                else {
                    apilar(pila2,auxiliar); // mantengo el mayor y apilo el que desapile (auxiliar)
                }
            } // Hasta este punto tengo el mayor
        }
        apilar(pila1,mayor);
        while (pila2.inicio != nullptr) {
            // paso todos los nodos analizados de pila 2 a pila 1
            apilar(pila1, desapilar(pila2)->elemento);
        }
    }
}

void ReiniciaCola(Cola& cola, int n, Pila& pila1, Pila& pila2) {
    // Paso 1: Se pasan los nodos de Pila2 a Pila1
    pasaPila(pila2, pila1);
    // Paso 2: Se ordena Pila1
    OrdenaPila(pila1, pila2);
    // Paso3:
    int longitud_pila = pila1.longitud;
    // En azul: Desencola y encola longitud Cola - longitud Pila1 espacios,
    //          luego desencola longitud Pila1 espacios y se apilan en Pila1
    for (int i=0; i<n-longitud_pila; i++) {
        encolar(cola, desencolar(cola));
    }
    for (int i=0; i<longitud_pila; i++) {
        //  apilar(pila1, desencolar(cola));
    }
    // En verde: Se encola longitud Pila1 espacios desde Pila1
    // En anaranjado: Se desencola y enconla longitud Cola - longitud Pila1 espacios
}

int main() {
    
    Cola cola;
    int n = 8; // # de espacios de la cola segun enunciado
    Pila pila1, pila2;

    construir(cola);
    construir(pila1);
    construir(pila2);

    apilar(pila1,{ 101});
    apilar(pila1,{ 102});
    apilar(pila2,{ 203});
    apilar(pila2,{ 204});
    apilar(pila1,{ 105});

    encolar(cola, {206});
    encolar(cola, {107});
    encolar(cola, {208});
    encolar(cola, {109});
    encolar(cola, {210});
    encolar(cola, {211});
    encolar(cola, {112});
    encolar(cola, {113});

    cout << "INICIAL" << endl;
    imprimir(cola);
    imprimir(pila1);
    imprimir(pila2);

    ReiniciaCola(cola, n, pila1, pila2);
    cout << "REINICIA COLA" << endl;
    cout << "Cola: ";
    imprimir(cola);
    cout << "Pila1: ";
    imprimir(pila1);
    cout << "Pila2: ";
    imprimir(pila2);

    return 0;
}
