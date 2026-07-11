#include <iostream>
using namespace std;

int buscaZonaCaries(int A[], int ini, int fin, int T) {
    // CASO BASE
    if (ini >= fin) {
        if (A[ini] < T) return ini;
        else return -1;
    }

    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    if (A[mid] < T) return buscaZonaCaries(A, ini, mid, T);
    else return buscaZonaCaries(A, mid+1, fin, T);
}

int main() {

    int A[] {98, 95, 93, 90, 72, 60, 55, 50};
    int n = sizeof(A)/sizeof(A[0]);
    int T = 98;

    int indiceZonaCaries = buscaZonaCaries(A, 0, n-1, T);

    if (indiceZonaCaries != -1) {
        cout << "Primera zona con caries clinica detectada en la posicion " << indiceZonaCaries << endl;
        cout << "Densidad registrada: " << A[indiceZonaCaries] << endl;
    }
    else {
        cout << "No se detecta caries clinica" << endl;
    }

    return 0;
}
