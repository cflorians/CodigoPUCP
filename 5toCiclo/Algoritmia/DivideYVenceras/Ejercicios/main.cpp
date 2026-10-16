#include <iostream>
using namespace std;

int evaluaPar(int A[], int ini, int fin) {
    // CASO BASE
    if (ini == fin) return A[ini];
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    // Si es que el medio es par, el mid+1 debe ser su pareja
    if (mid%2 == 0) {
        if (A[mid] == A[mid+1]) {
            // entonces debe estar a la derecha
            return evaluaPar(A, mid+2, fin);
        }
        else {
            // entonces voy a la izq
            return evaluaPar(A, ini, mid);
        }
    }
    // Si es que el medio es impar, el mid-1 debe ser su pareja
    else {
        if (A[mid] == A[mid-1]) {
            // Entonces tiene que ir a la derecha
            return evaluaPar(A, mid+1, fin);
        }
        else {
            // Si no es igual entonces voy a la izq
            return evaluaPar(A, ini, mid);
        }
    }
}

int cuentaCeros(int A[], int ini, int fin, int n) {
    // CASO BASE
    if (ini == fin) return (n-1)-fin;
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    if (A[mid] == 0) return cuentaCeros(A, ini, mid-1, n);
    else return cuentaCeros(A, mid+1, fin, n);
}

int minArregloRotado(int A[], int ini, int fin) {
    // CASO BASE
    if (ini == fin) return A[ini];
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    if (A[mid] < A[fin]) return minArregloRotado(A, 0, mid);
    else return minArregloRotado(A, mid+1, fin);
}

int sumaMaximaCruzada(int A[], int ini, int mid, int fin) {
    // Buscamos la suma maxima de la izq
    int suma = 0;
    int max_izq_cruzado = INT_MIN;
    for (int i = mid; i >= ini; i--) {
        suma = suma + A[i];
        if (suma > max_izq_cruzado) {
            max_izq_cruzado = suma;
        }
    }
    // Buscamos la suma maxima de la der
    suma = 0;
    int max_der_cruzado = INT_MIN;
    for (int i = mid+1; i <= fin; i++) {
        suma = suma + A[i];
        if (suma > max_der_cruzado) {
            max_der_cruzado = suma;
        }
    }
    // devolvemos la suma maxima cruzada
    return max_izq_cruzado + max_der_cruzado;
}
int max(int a, int b, int c) {
    if (a>b and a>c) return a;
    if (b>a and b>c) return b;
    if (c>a and c>b) return c;
}
int sumaMaxima(int A[], int ini, int fin) {
    // CASO BASE
    if (ini == fin) return A[ini];
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;

    int max_izq = sumaMaxima(A, ini, mid);
    int max_der = sumaMaxima(A, mid+1, fin);

    int max_cruzado = sumaMaximaCruzada(A, ini, mid, fin);

    return max(max_izq, max_der, max_cruzado);
}

int maximoArreglo(int A[], int ini, int fin) {
    // CASO BASE
    if (ini == fin) return A[ini];
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    if (A[mid] < A[mid+1]) return maximoArreglo(A, mid+1, fin);
    else return maximoArreglo(A, ini, mid);
}

int numInversiones(int A[], int ini, int fin) {
    // CASO BASE
    if (ini == fin) return 0;
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    int cantInt = 0;

    if (A[mid] > A[mid+1]) cantInt = 1;

    int inv_izq = numInversiones(A, ini, mid);
    int inv_der = numInversiones(A, mid+1, fin);

    cantInt += inv_izq + inv_der;

    return cantInt;
}

int main() {

    int A[] = {1,1,3,3,4,5,5,7,7,8,8};
    int n = sizeof(A)/sizeof(A[0]);
    cout << "1. " << evaluaPar(A, 0, n-1) << endl;

    int B[] = {1,1,1,0,0,0,0};
    n = sizeof(B)/sizeof(B[0]);
    cout << "2. " << cuentaCeros(B, 0, n-1, n) << endl;

    int C[] = {2,3,4,5,6};
    n = sizeof(C)/sizeof(C[0]);
    cout << "3. " << minArregloRotado(C, 0, n-1) << endl;

    int D[] = {-2,-5,6,-2,-3,1,5,-6};
    n = sizeof(D)/sizeof(D[0]);
    cout << "4. " << sumaMaxima(D, 0, n-1) << endl;

    int E[] = {8,10,20,80,100,200,400,500,3,2,1};
    n = sizeof(E)/sizeof(E[0]);
    cout << "5. " << maximoArreglo(E, 0, n-1) << endl;

    int F[] = {2,3,1,5,7,3,4,1,8,4};
    n = sizeof(F)/sizeof(F[0]);
    cout << "6. " << numInversiones(F, 0, n-1) << endl;

    return 0;
}
