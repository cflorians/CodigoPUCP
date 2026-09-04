#include <iostream>
#include <iomanip>
using namespace std;

enum NUMS {X,Y,Z};

void resolver(int nivel, int usados[], int valores[], int sParcial ,int S);

void probarDigito(int d, int nivel, int usados[], int valores[], int sParcial, int S) {
    if (d > 9) return;

    if (not usados[d]) { // si es que el número no esta en usados
        int nuevaSuma = sParcial + d;

        if (nuevaSuma <= S) {
            usados[d] = 1;
            valores[nivel] = d;

            resolver(nivel + 1, usados, valores, nuevaSuma, S);

            usados[d] = 0; // backtracking
        }
    }

    probarDigito(d+1, nivel, usados, valores, 0, S);
}

void resolver(int nivel, int usados[], int valores[], int sParcial, int S) {
    // CASO BASE
    // si ya elegi los 3
    if (nivel == 3) {
        // si suman S
        if (valores[X] + valores[Y] + valores[Z] == S) {
            cout << valores[X] << " "
                 << valores[Y] << " "
                 << valores[Z] << endl;
        }
        return;
    }

    // parte recursiva
    probarDigito(1, nivel, usados, valores, sParcial, S);
}

int main() {

    int S = 8;
    int usados[10]{};
    int valores[3]{};

    resolver(0, usados, valores, 0, S);

    return 0;
}
