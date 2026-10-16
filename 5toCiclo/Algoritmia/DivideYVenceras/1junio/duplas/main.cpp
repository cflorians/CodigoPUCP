#include <iostream>
using namespace std;

void buscaNoDupla(int A[], int inicio, int fin) {
    // CASO BASE
    // cuando nos quedmaos con un solo elemento, hemos encontrado la solución
    if (inicio == fin) {
        cout << A[fin] << endl;
        return;
    }
    // PARTE RECURSIVA
    int medio = (inicio + fin) / 2;
    // Hacemos el análisis de la posicion medio
    // se espera que las duplas comiencen en un indice par: 0, 2, 4, etc
    // y que terminan en uno impar: 1, 3, 5, etc;
    if (medio % 2 == 0) { // la posicion del medio es PAR, se espera que inicie dupla
        if (A[medio] == A[medio + 1]) {
            buscaNoDupla(A, medio + 2, fin);
        }
        else {
            buscaNoDupla(A, inicio, medio);
        }
    }
    else { // la posicion del medio es impar
        if (A[medio] == A[medio+1]) {
            buscaNoDupla(A, medio + 1, fin);
        }
        else {
            buscaNoDupla(A, inicio, medio-1);
        }
    }

}

int main() {

    int A[]{1,1,2,2,4,4,5,6,6};
    int n = sizeof(A)/sizeof(A[0]);

    buscaNoDupla(A, 0, n-1);

    return 0;
}
