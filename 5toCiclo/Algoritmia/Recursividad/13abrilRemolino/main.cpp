#include <iostream>
using namespace std;

#define MAX 10

void recorreRobot(int x, int y, int n, int m, int almacen[][MAX]) {
    // CASO BASE
    if (x>=n or y>=m) return; // si es que es una matriz cuadrada de n y m par
    if (x == n-1 and y == m-1) cout << almacen[x][y]; // es decir, nos quedo una celda en matriz de lado impar
    if (x == n-1) {
        for (int i = y; i <= m-1; i++) {
            cout << almacen[x][i] << " ";
        }
        return;
    }
    if (y == m-1) {
        for (int i = x; i <= n-1; i++) {
            cout << almacen[x][i] << " ";
        }
        return;
    }

    for (int i = y; i < m-1 ; i++) { // voy a la derecha
        cout <<  almacen[x][i] << " ";
    }
    for (int i = x; i < n-1 ; i++) { // voy hacia abajo
        cout <<  almacen[i][m-1] << " ";
    }
    for (int i = m-1; i>y ; i--) { // voy a la izquierda
        cout << almacen[n-1][i] << " ";
    }
    for (int i = n-1; i>x ; i--) { // voy hacia arriba
        cout << almacen[i][y] << " ";
    }
    // PARTE RECURSIVA
    recorreRobot(x+1, y+1, n-1, m-1, almacen);
}

int main(int argc, char** argv) {

    int contador = 1;
    int almacen[MAX][MAX]{};
    int n = 4, m = 6;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            almacen[i][j] = contador++;
        }
    }

    recorreRobot(0, 0, n, m, almacen);
    
    return 0;
}
