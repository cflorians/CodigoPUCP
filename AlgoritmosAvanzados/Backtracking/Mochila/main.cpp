#include <iostream>
using namespace std;

const int W=10; // capacidad maxima
const int N=4; // cantidad de objetos

void printBest(int w, int v, bool carried[N]) {
    cout << "PESO: " << w << "kg  VALOR: " << v << endl;
    cout << "[";
    for (int i = 0; i < N; i++) {
        cout << carried[i] << (i==N-1 ? "]\n":", ");
    }
}


void solve(int actual,int weight, int value,int weights[N], int values[N], bool carried[N],
           int& bestWeight, int& maxValue, bool bestCarried[N]) {
    // BASE CASE
    // si alcanza el final del arreglo, imprimimos y regresamos
    if (actual == N) {
        return;
    }

    // RECURSION PART
    // tenemos 2 casos, tomar el elemento, o no tomarlo
    // caso 1, lo tomamos verificando si no excede el peso
    int acumWeight = weight+weights[actual];
    int actualValue = value+values[actual];
    if (acumWeight <= W) {
        carried[actual] = true;
        if (actualValue > maxValue) {
            maxValue = actualValue;
            for (int i = 0; i < N; i++) {
                bestCarried[i] = carried[i];
            }
            bestWeight = acumWeight;
        }
        solve(actual+1, acumWeight, actualValue, weights, values, carried,
         bestWeight,maxValue, bestCarried);
        carried[actual] = false;
    }
    // caso 2 no lo tomamos
    solve(actual+1, weight, value, weights, values, carried,
         bestWeight,maxValue, bestCarried);
}

int main(int argc, char** argv) {

    int weights[N]{2,3,4,5};
    int values[N]{3,4,5,6};
    bool carried[N]{false};
    int bestWeight = 0, maxValue = 0;
    bool bestCarried[N]{false};

    solve(0,0, 0, weights, values, carried,bestWeight,maxValue,bestCarried);

    // imprimimos la mejor solucion
    printBest(bestWeight,maxValue,bestCarried);

    return 0;
}
