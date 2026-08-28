#include <iostream>
using namespace std;

#define N 8

// El problema consiste en colocar N reinas en un
// tablero de NxN, sin que se puedan atacar entre si

void initBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << (j==N-1 ? "\n" : "  ");
        }
    }
    cout << endl;
}

bool valid(int currentRow, int currentCol, char board[N][N]) {
    // revisamos hacia la izquierda
    for (int i = currentCol; i>=0; i--) {
        if (board[currentRow][i] == 'Q') return false;
    }
    // ahora revisamos la diagonal superior izquierda
    for (int i = currentRow, j = currentCol; i>=0 and j>=0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    // ahora revisamos la diagonal hacia abajo a la izquierda
    for (int i = currentRow, j = currentCol; i<N and j>=0; i++, j--) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solve(int currentCol, char board[N][N]) {
    // BASE CASE
    // si llegamos al final imprimimos y retornamos
    static int solutions = 1;
    if (currentCol == N) {
        cout << "Solution " << solutions++ << " FOUND!" << endl;
        printBoard(board);
        return;
    }
    // RECURSION PART
    // vamos verificando cada fila y si es que podemos colocar alli la reina
    for (int row = 0; row < N; row++) {
        if (valid(row, currentCol, board)) {
            // si es que no esta usada, entonces seguimos
            board[row][currentCol] = 'Q';
            solve(currentCol + 1, board);
            // para regresar al estado original
            board[row][currentCol] = '.';
        }
    }
}

int main() {
    char board[N][N] {};
    initBoard(board);
    solve(0, board);

    return 0;
}
