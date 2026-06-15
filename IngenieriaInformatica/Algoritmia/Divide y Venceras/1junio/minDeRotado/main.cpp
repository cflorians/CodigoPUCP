#include <iostream>
using namespace std;

int hallaMin(int A[], int ini, int fin) {
    // CASO BASE
    // con un elemento, ese sera el minimo
    if (ini == fin) {
        return A[ini];
    }
    // PARTE RECURSIVA
    int mid = (ini + fin)/2;
    if (A[mid] < A[fin]) { // entonces voy a la izq
        return hallaMin(A, ini, mid);
    }
    else { // si no voy a la derecha
        return hallaMin(A, mid + 1, fin);
    }
}

int main() {
    int A[] = {5,6,1,2,3,4};
    int n = sizeof(A)/sizeof(A[0]);

    cout << hallaMin(A, 0, n-1) << endl;

    return 0;
}
