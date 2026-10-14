#include <iostream>
#include <iomanip>
using namespace std;

const int N = 8; // cant fechas
const int K = 2; // numero compras

int max_ganancia(int meses[N+1]) {
    // Estrategia: PROGRAMACION DINAMICA (iterativa, bottom-up).
    // pd[k][i] = maxima ganancia con a lo sumo k compras hasta el mes i.
    // Fila k=0 (cero compras) y columna i=0 (cero meses) valen 0.
    // Para cada celda se elige la mejor de dos opciones:
    //   1) no vender el mes i:  pd[k][i-1]
    //   2) vender el mes i, habiendo comprado en un mes j <= i:
    //      meses[i] + (pd[k-1][j] - meses[j])
    // El maximo sobre j se va acumulando en "mejor" para no usar un 3er bucle.
    int pd[K+1][N+1]{};
    int mejor;

    for (int k = 1; k <= K; k++) {
        // mejor = max sobre j de (pd[k-1][j] - meses[j]), empieza con j=1
        mejor = pd[k-1][1] - meses[1];
        for (int i = 1; i <= N; i++) {
            // se considera comprar en el mes i (para ventas futuras)
            if (pd[k-1][i] - meses[i] > mejor) mejor = pd[k-1][i] - meses[i];
            // opcion 1: no vender el mes i
            pd[k][i] = pd[k][i-1];
            // opcion 2: vender el mes i
            if (meses[i] + mejor > pd[k][i]) pd[k][i] = meses[i] + mejor;
        }
    }

    // IMPRIMIMOS LA MATRIZ DE SOLUCIONES PARCIALES
    cout << "Matriz de soluciones parciales (filas: k compras, columnas: mes i)" << endl;
    cout << left << setw(6) << "k/i";
    for (int i = 0; i <= N; i++) cout << left << setw(6) << i;
    cout << endl;
    for (int k = 0; k <= K; k++) {
        cout << left << setw(6) << k;
        for (int i = 0; i <= N; i++) cout << left << setw(6) << pd[k][i];
        cout << endl;
    }

    cout << "La ganancia maxima sera: ";

    return pd[K][N];
}

int main() {

    int meses[N+1]{0,120,100,150,125,120,150,200,250};

    cout << max_ganancia(meses) << endl;

    return 0;
}