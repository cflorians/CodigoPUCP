#include <iostream>
#include <iomanip>
using namespace std;
#define N 8
#define M 8
enum VECTOR {VX, VY};
int movs[8][2] {
    {-1,-1},
    {-1,0},
    {-1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1}
};

void imprimeTablero(int tablero[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << right <<setw(2) << setfill('0') << tablero[i][j] << setfill(' ') << "  ";
        }
        cout << endl;
    }
}

int resolver(int tablero[N][M], int x, int y, int numMov) {
    // CASOS BASE
    // posición fuera del tablero
    if (x < 0 or y < 0  or x >= N or y >= M) return 0;
    // posición ya visitada
    if (tablero[x][y] != 0) return 0;

    // cuando llegamos aqui, ya verificamos que sea una casilla valida
    tablero[x][y] = numMov;
    // si el tablero llega al final, imprimimos y retornamos
    if (numMov == 64) {
        imprimeTablero(tablero);
        return 1;
    }

    // ahora probamos todos los movimientos posibles
    // para ver a donde vamos ahora
    for (int i=0; i<8; i++) {
        int newX = x + movs[i][VX];
        int newY = y + movs[i][VY];

        if (resolver(tablero, newX, newY, numMov+1)) {
            return 1;
        }
    }

    tablero[x][y] = 0;

    return 0;
}

int sumFila(int tablero[N][M], int f, int c, int acum) {
    if (c == M) return acum;
    return sumFila(tablero, f, c+1, acum + tablero[f][c]);
}
int sumCol(int tablero[N][M], int f, int c, int acum) {
    if (f == N) return acum;
    return sumCol(tablero, f+1, c, acum + tablero[f][c]);
}
int sumDiag1(int tablero[N][M], int i, int acum) {
    if (i == N) return acum;
    return sumDiag1(tablero, i+1, acum + tablero[i][i]);
}
int sumDiag2(int tablero[N][M], int i, int acum) {
    if (i == N) return acum;
    return sumDiag2(tablero, i+1, acum + tablero[i][N-1-i]);
}
bool verificarFila(int tablero[N][M], int f, int s) {
    if (f == N) return true;
    if (sumFila(tablero, f, 0, 0) != s) return false;
    return verificarFila(tablero, f+1, s);
}
bool verificarCol(int tablero[N][M], int c, int s) {
    if (c == M) return true;
    if (sumCol(tablero, 0, c,0) != s) return false;
    return verificarCol(tablero, c+1, s);
}


bool verificarCuadradoMagico(int tablero[N][M]) {
    int sumMagica = sumFila(tablero, 0, 0, 0); // constante que usaremos de referencia

    if (not verificarFila(tablero, 0, sumMagica)) return false;
    if (not verificarCol(tablero, 0, sumMagica)) return false;
    if (sumDiag1(tablero, 0, 0) != sumMagica) return false;
    if (sumDiag2(tablero, 0, 0) != sumMagica) return false;

    return true;
}

int main() {

    int tablero[N][M]{};

    int f = 4;
    int c = 4;

    resolver(tablero,c,f,1);

    // int tableroMagico[N][M] = {
    //     {64,  2,  3, 61, 60,  6,  7, 57},
    //     { 9, 55, 54, 12, 13, 51, 50, 16},
    //     {17, 47, 46, 20, 21, 43, 42, 24},
    //     {40, 26, 27, 37, 36, 30, 31, 33},
    //     {32, 34, 35, 29, 28, 38, 39, 25},
    //     {41, 23, 22, 44, 45, 19, 18, 48},
    //     {49, 15, 14, 52, 53, 11, 10, 56},
    //     { 8, 58, 59,  5,  4, 62, 63,  1}
    // };

    cout << "Es cuadrado magico?: " << (verificarCuadradoMagico(tablero) ? "Si":"No") << endl;

    return 0;
}
