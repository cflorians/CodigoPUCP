#include <atomic>
#include <iostream>
#include <cmath>
using namespace std;

void cargaBinaria(int numero, int* cromosoma, int n) {
    int i=0;
    int aux;

    // inicializamos todos los genes del cromosoma en 0
    for (i=0; i<n; i++) {
        cromosoma[i]=0;
    }

    // pasar el número a binario
    i=0;
    while (numero>0) {
        aux = numero%2;
        numero = numero/2;
        cromosoma[i] = aux;
        i++;
    }
}

bool verificarPredecesores(int j, int* cromosoma, int* predecesores, int* cantPredecesores) {
    if (cantPredecesores[j]==0) return true;

    int condicionesValidas = 0;
    for (int i=0; i < cantPredecesores[j]; i++) {
        if (cromosoma[predecesores[i] - 1] == 1) condicionesValidas++;
    }
    return condicionesValidas == cantPredecesores[j];
}

int main(int argc, char** argv) {
    // Datoos de entrada
    int proyectos[8]{1,2,3,4,5,6,7,8};
    int costo[8]{80,20,100,100,50,10,50,50};
    int ganancia[8]{150,80,300,150,80,50,120,150};

    int cantPredecesores[8]{0,0,2,0,0,1,1,1};
    int predecesores[8][3]{};

    predecesores[2][0] = 1; predecesores[2][1] = 2;
    predecesores[5][0] = 2;
    predecesores[6][0] = 6;
    predecesores[7][0] = 6;

    // para analisis de cada combinacion
    int cromosoma[8];
    int gananciaActual;
    int costoActual;
    bool combinacionFactible;

    // limitantes
    int presupuesto = 250;

    int combinaciones;
    combinaciones = pow(2,8);

    int menorCosto = 10000;
    int mayorGanancia = -1;
    int mejorCombinacion = -1;

    for (int i=0; i<combinaciones; i++) {
        cargaBinaria(i, cromosoma, 8);
        gananciaActual = 0;
        costoActual = 0;
        combinacionFactible = true;

        for (int j=0; j<8; j++) {
            if (cromosoma[j] == 1) {
                if (verificarPredecesores(j, cromosoma, predecesores[j], cantPredecesores)) {
                    gananciaActual += ganancia[j];
                    costoActual += costo[j];
                }
                else {
                    combinacionFactible = false;
                    break;
                }
            }
        }

        if (combinacionFactible and costoActual <= presupuesto) {
            if (gananciaActual > mayorGanancia) {
                mayorGanancia = gananciaActual;
                menorCosto = costoActual;
                mejorCombinacion = i;
            }
        }
    }
    
    if (mejorCombinacion != -1) {
        // en este punto ya tengo la mejor combinacion
        cargaBinaria(mejorCombinacion, cromosoma, 8);
        cout << "SOLUCIÓN: ";
        for (int j=0; j<8; j++) {
            if (cromosoma[j] == 1) cout << proyectos[j] << " ";
        }
        cout << endl << menorCosto << endl << mayorGanancia << endl;
    }
    
    return 0;
}
