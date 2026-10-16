#include <iostream>
using namespace std;

#include "Bibliotecas/Lista.h"
#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv){
    
    Lista lunes, martes, miercoles, jueves, viernes;

    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);

    insertarAlFinal(lunes, {8, 6, "Lunes"});
    insertarAlFinal(lunes, {10, 14, "Lunes"});
    insertarAlFinal(lunes, {12, 1, "Lunes"});

    insertarAlFinal(martes, {9, 3, "Martes"});
    insertarAlFinal(martes, {11, 8, "Martes"});

    insertarAlFinal(miercoles, {8, 2, "Miercoles"});
    insertarAlFinal(miercoles, {9, 5, "Miercoles"});
    insertarAlFinal(miercoles, {10, 10, "Miercoles"});

    insertarAlFinal(jueves, {14, 13, "Jueves"});
    insertarAlFinal(jueves, {15, 9, "Jueves"});
    insertarAlFinal(jueves, {16, 11, "Jueves"});

    insertarAlFinal(viernes, {17, 4, "Viernes"});
    insertarAlFinal(viernes, {18, 12, "Viernes"});
    insertarAlFinal(viernes, {19, 7, "Viernes"});

    // imprimirLista(lunes);
    // imprimirLista(martes);
    // imprimirLista(miercoles);
    // imprimirLista(jueves);
    // imprimirLista(viernes);

    fusionarLista(lunes, martes);
    imprimirLista(lunes);
    cout << endl;

    fusionarLista(lunes, miercoles);
    imprimirLista(lunes);
    cout << endl;

    fusionarLista(lunes, jueves);
    imprimirLista(lunes);
    cout << endl;

    fusionarLista(lunes, viernes);
    imprimirLista(lunes);

    return 0;
}
