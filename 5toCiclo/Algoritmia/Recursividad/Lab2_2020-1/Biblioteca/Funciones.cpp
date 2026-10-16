#include <iostream>
#include <iomanip>
using namespace std;

#include "Funciones.h"

void pregunta1() {
    // Dimensiones de la matriz
    int n = 5, m = 8;
    // matriz
    int** mapa = new int*[n];
    for (int i = 0; i < n; i++) {
        mapa[i] = new int[m];
    }
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mapa[i][j] = valor++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(2) << mapa[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    recorrer(0, 0, n, m, 0,mapa, 0);

    for (int i = 0; i < n; i++) {
        delete[] mapa[i];
    }
    delete[] mapa;
}

void recorrer(int posX, int posY, int n, int m, int mov, int** mapa, int vuelta) {
    // CASO BASE
    // si nos salimos del mapa
    if (posX >= n - vuelta or posX < vuelta) return;
    if (posY >= m - vuelta or posY < vuelta) return;

    cout << mapa[posX][posY] << " ";

    // mov = 0, hacia la derecha, 1 hacia abajo, 2 hacia la izq y 3 hacia arriba
    if (mov == 0) {
        if (posY < m - 1 - vuelta) {
            recorrer(posX, posY + 1, n, m, 0, mapa, vuelta);
        }
        else {
            recorrer(posX + 1, posY, n, m, 1, mapa, vuelta);
        }
    }
    else if (mov == 1) {
        if (posX < n - 1 - vuelta) {
            recorrer(posX + 1, posY, n, m, 1, mapa, vuelta);
        }
        else {
            recorrer(posX, posY - 1, n, m, 2, mapa, vuelta);
        }
    }
    else if (mov == 2) {
        if (posY > vuelta) {
            recorrer(posX, posY - 1, n, m, 2, mapa, vuelta);
        }
        else {
            recorrer(posX-1, posY, n, m, 3, mapa, vuelta);
        }
    }
    else if (mov == 3) {
        if (posX > vuelta + 1) {
            recorrer(posX-1, posY, n, m, 3, mapa, vuelta);
        }
        else {
            if (vuelta + 1 < n - vuelta - 1 and vuelta + 1 < m - vuelta - 1) {
                recorrer(posX, posY+1, n, m, 0, mapa, ++vuelta);
            }
        }
    }
}

void pregunta() {
    // tamaño de la matriz
    int n = 5, m = 6;
    // limites
    int max = 5, min = 3;
    // cantidad de productos
    int productos = 20;
    
}