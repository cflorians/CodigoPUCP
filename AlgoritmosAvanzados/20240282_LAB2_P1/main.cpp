#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

enum TOMA{PUNTOS, LO_TOMO};

// NOMBRE:      Florian Silva Carlos
// CODIGO:      20240282
// DESCRIPCIÓN: El programa usa programación dinamica para resolver el problema,
//              este va avanzando paso a paso, pero en cada uno evalua si es más
//              conveniente hacer un salto de 2 pasos, si es que si, entonces tomamos
//              el valor de dp de hace 2 casillas y le sumamos los puntos actuales,
//              dp[N][LO_TOMO], siempre será 1 (termina exactamente en la casilla N)

int recoleccionDePuntos(vector<int>& puntos, int N) {
    int dp[N+1][2]{};
    // dp[i][puntos] = el maximo de puntos alcanzables para los primeros i elementos de el vector puntos
    // dp[i][LO_TOMO] = 1 si estoy contando ese valor al final, 0 si no lo estoy contando
    //                  (simula pasos de 1 y 2 casillas)

    // Caso Base
    // en el paso 0 no puedo tomar nada ni sumar puntos
    dp[0][PUNTOS] = 0;
    dp[0][LO_TOMO] = 0;

    int iPuntos;

    for (int i = 1; i <= N; i++) {
        // como el arreglo de puntos no tiene 7 elementos, ajustamos su indice con i-1
        iPuntos = i-1;
        // lo tomamos
        dp[i][PUNTOS] = dp[i-1][PUNTOS] + puntos[iPuntos];
        dp[i][LO_TOMO] = 1;

        // evaluamos si es que un paso de 2 sea mas conveniente
        if (i != 1 and puntos[iPuntos-1] <= puntos[iPuntos] and dp[i-2][LO_TOMO] == 1) {
            // si es que los puntos en la posición actual son mayores a los de la posicion anterior
            // evaluamos si es posible cambiar el salto de 1 a salto de 2 con dp[i-2][LO_TOMO],
            // ese valor debe ser 1 para verificar que sea un salto de 2
            dp[i][PUNTOS] = dp[i-2][PUNTOS] + puntos[iPuntos];
            // actualizamos el valor de LO_TOMO del anterior
            dp[i-1][LO_TOMO] = 0;
        }
    }

    // mostramos dp
    cout << "i   PUNTOS  LO_TOMO?" << endl;
    for (int i = 0; i <= N; i++) {
        cout << left << setw(6) << i
             << right  << setw(2) << dp[i][PUNTOS]
             << setw(8) << dp[i][LO_TOMO] << endl;
    }

    // imprimimos solución
    cout << endl << "Resultado: " << dp[N][PUNTOS] << endl;

    return dp[N][PUNTOS];
}

int main() {

    int N = 6;
    vector<int> puntos {5,8,-4,10,-3,7};

    recoleccionDePuntos(puntos, N);

    return 0;
}