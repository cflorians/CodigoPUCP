#include <iostream>
using namespace std;

int encuentraMayorIncremento(int A[], int ini, int med, int fin) {
    int contador = 0;
    int contador_izq = 1, contador_der = 1;
    for (int i=med; i > ini; i--) { // analizo los dias hacia la izq
        if (A[i-1]<A[i]) contador_izq++;
        else break;
    }
    for (int i=med+1; i < fin; i++) { // analizo los dias hacia la der
        if (A[i]<A[i+1]) contador_der++;
        else break;
    }
    if (A[med]<A[med+1]) { // si realmente hay secuencia, sumo los contadores
        return contador_izq + contador_der;
    }
    else return 0;
}

int maximo3(int a, int b, int c){
    if (a>=b && a>=c) return a;
    if (b>=a && b>=c) return b;
    if (c>=a && c>=b) return c;
}

int rebroteCovid(int A[], int ini, int fin) {
    int maximo_incremento_izq, maximo_incremento_der, maximo_incremento_centro;
    // CASO BASE
    if (ini == fin) return 1; // 1 dia
    // PARTE RECURSIVA
    int med = (ini + fin) / 2;
    maximo_incremento_izq = rebroteCovid(A, ini, med);
    maximo_incremento_der = rebroteCovid(A, med + 1, fin);
    maximo_incremento_centro = encuentraMayorIncremento(A, ini, med, fin);
    return maximo3(maximo_incremento_izq, maximo_incremento_der, maximo_incremento_centro);
}

int main() {

    int A[]{10,20,15,12,10,13,18};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "Intervalo máximo de incremento: " << rebroteCovid(A, 0, n-1) << endl;

    return 0;
}
