#include <iostream>
#include <iomanip>
using namespace std;

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    
    // ---------------NIVEL 1-----------------
    int N=5, M=5;
    int matriz[5][5]{};
    int k=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            matriz[i][j]= k++;
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout<< setw(2) << matriz[i][j]<<" ";
        }
        cout << endl;
    }
    cout << "Cantidad de pares: " << contarPares(0, 0, N, M, matriz) << endl;
    cout << endl;

    // ---------------NIVEL 2-----------------
    int viento[5][5] {
        {4,5,3,2,7},
        {8,4,6,2,1},
        {0,6,2,5,4},
        {1,4,2,6,7},
        {9,6,2,4,1}
    };
    int bateria = 30;
    cout << "El dron llega: " << dron(0,0,3,4, 5, 5, bateria, viento) << endl << endl;

    // ---------------NIVEL 3-----------------

    int mina[6][7] = {
        { 0,  0,  0, -1,  0,  0,  0}, // Fila 0: Anomalía en (0,3)
        { 0,  0, -1,  0,  0,  0,  0}, // Fila 1: Anomalía en (1,2)
        { 0,  0,  0,  0,  0,  0,  0}, // Fila 2
        { -1, 0,  0,  0, 99,  0,  0}, // Fila 3: Anomalía en (3,0) y Roca en (3,4)
        { 0,  0,  0,  0,  0,  0,  0}, // Fila 4
        { 0,  0,  0, -1,  0,  0,  0}  // Fila 5: Anomalía en (5,3)
    };
    int energia = 4;
    sonda(mina, 6, 7, 3, 2, 0, 1, energia, -1);
    
    return 0;
}
