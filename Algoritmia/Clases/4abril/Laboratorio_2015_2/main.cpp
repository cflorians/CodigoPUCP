#include <iostream>
using namespace std;

void triangulo(int a, int b) {
    // CASO BASE
    if (a > b) return;
    // PARTE RECURSIVA
    for (int i = 0; i < a; i++) {
        cout << " * ";
    }
    cout << endl;
    triangulo(a+1,b);
    for (int i = 0; i < a; i++) {
        cout << " * ";
    }
    cout << endl;
}

void patron(int n, int i) {
    // CASO BASE
    if (n==0) return;
    // PARTE RECURSIVA
    patron(n/2,i);
    for (int j = 0; j < i; j++) {
        cout << "   ";
    }
    for (int j=0; j < n ; j++) {
        cout << " * ";
    }
    cout << endl;
    patron(n/2, i + n/2);
}

int mapa[][6] {
    {0,0,0,1,0,1},
    {0,0,1,0,0,0},
    {0,1,0,0,0,1},
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,0,0,1,0}
};

int buscarUnidades(int posX, int posY, int movX, int movY,int controlX, int controlY, int n, int m) {
    int contador = 0;
    int i;

    // CASO BASE, cuando se sale por alguno de los bordes
    if (posX >= n or posY >= m or posX <0 or posY <0) return contador;
    if (mapa[posX][posY] == 1) contador++; // si en la pos inicial hay un elemento, cuento
    if (controlX == 0) { // Entra cuando es la primera vez
        // luego ya no porque toma el valor del movimiento
        for (i = posX+1; i<n ; i++) { // abajo
            contador += mapa[i][posY];
        }
        for (i = 0; i<posX ; i++) { // arriba
            contador += mapa[i][posY];
        }
    }
    if (controlY == 0) {
        for (i = posY+1; i<m ; i++) { // derecha
            contador += mapa[posX][i];
        }
        for (i = 0; i<posY ; i++) { // izquierda
            contador += mapa[posX][i];
        }
    }

    // PARTE RECURSIVA
    contador += buscarUnidades(posX+movX, posY+movY, movX, movY, movX, movY, n, m);
    return contador;
}

int main(int arg, char** argv) {
    
     // triangulo(1,7);
     patron(8,0);
    // int contador; //contadorDeUnidades
    // int n=6,m=6; // segun enunciado
    // // los movimientos disponibles en esta version del RobotSonda:
    // // derecha 0,1
    // // izquierda 0,-1
    // // arriba -1,0
    // // abajo 1,0
    // contador = buscarUnidades(3,2, 0,1, 0,0, n,m);
    // cout << "Total de unidades: " << contador << endl;

    return 0;
}
