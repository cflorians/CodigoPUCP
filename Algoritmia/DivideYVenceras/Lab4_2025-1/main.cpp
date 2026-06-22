#include <iostream>
using namespace std;

int buscaMax(int A[], int ini, int fin) {
    // CASO BASE
    if (ini == fin) return ini;
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    if (A[mid] < A[mid+1]) return buscaMax(A, mid+1, fin);
    else return buscaMax(A, ini, mid-1);
}

int buscaDia(int A[], int ini, int fin, int buscado) {
    // CASO BASE
    if (ini == fin) return ini;
    // PARTE RECURSIVA
    int mid = (ini + fin) / 2;
    if (A[mid] < buscado) return buscaDia(A, mid+1, fin, buscado);
    else return buscaDia(A, ini, mid-1, buscado);
}

int main() {

    int ventas_original[] = {50,80,120,160,210,180,140};
    int nOrg = sizeof(ventas_original) / sizeof(ventas_original[0]);
    int ventas_nueva[] = {300,380,450,570,620,740,860};
    int nNueva = sizeof(ventas_nueva) / sizeof(ventas_nueva[0]);

    // Buscamos el dia maximo en en el arreglo original
    int dia = buscaMax(ventas_original, 0, nOrg-1);
    cout << "Pico de ventas_original: Dia " << dia << " - Valor " << ventas_original[dia] << endl;

    // ahora buscamos en que dia se supera ese valor
    int diaNuevo = buscaDia(ventas_nueva, 0, nNueva-1, ventas_original[dia]);
    cout << "Primer dia en ventas_nueva que supera el pico: Dia " << diaNuevo << " - Valor " << ventas_nueva[diaNuevo] << endl;

    return 0;
}
