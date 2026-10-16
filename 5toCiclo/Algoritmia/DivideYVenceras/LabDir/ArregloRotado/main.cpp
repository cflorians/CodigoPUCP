#include <iostream>
using namespace std;

int buscaCodigo(int A[], int ini, int fin, int cod) {
    // CASO BASE
    if (ini > fin) return -1;
    // PARTE RECURSIVA
    int mid = (ini+fin)/ 2;
    if (A[mid] == cod) return mid;
    if (A[mid] < A[fin]) {
        // ahora derecha
        // return buscaCodigo(A, mid+1, fin, cod);
        if (cod >= A[ini] and cod < A[mid]) {
            // entonces vamos a la izq
            return buscaCodigo(A, ini, mid-1, cod);
        }
        else {
            // si no derecha
            return buscaCodigo(A, mid+1, fin, cod);
        }
    }
    else {
        // ahora derecha
        // return buscaCodigo(A, ini, mid-1, cod);
        if (cod > A[mid] and cod <= A[fin]) {
            // vamos a la derecha
            return buscaCodigo(A, mid+1, fin, cod);
        }
        else {
            // vamos a la izq
            return buscaCodigo(A, ini, mid-1, cod);
        }
    }
}

int main() {
    int arr[]{4,5,6,7,8,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int codeBuscar = 7;

    cout << buscaCodigo(arr, 0, n-1, codeBuscar) << endl;

    return 0;
}
