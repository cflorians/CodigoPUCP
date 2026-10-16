#include <iostream>
using namespace std;

#include "Bibliotecas/Lista.h"
#include "Bibliotecas/Funciones.h"

int main() {

    Lista bowser, peach, donkey, guerreros;

    construir(bowser);
    construir(peach);
    construir(donkey);
    construir(guerreros);

    int n = 2;
    int cantTotal = 12;

    insertarFinal(guerreros, {723});
    insertarFinal(guerreros, {182});
    insertarFinal(guerreros, {123});
    insertarFinal(guerreros, {262});
    insertarFinal(guerreros, {851});
    insertarFinal(guerreros, {352});
    insertarFinal(guerreros, {653});
    insertarFinal(guerreros, {103});
    insertarFinal(guerreros, {561});
    insertarFinal(guerreros, {841});
    insertarFinal(guerreros, {391});
    insertarFinal(guerreros, {241});

    imprimir(guerreros);

    distribuirGuerreros(guerreros, bowser, peach, donkey);

    imprimir(bowser);
    cout << "Nivel de ataque del ejercito 1: " << fuerza(bowser) << endl;
    imprimir(peach);
    cout << "Nivel de ataque del ejercito 2: " << fuerza(peach) << endl;
    imprimir(donkey);
    cout << "Nivel de ataque del ejercito 3: " << fuerza(donkey) << endl;

    batalla(bowser, peach, donkey, n);

    return 0;
}
