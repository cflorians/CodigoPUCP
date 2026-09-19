#include <iostream>
using namespace std;

const int inicio = 0;
const int fin = 1;
const int pago = 2;

const int bono = 15;

const int cantEventos = 6;


int maximaGanancia(int eventos[cantEventos][3]) {
    int dp[cantEventos+1]{};

    // caso base
    dp[0] = 0;

    for (int i=1; i<=cantEventos; i++) {
        dp[i] = eventos[i-1][pago];
        for (int j=1; j <= i-1; j++) {
            if (eventos[i-1][inicio] >= eventos[j-1][fin] + 1) {
                int candidato = dp[j] + eventos[i-1][pago];
                if (eventos[i-1][inicio] == eventos[j-1][fin] + 1) candidato += bono;
                dp[i] = max(dp[i], candidato);
            }
        }
    }

    int maxGain = 0;
    for (int i=1; i<=cantEventos; i++) {
        if (maxGain < dp[i]) maxGain = dp[i];
    }
    return maxGain;
}

void p1() {
    int eventos[cantEventos][3] {
        {1,3,30},
        {4,5,10},
        {6,8,60},
        {6,8,20},
        {5,9,50},
        {8,12,40}
    };

    cout << "La ganancia final maxima es: " << maximaGanancia(eventos) << endl;
}

const int costaSur = 6000, costaNorte = 12000, sierraCentro = 8000;
const int sierraNorte = 12000, sierraSur = 15000, oriente = 4500;

const int limaEnviado = 35200, extranjeroEnviado = 2300;

const int extranjeroMin = 2001;
const int extranjeroMax = 7500;

void validarActas() {
    int rango = extranjeroMax - extranjeroMin + 1;
    bool dp[rango][3]; // columna 0: val.1, columna 1: val.2, columna 2: val.3

    bool val1 = (limaEnviado + extranjeroEnviado + costaSur + costaNorte +
             sierraCentro + sierraNorte + sierraSur + oriente) == 95000;

    for (int e = 0; e < rango; e++) {
        int extranjero = extranjeroMin + e;

        dp[e][1] = (extranjero + oriente == 7000);

        dp[e][2] = abs((extranjero + oriente + costaSur + sierraCentro) -
                        (costaNorte + sierraNorte)) == 3000;
    }

    int indice = extranjeroEnviado -extranjeroMin;

    cout << "Total: " << (val1 ? "correcta" : "incorrecta") << endl;
    cout << "Oriente+Extranjero: " << (dp[indice][1] ? "correcta" : "incorrecta") << endl;
    cout << "Diferencia: " << (dp[indice][2] ? "correcta" : "incorrecta") << endl;
}

void p2() {
    validarActas();
}

int main() {
    p1();
    p2();

    return 0;
}
