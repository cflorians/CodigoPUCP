#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int sonda(int x, int y, int n, int m, int mapa[][6], int limite, int movidas, int mov) {
    // CASO BASE
    // limites del mapa
    if (x<0 or x>=n or y<0 or y>=m) return 0;
    // verificar las esquinas del cuadrado para no salirse
    if ((x+limite > n-1 or y+limite > m-1) and mov == 0) return 0;

    int contador = 0;

    // escaneamos la casilla en la que estamos
    if (mapa[x][y] == 1) {
        contador++;
        cout << x << ", " << y << endl;
    }

    if (mov == 0) {
        // Para aca salimos hacia la izq arriba
        contador += sonda(x-1, y-1, n, m, mapa, limite + 2, movidas,0);
        mov = 1;
    }
    if (movidas < limite and y+1 < m and mov == 1) {
        // vamos a movernos hacia la derecha
        if (movidas != limite-1) {
            contador += sonda(x, y+1, n, m, mapa, limite, movidas + 1, mov);
        }
        else { // en el ultimo establece que se movera hacia abajo
            contador += sonda(x, y+1, n, m, mapa, limite, 0, 2);
        }
    }
    if (movidas < limite and x+1 < n and mov == 2) {
        // vamos a movernos hacia abajo
        if (movidas != limite-1) {
            contador += sonda(x+1, y, n, m, mapa, limite, movidas + 1, mov);
        }
        else { // en el ultimo establecemos que nos movemos hacia la izq
            contador += sonda(x+1, y, n, m, mapa, limite, 0, 3);
        }
    }
    if (movidas < limite and y-1 >= 0 and mov == 3) {
        // vamos a movernos hacia la izq
        if (movidas != limite-1) {
            contador += sonda(x,y-1, n, m, mapa, limite, movidas + 1, mov);
        }
        else { // en el ultimo establece que se movera hacia arriba
            contador += sonda(x, y-1, n, m, mapa, limite, 0, 4);
        }
    }
    if (movidas < limite-1 and x-1 >= 0 and mov == 4) {
        // como ya no cambia de direccion, no necesitamos más ifs
        contador += sonda(x-1, y, n, m, mapa, limite, movidas + 1, mov);
    }

    return contador;
}

int main() {
    
    // Tamaño
    int n = 6, m = 6;
    int mapa[][6] {
        {0,0,0,1,0,1},
        {0,0,1,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0}
    };

    cout << "El resultado de la busqueda es: " << sonda(3,2,n,m,mapa,0,0,0) << endl;

    return 0;
}