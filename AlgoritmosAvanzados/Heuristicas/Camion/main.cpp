#include <iostream>
using namespace std;

#define N 6
#define CAP 10

void rutaCamion(int mapa[][N], bool grifo[], int ini, int fin) {
    bool visitado[N]{};
    int ruta[N]{};
    int paso = 0;
    int actual = ini;
    int combustible = CAP;
    int candidato, costoCandidato;
    int mapaActual;
    int combustibleGastado = 0;

    while (actual != fin) {
        costoCandidato = CAP + 1;
        // marcamos el actual como visitado
        visitado[actual] = true;
        ruta[paso] = actual;
        paso++;
        // recorremos los vecinos
        candidato = -1;
        for (int i = 0; i < N; i++) {
            mapaActual = mapa[actual][i];
            if (mapaActual < costoCandidato and mapaActual != 0) {
                // validamos si es que entra y si es que no esta visitado
                if (not visitado[i] and mapaActual <= combustible) {
                    candidato = i;
                    costoCandidato = mapaActual;
                }
            }
        }
        if (candidato == -1) {
            cout << "Solución no encontrada" << endl;
            return;
        }
        // aca en candidato ya tenemos al más cercano
        actual = candidato;
        combustible -= costoCandidato;
        combustibleGastado += costoCandidato;
        if (grifo[actual]) combustible = CAP;
    }
    ruta[paso] = actual;
    cout << "Ruta: ";
    for (int i = 0; i <= paso; i++) {
        cout << ruta[i] << (i == paso ? "\n" : " -> ");
    }
    cout << "Combustible gastado: " << combustibleGastado << endl;
}

int main() {

    int mapa[N][N] {
        {0,3,6,0,0,0},
        {3,0,4,5,0,0},
        {6,4,0,2,7,0},
        {0,5,2,0,0,6},
        {0,0,7,0,0,3},
        {0,0,0,6,3,0}
    };
    bool grifo[N] {true, false, false, true, false, false};

    rutaCamion(mapa, grifo, 0, 5);
    rutaCamion(mapa, grifo, 0, 4);

    return 0;
}
