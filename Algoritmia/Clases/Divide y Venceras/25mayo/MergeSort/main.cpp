#include <algorithm>
#include <iostream>
using namespace std;

void merge(int A[], int ini, int med, int fin) {
    int longitud1, longitud2;
    longitud1 = (med-ini) + 1;
    longitud2 = fin - med;

    int P[longitud1 + 1]; // aumento "un espacio" para el entero "muy grande"
    int Q[longitud2 + 1]; // aumento "un espacio" para el entero "muy grande"

    // Matriculamos el entero "muy grande"
    P[longitud1] = INT_MAX;
    Q[longitud2] = INT_MAX;

    // copiamos los valores a los subarreglos auxiliares
    for (int i = 0; i <= med; i++) {
        P[i-ini] = A[i]; // OJO AL PIOJO con los indices
    }
    for (int i=med+1; i <= fin; i++) {
        Q[i-(med+1)] = A[i]; // OJO AL PIOJO con los indices
    }
    // Ahora recien pasamos a hacer la mezcla
    int p = 0, q = 0;
    for (int i = ini; i <= fin; i++) {
        if (P[p] < Q[q]) A[i] = P[p++];
        else A[i] = Q[q++];
    }
}

void mergeSort(int A[], int ini, int fin) {
    // CASO BASE
    // Si el inicio coincide con el fin, es porque solo tenemos un elemento
    if (ini == fin) return;

    // PARTE RECURSIVA
    int med = (ini + fin) / 2;
    mergeSort(A, ini, med); // Mitad de la izquierda
    mergeSort(A, med + 1, fin); // Mitad de la derecha

    merge(A, ini, med, fin); // Mezclamos los subarreglos
}

int main() {
    int A[] = {11,4,7,1,6,3,2,9};
    int n = 8;

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    mergeSort(A,0,n-1);
    cout << "====ORDENANDO====" << endl;

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
