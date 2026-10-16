#include <iostream>
using namespace std;

// int cuentaCeros(int A[], int n ,int ini, int fin) {
//     // CASO BASE
//     if (ini > fin) return 0;
//     if (A[0] == 0) return n;
//
//     // PARTE RECURSIVA
//     int med = (ini + fin) / 2;
//
//     if (A[med] == 1 and A[med + 1] == 0) return n - (med + 1);
//
//     // Si es 0 entonces seguimos buscando hacia la izquierda
//     if (A[med] == 0) return cuentaCeros(A, n, ini, med-1);
//     // Si es 1 entonces seguimos buscando hacia la derecha
//     else return cuentaCeros(A, n, med+1, fin);
// }

int cuentaCerosContador(int A[], int ini, int fin, int contador) {
    //CASO BASE
    if (ini == fin) {
        if (A[ini] == 1) return contador;
        if (A[ini] == 0) return contador + 1;
    }

    // PARTE RECURSIVA
    int med = (ini + fin) / 2;

    // Si es 0 entonces seguimos buscando hacia la izquierda
    if (A[med] == 0) return cuentaCerosContador(A, ini, med-1, contador + 1 + (fin-med));
    // Si es 1 entonces seguimos buscando hacia la derecha
    else return cuentaCerosContador(A, med+1, fin, contador);
}

int main() {

    int A[] = {1,1,1,1,0};
    int n = sizeof(A)/sizeof(A[0]);

    cout << cuentaCerosContador(A, 0, n-1, 0) << endl;

    return 0;
}
