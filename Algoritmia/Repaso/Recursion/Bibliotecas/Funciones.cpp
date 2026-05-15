#include <iostream>
using namespace std;

#include "Funciones.h"

int contarPares(int posX, int posY, int n, int m, int matriz[][5]) {
    // CASO BASE
    if (posX == n) return 0;

    // si es que es par, aumentamos el contador
    int contador = 0;
    if (matriz[posX][posY] % 2 == 0 and matriz[posX][posY] != 0) contador++;

    if (posY < m-1) {
        // Recorremos a la derecha hasta que nos pasemos
        contador += contarPares(posX, posY + 1, n, m, matriz);
    }
    else {
        // Si nos excedemos del limite, bajamos y repetimos
        contador += contarPares(posX + 1, 0, n, m, matriz);
    }
    return contador;
}

int dron(int posX, int posY, int objX, int objY,int n, int m, int bateria, int viento[][5]) {
    // CASO BASE
    if (posX < 0 or posX >= n or posY < 0 or posY >= m) return 0;
    if (bateria < 0) return 0;
    if (posX == objX and posY == objY) return 1;

    bateria -= viento[posX][posY];
    // verificamos cada direccion
    // Hacia la derecha
    if (dron(posX, posY+1, objX, objY, n, m, bateria, viento)) return 1;
    // Hacia abajo
    if (dron(posX+1, posY, objX, objY, n, m, bateria, viento)) return 1;

    return 0; // si ninguno llega, da 0
}

void sonda(int mat[][7], int N, int M,
           int x, int y,
           int dx, int dy,
           int E, int scan) {

    if (scan >= 0) {
        // se mueve en horizontal
        // entonces escanea en la columna Y
        if (dy != 0) {
            if (scan == N) return; // significa que ya revise toda la columna
            if (mat[scan][y] < 0) {
                cout << "Anomalia en: " << "(" << scan << ", " << y << ")" << endl;
            }
            sonda(mat, N, M, x , y , dx, dy, E, scan + 1);
        }
        if (dx != 0) {
            if (scan == M) return; // significa que reviso toda la fila
            if (mat[x][scan] < 0) {
                cout << "a en: " << "(" << x << ", " << scan << ")" << endl;
            }
            sonda(mat, N, M, x , y , dx, dy, E, scan + 1);
        }

    } else {
        sonda(mat, N, M, x, y , dx, dy, E, 0);

        int nx = x+dx;
        int ny = y+dy;

        bool choque = (nx < 0 or nx >= N or ny < 0 or ny >= M or mat[nx][ny] == 99);

        if (choque) {
            dx = -dx;
            dy = -dy;
            E--;
            if (E == 0) return;
            if (E > 0) sonda(mat, N, M, x+dx, y+dy , dx, dy, E, -1);
        }
        else {
            if (E == 0) return;
            if (E > 0) sonda(mat, N, M, x+dx , y+dy , dx, dy, --E, -1);
        }
    }
}