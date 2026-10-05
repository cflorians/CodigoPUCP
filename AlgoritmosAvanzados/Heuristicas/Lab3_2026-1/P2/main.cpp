#include <iostream>
using namespace std;

#define CAP 10
#define N 6

/*  Estrategia: Algoritmo voraz
 *  Objetivo: Llegar de una ciudad inicio a una fin
 *  Selección: Se elige a la ciudad no visitada más lejana alcanzale con el combustible restante
 */

void once(int costos[][N], bool grifos[], int inicio, int fin) {
    int restante = CAP;
    bool visitados[N]{};
    int actual = inicio;
    int candidato, costoCandidato;

    cout << "Ruta: " << inicio << ' ';
    while (actual != fin) {
        visitados[actual] = true;
        candidato = -1;
        costoCandidato = -1;
        // vamos candidato por candidato
        for (int i = 0; i < N; i++) {
            if (costos[actual][i] and costos[actual][i] <= restante) {
                // si es 0 o no podemos llegar, no entrara
                if (costos[actual][i] > costoCandidato and not visitados[i]) {
                    costoCandidato = costos[actual][i];
                    candidato = i;
                }
            }
        }

        if (candidato == -1) {
            cout << "No hay solucion" << endl;
            cout << "Combustible restante: " << restante << endl;
            return;
        }
        // aca ya tenemos a nuestro candidato ideal
        actual = candidato;
        restante -= costoCandidato;
        if (grifos[actual]) restante = CAP;
        cout << actual << " ";
    }
    cout << endl;
}

int main() {
    // 5 ciudades
    // int costos[N][N] {
    //     {0,4,7,5,0},
    //     {4,0,3,2,6},
    //     {7,3,0,4,7},
    //     {5,2,4,0,3},
    //     {0,6,7,3,0}
    // };
    // bool grifos[N]{true, false, true, false, false};

    // 6 ciudades
    int costos[N][N] {
        {0,4,8,5,0,0},
        {4,0,3,2,6,0},
        {8,3,0,4,7,0},
        {5,2,4,0,3,4},
        {0,6,7,3,0,9},
        {0,0,0,4,9,0}
    };
    bool grifos[N]{true, false, true, false, false, false};

    once(costos, grifos, 0, 5);

    return 0;
}
