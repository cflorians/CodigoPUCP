#include <iostream>
using namespace std;

int PotenciaMaxima(int A[],int ini, int fin) {
    // es como un buscaMayor
    // CASO BASE
    if (ini == fin) {
        return A[ini];
    }
    // PARTE RECURSIVA
    int mid = (ini + fin)/2;
    if (A[mid] <= A[mid+1]) { // quiere decir que esta a la derecha
        return PotenciaMaxima(A, mid+1, fin);
    }
    else { // quiere decir que el mayor estaria a la izq
        return PotenciaMaxima(A, ini, mid);
    }
}

int Radiacion(int A[], int ini, int fin, int cont) {
    // CASO BASE
    if (ini > fin) {
        return cont; // contador de NO POSITIVOS
    }
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    if (A[mid] > 0) { // A[medio] es positivo, entonces no lo considero en el analisis
        return Radiacion(A, ini, mid-1, cont);
    }
    else { // A[medio] es no-positivo, lo cuento y no lo considreco en el analisis
        return Radiacion(A, mid + 1, fin, cont + (mid-ini) + 1);
    }
}

int main() {
    int A[] = {0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int n = sizeof(A)/sizeof(int);
    int distancia = Radiacion(A, 0 , n-1, 0); // O(logN)

    cout << "La radiacion empieza en: " << distancia << endl;
    // vamos a buscar la potencia máxima desde donde empieza la radiación
    cout <<"Potencia máxima: "<<PotenciaMaxima(A,distancia,n-1)<<" megatones"<< endl; // O(logN)

    return 0;
}
