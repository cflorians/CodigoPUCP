#include <iostream>
using namespace std;
int busquedaBinaria(int A[], int k, int inicial, int final) {
    // CASO BASE
    // cuando se cruzan la posición inicial y final
    if (inicial > final) return -1;
    // cuando encontramos la posición

    // PARTE RECURSIVA
    int med = (inicial+final)/2;
    // si es igual devolvemos la posición
    if (A[med] == k) return med;
    // si es menor buscamos a la izquierda
    else if (k < A[med]) return busquedaBinaria(A, k, inicial, med-1);
    // si es mayor buscamos a la derecha
    else return busquedaBinaria(A, k, med+1, final);
}

int main() {
    int A[] = {1,5,7,9,12,15,16,20};
    int n=8;
    int k=16;
    int posicion = busquedaBinaria(A, k, 0, n-1);

    if (posicion != -1) {
        cout << posicion + 1 << endl;
    }
    else cout << k << " no se encuentra en el arreglo" << endl;

    return 0;
}
