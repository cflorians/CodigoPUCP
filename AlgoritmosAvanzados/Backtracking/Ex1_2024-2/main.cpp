#include <iostream>
using namespace std;

const int N=4;

void comb_parentesis_balanceados(char cadena[], int actual, int cant_apertura, int cant_cierres) {
    // CASO BASE
    if (actual == N<<1) {
        if (cant_apertura == cant_cierres) {
            cout << cadena << endl;
        }
        return;
    }

    // PARTE RECURSIVA
    // CASO 1. colocamos apertura
    if (cant_apertura < N) {
        //ponemos
        cadena[actual] = '(';
        //llamamos
        comb_parentesis_balanceados(cadena, actual+1, cant_apertura+1, cant_cierres);
        // no es necesario deshacer, porque se sobreescribe cadena[actual]
    }
    // CASO 2. colocamos cierre
    if (cant_cierres < cant_apertura) {
        // colocamos
        cadena[actual] = ')';
        // llamamos a la siguiente
        comb_parentesis_balanceados(cadena, actual+1, cant_apertura, cant_cierres+1);
    }
}

int main() {

    char cadena[(N<<1) + 1]; // N<<1 = N*2
    cadena[N<<1] = '\0';
    int cant_apertura = 0;
    int cant_cierres = 0;

    comb_parentesis_balanceados(cadena, 0, cant_apertura, cant_cierres);


    return 0;
}
