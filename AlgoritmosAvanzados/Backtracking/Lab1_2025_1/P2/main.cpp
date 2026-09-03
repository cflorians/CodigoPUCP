#include <iostream>
using namespace std;

enum VECTOR {VECX, VECY};

#define N 5
#define M 6

bool valida(int almacen[N][M], int x, int y) {
    if (x == 0 and y ==0) return false;

    int mov[8][2] = {
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1},
    };

    for (int i = 0; i < 8; i++) {
        int newX = x+mov[i][VECX];
        int newY = y+mov[i][VECY];
        if (0 <= newX and newX < N and 0 <= newY and newY < M) {
            if (almacen[newX][newY] != 0) return false;
        }
    }

    return true;
}

void imprimirAlmacen(int almacen[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << almacen[i][j] << "  ";
        }
        cout << endl;
    }
}

void copia(int origen[N][M], int destino[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

int resolver(int almacen[N][M], int mejorAlmacen[N][M], int& max, int x, int y, int numPalet) {
    // CASOS BASE
    // si la pos esta fuera del tablero
    if (x < 0 or y < 0 or x >= N or y >= M) return 0;

    if (numPalet-1 >= max) {
        max = numPalet-1;
        copia(almacen,mejorAlmacen);
    }

    // ahora evaluamos si podemos colocar el palet
    if (valida(almacen, x, y)) {
        almacen[x][y] = numPalet;
        if (x == N-1) {
            resolver(almacen, mejorAlmacen, max, 0, y+1, numPalet+1);
        }
        else {
            resolver(almacen, mejorAlmacen, max, x+1, y, numPalet+1);
        }
        almacen[x][y] = 0;
    }
    if (x == N-1) {
        resolver(almacen, mejorAlmacen, max, 0, y+1, numPalet);
    }
    else {
        resolver(almacen, mejorAlmacen, max, x+1, y, numPalet);
    }

    return 0;
}

int main() {

    int almacen[N][M]{};
    int mejorAlmacen[N][M]{};
    int max = 0;

    resolver(almacen, mejorAlmacen, max, 0,0,1);

    cout << "El máximo es: " << max << endl;
    imprimirAlmacen(mejorAlmacen);

    return 0;
}
