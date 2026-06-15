#include <iostream>
using namespace std;

// Laboratorio dirigido de Divide y Venceras
int buscaCarie(int A[], int ini, int fin, int umb) {
    // CASO BASE
    if (ini == fin) {
        if (A[ini] > umb) return -1;
        return ini;
    }
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;

    // Si el umbral es menor que el medio, vamos a la izquierda
    if (umb < A[mid]) return buscaCarie(A, mid+1, fin, umb);
    // Si el umbral es mayor que el medio, vamos a la derecha
    else return buscaCarie(A, ini, fin-1, umb);
}


int main() {

    int arr[]{98, 95, 93, 90, 72, 60, 55, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int umbral = 80;

    cout << "Posicion de la carie: " << buscaCarie(arr, 0, n-1, umbral)+1 << endl;

    return 0;
}
