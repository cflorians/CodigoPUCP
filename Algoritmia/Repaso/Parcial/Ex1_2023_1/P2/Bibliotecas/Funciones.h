//
// Created by Carlos on 5/21/2026.
//

#ifndef P2_FUNCIONES_H
#define P2_FUNCIONES_H

void parteEGISI();
void construir(ColaA &c);
void encolar_prioridad(ColaA& c, int prioridad, const char* isi);
void mostrarCola(ColaA c);

void parteEGP();
void construir(ColaB& c);
void construir(PilaB& p);
void encolar(ColaB& c, int id, int detecto);
NodoB* desencolar(ColaB& c);
void push(PilaB& p, NodoB* nodo);
NodoB* pop(PilaB &p);
void reorganizarEGP(ColaB& c);
void mostrarCola(ColaB c);

#endif //P2_FUNCIONES_H
