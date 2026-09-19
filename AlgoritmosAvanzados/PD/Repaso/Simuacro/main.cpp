#include <iostream>
using namespace std;

const int blanco = 0;
const int azul_de_rojo = 1;
const int azul_de_blanco = 2;
const int rojo = 3;

long long cantFormasPintadas(int n) {
    long long dp[n+1][4]{}; // se usa n+1 para el caso base
    // el 4 es para recordar cual fue el color de la casilla i

    dp[1][blanco] = 1;
    dp[1][azul_de_blanco] = 0;
    dp[1][azul_de_rojo] = 0;
    dp[1][rojo] = 1;

    for (int i=2; i <= n; i++) {
        dp[i][blanco] = dp[i-1][rojo] + dp[i-1][azul_de_rojo];
        dp[i][rojo] = dp[i-1][blanco] + dp[i-1][azul_de_blanco];
        dp[i][azul_de_blanco] = dp[i-1][blanco];
        dp[i][azul_de_rojo] = dp[i-1][rojo];
    }

    return dp[n][blanco] + dp[n][rojo];
}

void p1() {
    int n = 3;
    cout << cantFormasPintadas(n) << endl;
}

void vueltos(int monedas[], int n, int numMonedas) {
    bool dp[n+1]{};
    // caso base
    dp[0] = true;

    for (int i=0; i < numMonedas; i++) {
        for (int j=n; 0 < j; j--) {
            if (j >= monedas[i] and dp[j-monedas[i]]) {
                dp[j] = true;
            }
        }
    }


    cout << "Se pueden brindar los siguientes cambios: ";
    for (int i=1; i <= n; i++) {
        if (dp[i]) cout << i << (i == n ? "\n" : ", ");
    }
}

void p2() {
    int monedas[3]{2,5,10};
    int numMonedas = sizeof(monedas)/sizeof(monedas[0]);
    int montoMaximo = 0;
    for (int i=0; i < numMonedas; i++) montoMaximo += monedas[i];

    vueltos(monedas, montoMaximo, numMonedas);
}

int minimasMonedas(int monedas[], int numMonedas, int n) {
    int dp[n+1];
    for (int i=0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    // caso base
    dp[0] = 0; // porque la minima cantidad de monedas para dar es 0

    for (int i=1; i <= n; i++) {
        for (int j=0; j < numMonedas; j++) {
            if (i >= monedas[j] and dp[i-monedas[j]] != INT_MAX) {
                if (dp[i-monedas[j]] +1 < dp[i]) dp[i] = dp[i-monedas[j]] + 1;
            }
        }
    }

    if (dp[n] == INT_MAX) return -1;
    return dp[n];
}

void p3() {
    int monedas[3]{2,5,10};
    int numMonedas = sizeof(monedas)/sizeof(monedas[0]);
    int monto = 20;

    cout << minimasMonedas(monedas, numMonedas, monto) << endl;
}

int main() {
    // LABORATORIO 2 / 2025-2

    // p1();
    // p2();
    p3();

    return 0;
}