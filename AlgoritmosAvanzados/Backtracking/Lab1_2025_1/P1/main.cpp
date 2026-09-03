#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

enum VECTOR {VECX, VECY};

void imprimeTablero(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << right << setw(2) << setfill('0') << board[i][j] << setfill(' ') << "  ";
        }
        cout << endl;
    }
}

int buscaMov(int board[8][8], int x, int y, int mov[8][2], int numMov) {
    // validamos si estamos en una posición incorrecta
    if (x < 0 or y < 0 or 8 <= x or 8 <= y) {
        return 0;
    }
    // validamos si estamos en una posición ya visitada
    if (board[x][y] != 0) return 0;

    board[x][y] = numMov;

    // validamos si ya completamos el tablero
    if (numMov == 64) {
        imprimeTablero(board);
        return 1;
    }

    // buscamos una dirección a la que podamos movernos
    for (int i=0; i<8; i++) {
        // vamos dirección por direccion
        if (buscaMov(board, x + mov[i][VECX], y + mov[i][VECY], mov, numMov+1)) {
            return 1;
        }
    }

    board[x][y] = 0;

    return 0;
}

void resolver(int board[8][8], int xi, int yi) {
    // se pone -1 para que las columnas vayan de 1 a 8
    if (not (0 < xi and 0 < yi and xi <=8 and yi <=8)) {
        cout << "Posición inicial invalida" << endl;
        return;
    }

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

    buscaMov(board, xi-1, yi-1, mov, 1);
}

int main() {

    int board[8][8]{0};
    int xi = 4;
    int yi = 4;

    resolver(board, xi, yi);

    return 0;
}
