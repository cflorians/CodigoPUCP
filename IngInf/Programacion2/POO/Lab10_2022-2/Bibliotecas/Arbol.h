//
// Created by Carlos on 18/06/2026.
//

#ifndef LAB10_2022_2_ARBOL_H
#define LAB10_2022_2_ARBOL_H
#include "Nodo.h"

class Arbol {
private:
    Nodo* raiz;
    void insertarRecursivo(Nodo*& n, Medicamento* m);
    void destruir(Nodo*& n);
public:
    Arbol();
    ~Arbol();
    void insertar(Medicamento* m);
    // hacer la funcion que imprima para que imprima con nodo
};
void operator << (ofstream& arch, const Arbol& arbol);

#endif //LAB10_2022_2_ARBOL_H
