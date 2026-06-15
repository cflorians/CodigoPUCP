#include <iostream>
using namespace std;

#include "Bibliotecas/Funciones.h"  
#include "Bibliotecas/Lista.h"

void reorganizar(struct Lista& lista1, struct Lista& lista2) {
    // Caso 1: Todos los elementos de L1 son mayores que L2, RESTRICCIÓN: Complejidad O(1)
    if (lista1.fin->elemento.nivelImpacto > lista2.inicio->elemento.nivelImpacto) {
        lista1.fin->sgte = lista2.inicio;
        lista1.fin = lista2.fin;
        lista1.longitud += lista2.longitud;
    }
    // Caso 2: Todos los elementos de L2 son mayores que L1, RESTRICCIÓN: Complejidad O(1)
    else {
        if (lista2.fin->elemento.nivelImpacto > lista1.inicio->elemento.nivelImpacto) {
            lista2.fin->sgte = lista1.inicio;
            lista1.inicio = lista2.inicio;
            lista1.longitud += lista1.longitud;
        }
        // Caso 3: Hay traslape entre L1 y L2, RESTRICCIÓN: Complejidad O(N)
        else {
            Lista listaFinal{};
            construir (listaFinal);
            // Mientras tenga elementos en ambas listas
            while (lista1.inicio != nullptr and lista2.inicio != nullptr) { // Ganador L1
                if (lista1.inicio->elemento.nivelImpacto >= lista2.inicio->elemento.nivelImpacto) {
                    // Coloco a L1 porque es el que tiene la letra antes en orden alfabetico
                    if (listaFinal.inicio == nullptr) { // Si es el primer nodo en listaFinal
                        listaFinal.inicio = lista1.inicio;
                        listaFinal.fin = lista1.inicio;
                    }
                    else { // Si ya hay elementos en listaFinal
                        listaFinal.fin->sgte = lista1.inicio;
                        listaFinal.fin = lista1.inicio;
                    } // Como ya procesamos al ganador (L1), avanzamos el inicio;
                    lista1.inicio = lista1.inicio->sgte;
                }
                else if (lista1.inicio->elemento.nivelImpacto < lista2.inicio->elemento.nivelImpacto){
                    // ganador L2
                    // Coloco a L2
                    if (listaFinal.inicio == nullptr) { // Si es el primer nodo en listaFinal
                        listaFinal.inicio = lista2.inicio;
                        listaFinal.fin = lista2.inicio;
                    }
                    else { // Si ya hay elementos en listaFinal
                        listaFinal.fin->sgte = lista2.inicio;
                        listaFinal.fin = lista2.inicio;
                    } // Como ya procesamos al ganador (L1), avanzamos el inicio;
                    lista2.inicio = lista2.inicio->sgte;
                }
            }
            if (lista1.inicio == nullptr) { // Ya pasamos lista1, queda el resto de lista2
                listaFinal.fin->sgte = lista2.inicio;
                listaFinal.fin = lista2.fin;
            }
            else if (lista2.inicio == nullptr) {
                listaFinal.fin->sgte = lista1.inicio;
                listaFinal.fin = lista1.fin;
            }
            lista1.inicio = listaFinal.inicio;
            lista1.fin = listaFinal.fin;

        }
    }
}

int main() {
    Lista CategoriaA{}, CategoriaB{}, CategoriaC{}, CategoriaD{}, CategoriaE{};

    construir(CategoriaA);
    construir(CategoriaB);
    construir(CategoriaC);
    construir(CategoriaD);
    construir(CategoriaE);

    insertarAlFinal(CategoriaA, {15, 'A'});
    insertarAlFinal(CategoriaA, {13, 'A'});
    insertarAlFinal(CategoriaA, {12, 'A'});
    insertarAlFinal(CategoriaA, {11, 'A'});
    imprimir(CategoriaA);

    insertarAlFinal(CategoriaB, {20, 'B'});
    insertarAlFinal(CategoriaB, {19, 'B'});
    imprimir(CategoriaB);

    insertarAlFinal(CategoriaC, {18, 'C'});
    insertarAlFinal(CategoriaC, {17, 'C'});
    insertarAlFinal(CategoriaC, {16, 'C'});
    imprimir(CategoriaC);

    insertarAlFinal(CategoriaD, {17, 'D'});
    insertarAlFinal(CategoriaD, {15, 'D'});
    insertarAlFinal(CategoriaD, {14, 'D'});
    insertarAlFinal(CategoriaD, {13, 'D'});
    insertarAlFinal(CategoriaD, {12, 'D'});
    imprimir(CategoriaD);

    insertarAlFinal(CategoriaE, {14, 'E'});
    insertarAlFinal(CategoriaE, {12, 'E'});
    insertarAlFinal(CategoriaE, {10, 'E'});
    insertarAlFinal(CategoriaE, {8, 'E'});
    imprimir(CategoriaE);

    cout << "Regorganizar: " << endl;
    // Vamos a juntar de 2 en 2 las listas
    reorganizar(CategoriaA, CategoriaB);
    imprimir(CategoriaA);
    reorganizar(CategoriaA, CategoriaC);
    imprimir(CategoriaA);
    reorganizar(CategoriaA, CategoriaD);
    imprimir(CategoriaA);
    reorganizar(CategoriaA, CategoriaE);
    imprimir(CategoriaA);

    return 0;
}
