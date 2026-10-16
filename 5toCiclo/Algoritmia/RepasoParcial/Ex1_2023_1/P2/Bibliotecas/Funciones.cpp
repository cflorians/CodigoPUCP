#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Estructuras.h"
#include "Funciones.h"

void construir(ColaA &c) {
    c.inicio = nullptr;
    c.final = nullptr;
}

void encolar_prioridad(ColaA& c, int prioridad, const char* isi) {
    NodoA* nuevo = new NodoA;
    nuevo->prioridad = prioridad;
    strcpy(nuevo->codigoISI, isi);
    nuevo->sig = nullptr;

    // Cola vacia o nuevo tiene mas prioridad que el inicio de la cola
    if (c.inicio == nullptr or prioridad > c.inicio->prioridad) {
        nuevo->sig = c.inicio;
        c.inicio = nuevo;
        if (c.final == nullptr) c.final = nuevo; // si es cola vacia
    }
    // Buscar la posicion correcta
    else {
        NodoA* actual = c.inicio;

        // Recorremos hasta que encontremos el final de la prioridad en la que debe ir
        while (actual->sig != nullptr and actual->sig->prioridad >= prioridad) {
            actual = actual->sig;
        }

        // Enlazamos
        nuevo->sig = actual->sig;
        actual->sig = nuevo;

        // si esta al final, actualizamos el ultimo puntero
        if (nuevo->sig == nullptr) c.final = nuevo;
    }
}

void mostrarCola(ColaA c) {
    NodoA* act = c.inicio;
    if (act == nullptr) {
        cout << "La cola está vacía." << endl;
        return;
    }
    while (act != nullptr) {
        cout << "* " << act->codigoISI << " (Prioridad: " << act->prioridad << ")" << endl;
        act = act->sig;
    }
    cout << endl;
}

void parteEGISI() {
    ColaA colaEGISI;
    construir(colaEGISI);


    encolar_prioridad(colaEGISI, 1, "ISI007");
    encolar_prioridad(colaEGISI, 3, "ISI006");
    encolar_prioridad(colaEGISI, 2, "ISI005");
    encolar_prioridad(colaEGISI, 3, "ISI004");
    encolar_prioridad(colaEGISI, 1, "ISI003");
    encolar_prioridad(colaEGISI, 1, "ISI002");
    encolar_prioridad(colaEGISI, 2, "ISI001");

    cout << "=== EGISI: ATENCION DE INCIDENTES ===" << endl;
    cout << "Cola ordenada por prioridad y orden de llegada:" << endl;
    mostrarCola(colaEGISI);
}

void parteEGP() {
    ColaB colaEGP;
    construir(colaEGP);

    encolar(colaEGP, 1010, 1);
    encolar(colaEGP, 1009, 1);
    encolar(colaEGP, 1008, 1);
    encolar(colaEGP, 1007, 1);
    encolar(colaEGP, 1006, 1);
    encolar(colaEGP, 1005, 2);
    encolar(colaEGP, 1004, 2);
    encolar(colaEGP, 1003, 2);
    encolar(colaEGP, 1002, 2);
    encolar(colaEGP, 1001, 2);

    cout << "=== COLA ORIGINAL TRANSFERIDA ===" << endl;
    mostrarCola(colaEGP);

    reorganizarEGP(colaEGP);

    cout << "=== NUEVA COLA REQUERIDA (INTERCALADA) ===" << endl;
    mostrarCola(colaEGP);
}

void construir(ColaB& c) {
    c.inicio = nullptr;
    c.final = nullptr;
}

void construir(PilaB& p) {
    p.inicio = nullptr;
}

void encolar(ColaB& c, int id, int detecto) {
    NodoB* nuevo = new NodoB;
    nuevo->id = id;
    nuevo->detecto = detecto;
    nuevo->sig = nullptr;

    if (c.inicio == nullptr) {
        c.inicio = nuevo;
        c.final = nuevo;
    }
    else {
        c.final->sig = nuevo;
        c.final = nuevo;
    }

}

NodoB* desencolar(ColaB& c) {
    if (c.inicio == nullptr) return nullptr;
    NodoB* aDesencolar;
    aDesencolar = c.inicio;
    c.inicio = c.inicio->sig;
    if (c.inicio == nullptr) c.final = nullptr;
    return aDesencolar;
}

void push(PilaB& p, NodoB* nodo) {
    nodo->sig = p.inicio;
    p.inicio = nodo;
}

NodoB* pop(PilaB &p) {
    if (p.inicio == nullptr) return nullptr;
    NodoB* aux = p.inicio;
    p.inicio = p.inicio->sig;
    return aux;
}

void reorganizarEGP(ColaB& c) {
    PilaB aux;
    construir(aux);

    // Pasamos a los trabajadores a la pila
    for (int i=0; i<5; i++) {
        push(aux, desencolar(c));
    }

    // Rotamos los sistemas
    for (int i = 0; i < 5; i++) {
        NodoB* nodo = desencolar(c);
        encolar(c, nodo->id, nodo->detecto);
        delete nodo;
    }

    // Insertamos intercalados
    for (int i = 0; i < 5; i++) {
        // Sacamos un trabajador de la pila y lo encolamos
        NodoB* nodoTrab = pop(aux);
        encolar(c, nodoTrab->id, nodoTrab->detecto);
        delete nodoTrab;

        // Ponemos el sistema que esta al inicio de la cola
        NodoB* nodoSist = desencolar(c);
        encolar(c, nodoSist->id, nodoSist->detecto);
        delete nodoSist;
    }
}

void mostrarCola(ColaB c) {
    NodoB* act = c.inicio;
    while (act != nullptr) {
        cout << "  PS" << act->id << " (Detectó: "
             << (act->detecto == 1 ? "Trabajador" : "Sistema") << ")" << endl;
        act = act->sig;
    }
    cout << endl;
}