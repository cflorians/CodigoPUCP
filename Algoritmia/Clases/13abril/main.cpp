#include <iostream>
using namespace std;

int robotRecursivo(int iniX, int iniY, int tablero[][10] ,int n ,int m) {
    int derecha = INT_MIN, abajo = INT_MIN;
    int maximoPuntaje;
    // CASO BASE
    if (iniX == n-1 and iniY == m-1) {
        return tablero[iniX][iniY]; // retorno el valor de la ultima celda
    }
    // PARTE RECURSIVA
    // antes de ir a la derecha, puedo moverme?
    if (iniX + 1 < n) // con esto verifico si me muevo dentro de los limites
        derecha = robotRecursivo(iniX + 1,iniY,tablero,n,m);
    if (iniY + 1 < m) // con esto verifico si me muevo dentro de los limites
        abajo = robotRecursivo(iniX,iniY + 1,tablero,n,m);

    if (derecha > abajo) maximoPuntaje = tablero[iniX][iniY] + derecha;
    else maximoPuntaje = tablero[iniX][iniY] + abajo;

    return maximoPuntaje;
}

int main(int argc, char** argv) {

    int n, m;
    int tablero[10][10]{};
    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;

    // cuando trabajamos con matrices, mapas, tableros, laberintos, movimientos
    // SIEMPRE, SIEMPRE, SI--EM---PRE
    // se verifican los límites, si podemos o no movernos en esa dirección
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> tablero[i][j];
        }
    }

    cout << robotRecursivo(0,0,tablero,n,m) << endl;

    return 0;
}
