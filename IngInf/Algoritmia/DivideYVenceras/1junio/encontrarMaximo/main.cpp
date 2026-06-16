#include <iostream>
using namespace std;

int maximoDV(int A[], int ini, int fin) {
    // CASO BASE
    // cuando tenemos un solo elemento, entonces ese es el máximo
    if (ini >= fin) {
        return A[ini];
    }
    // PARTE RECURSIVA
    int mid = (ini+fin)/2;
    if (A[mid] < A[mid+1]) {// significa que esta en crecimiento, entonces entramos a la derecha
        return maximoDV(A, mid+1, fin);
    }
    else { // significa que esta en decrecimiento, entonces entramos a la izq
        return maximoDV(A, ini, mid);
    }
}
int main() {
    int A[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n = sizeof(A)/sizeof(A[0]);

    cout << maximoDV(A, 0, n-1) << endl;

    return 0;
}
