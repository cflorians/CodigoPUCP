#include <iostream>
using namespace std;
#define N 4
#define M 5

void colocarProducto(int capacidadRack[M], int ocupadoRack[M], int productos[N], bool usado[N]
                    , int iProducto, int totalColocado, int mejorOcupado[M], int& mejorTotal) {
    // CASO BASE
    // ya nos quedamos sin productos que evaluar si colocar o no
    if (iProducto >= N) {
        if (totalColocado > mejorTotal) {
            mejorTotal = totalColocado;
            for (int k = 0; k < M; k++) mejorOcupado[k] = ocupadoRack[k];
        }
        return;
    }

    // PARTE RECURSIVA
    // probamos a colocar productos en cada rack disponible
    for (int r=0; r<M; r++) {
        if (ocupadoRack[r] + productos[iProducto] <= capacidadRack[r]) {
            ocupadoRack[r] += productos[iProducto];
            colocarProducto(capacidadRack, ocupadoRack, productos, usado, iProducto+1
                            , totalColocado + productos[iProducto], mejorOcupado, mejorTotal);
            // para el backtracking
            ocupadoRack[r] -= productos[iProducto];
        }
    }
    // si no lo colocamos
    colocarProducto(capacidadRack, ocupadoRack, productos, usado, iProducto+1
                            , totalColocado, mejorOcupado, mejorTotal);
}

void colocarProductoTodas(int capacidadRack[M], int ocupadoRack[M], int productos[N], bool usado[N]
                    , int iProducto, int cantUbicados) {
    // CASO BASE
    // ya nos quedamos sin productos que evaluar si colocar o no
    if (iProducto >= N) {
        if (cantUbicados == N) {
            for (int i = 0; i < M; i++) {
                cout << ocupadoRack[i] << "  ";
            }
            cout << endl;
        }
        return;
    }

    // PARTE RECURSIVA
    // probamos a colocar productos en cada rack disponible
    for (int r=0; r<M; r++) {
        if (ocupadoRack[r] + productos[iProducto] <= capacidadRack[r]) {
            ocupadoRack[r] += productos[iProducto];
            colocarProductoTodas(capacidadRack, ocupadoRack, productos, usado, iProducto+1, cantUbicados+1);
            // para el backtracking
            ocupadoRack[r] -= productos[iProducto];
        }
    }
    // si no lo colocamos
    colocarProductoTodas(capacidadRack, ocupadoRack, productos, usado, iProducto+1, cantUbicados);
}

int main() {
    int capacidadRack[M] {3,2,5,1,3};
    int ocupadoRack[M]{};
    int productos[N] {2,3,1,4};
    bool usado[N]{};

    int mejorOcupado[M]{};
    int mejorTotal = -1;

    colocarProducto(capacidadRack, ocupadoRack, productos, usado, 0,0, mejorOcupado, mejorTotal);

    for (int i = 0; i < M; i++) {
        cout << mejorOcupado[i] << "  ";
    }
    cout << endl << "==============" << endl;

    colocarProductoTodas(capacidadRack, ocupadoRack, productos, usado, 0, 0);

    return 0;
}
