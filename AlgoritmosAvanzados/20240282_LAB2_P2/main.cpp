#include <iostream>
using namespace std;

#define N 9
#define M 5

// NOMBRE:      Florian Silva Carlos
// CODIGO:      20240282
// DESCRIPCIÓN: El programa usa programación dinamica para resolver el problema, se va recorriendo
//              la matriz casilla por casilla, verificando en cada una si es que el robot
//              se puede mover a la casilla actual, verificando que sea un espacio libre y
//              que cuente con alguna posición valida arriba dp[fila-1][columna] o a la
//              izquierda dp[fila][columna-1] para simular el movimiento del robot (solo derecha y abajo).

bool robot(char terreno[N][M]) {
    bool dp[N+1][M+1]{};
    // se le pone +1 para que haya una fila y una columna en 0 que rodeen
    // el mapa por la izquierda y arriba y funcionen como caso base

    // la casilla donde empezamos es true, de aqui se "esparce" la solución
    dp[1][1] = true;

    for (int fila = 1; fila <= N; fila++) {
        for (int columna = 1; columna <= M; columna++) {
            if (not(fila == 1 and columna == 1)) {
                // verificamos que sea una casilla valida
                // debe tener un espacio libre y que tenga por lo menos un 1 (true) a la izquierda o arriba
                if (terreno[fila-1][columna-1] == ' ' and (dp[fila-1][columna] or dp[fila][columna-1])) {
                    dp[fila][columna] = true;
                }
                else { // si es que no cumple alguna de las anteriores
                    dp[fila][columna] = false;
                }
            }
        }
    }

    // imprimimos dp (solo la parte del mapa, no la columna y fila de 0 de la izquierda y arriba)
    for (int fila = 1; fila <= N; fila++) {
        for (int columna = 1; columna <= M; columna++) {
            cout << dp[fila][columna] << "    ";
        }
        cout << endl;
    }
    cout << endl;

    return dp[N][M]; // si es false no hay salida, si es true si la hay
}

int main() {

    char terreno[N][M] {
        {' ',' ',' ','*','*'},
        {' ',' ',' ','*',' '},
        {' ',' ','*',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ','*','*',' ','*'},
        {' ','*','*',' ','*'},
        {' ','*',' ','*',' '},
        {'*','*','*','*',' '},
        {' ',' ',' ',' ',' '},
    };

    cout << (robot(terreno) ? "Si encontró salida":"No encontró salida") << endl;

    return 0;
}
