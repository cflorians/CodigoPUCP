#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define LARGO 10
#define CANTIDAD 20

struct Pedido {
    int id;
    int dimension;
    int cantidad;
    int ganancia;
};

bool compara(const Pedido& a, const Pedido& b) {
    if ((double)a.dimension/a.cantidad == (double)b.dimension/b.cantidad) {
        return a.ganancia > b.ganancia;
    }
    return (double)a.dimension/a.cantidad < (double)b.dimension/b.cantidad;
}

// debe estar en orden 3 -> 5 -> 1 -> 4
// dimension/cantidad  1/18 -> 1 -> 2 -> 3


/*  Estrategia: Algoritmo Voraz
 *  1. Objetivo: Minimizar las perdidas de acero
 *  2. Selección: ordenar por ratio dimension/cantidad, de forma ascendente,
 *                en caso de empate, ordenar por ganancia de forma descendente
 *  Si es que la dimensión del pedido es más grande que las barras que se tienen,
 *  entonces no se atiende.
 *  Si es que el largo total del pedido excede el largo de las barras, entonces se usa
 *  una entera y se consume tambien parte de la siguiente. Este proceso se repite
 *  hasta terminar con el largo total del pedido (dimension*cantidad)
 *  Se suma la ganancia y finalmente se imprime
 */
void acerosPuno(vector<Pedido>& pedidos, int barras[]) {
    // ordenamos el arreglo
    sort(pedidos.begin(), pedidos.end(), compara);
    // una vez ordenado, pasamos a hacer el algoritmo
    int largoTotalPedido;
    int ultimaBarraUsada = 0;
    int aUsar, ganancia = 0;;
    for (Pedido pedido : pedidos) {
        // si es que podemos atenderlo
        if (pedido.dimension <= LARGO) {
            largoTotalPedido = pedido.dimension*pedido.cantidad;
            // hacemos que reste hasta que largoTotalPedido sea 0
            while (largoTotalPedido) {
                if (largoTotalPedido >= LARGO) {
                    aUsar = 10;
                    largoTotalPedido -= 10;
                }
                else {
                    aUsar = largoTotalPedido;
                    largoTotalPedido = 0;
                }
                if (aUsar > 10 or aUsar > barras[ultimaBarraUsada]) ultimaBarraUsada++;
                barras[ultimaBarraUsada] -= aUsar;
            }
            ganancia += pedido.ganancia;
        }
    }

    cout << "Ganancia: " << ganancia << " k" << endl;
    cout << "Desperdicio de barras usadas:" << endl;
    cout << left << setw(13) << "Barras";
    for (int i=0; i<CANTIDAD; i++) {
        cout << left << setw(2) << i+1 << " ";
    }
    cout << endl << left << setw(13) << "Desperdicio";
    for (int i=0; i<CANTIDAD; i++) {
        cout << left << setw(2) << barras[i] << " ";
    }
}

int main() {

    vector<Pedido> pedidos;
    pedidos.push_back({1,10,5,10});
    pedidos.push_back({2,20,10,20});
    pedidos.push_back({3,1,18,15});
    pedidos.push_back({4,3,1,5});
    pedidos.push_back({5,1,1,2});

    int barras[CANTIDAD];
    for (int i = 0; i < CANTIDAD; i++) barras[i] = LARGO;

    acerosPuno(pedidos, barras);

    return 0;
}
