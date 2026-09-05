#include <iostream>
#include <cmath>
using namespace std;
#define P 15
#define k 4

bool validaPeso(int cortes[], bool enPedidoActual[], bool reservadosPermanente[],
                int pesoAgregado, int corteActual, int cantCortes) {
    if (pesoAgregado > P) return false;
    if (reservadosPermanente[corteActual]) return false; // ya pertenece a otro pedido

    // si el pedido actual esta vacio, se acepta el primer corte sin comparar
    bool estaVacio = true;
    for (int i = 0; i < cantCortes; i++) {
        if (enPedidoActual[i]) estaVacio = false;
    }
    if (estaVacio) return true;

    // se exige que el nuevo corte este a distancia <= k de AL MENOS uno
    // de los cortes ya reservados en el pedido actual
    for (int i = 0; i < cantCortes; i++) {
        if (i != corteActual && enPedidoActual[i]) {
            if (abs(cortes[i] - cortes[corteActual]) <= k) return true;
        }
    }

    return false;
}

int resolver(int cortes[], int cantCortes, int actual, bool enPedidoActual[],
             bool reservadosPermanente[], int pesoActual) {
    // CASO BASE 1: se completo el pedido exactamente con peso P
    if (pesoActual == P) {
        // los cortes de este pedido quedan reservados para siempre
        for (int i = 0; i < cantCortes; i++) {
            if (enPedidoActual[i]) reservadosPermanente[i] = true;
        }
        return 1;
    }

    // CASO BASE 2: ya no quedan cortes por evaluar y no se completo el pedido
    if (actual >= cantCortes) return 0;

    // CASO 1: tomamos el corte "actual"
    int pesoAgregado = pesoActual + cortes[actual];
    if (validaPeso(cortes, enPedidoActual, reservadosPermanente, pesoAgregado, actual, cantCortes)) {
        enPedidoActual[actual] = true;
        if (resolver(cortes, cantCortes, actual + 1, enPedidoActual, reservadosPermanente, pesoAgregado))
            return 1;
        enPedidoActual[actual] = false; // backtrack: deshacemos si no funciono
    }

    // CASO 2: no tomamos el corte "actual", avanzamos
    if (resolver(cortes, cantCortes, actual + 1, enPedidoActual, reservadosPermanente, pesoActual))
        return 1;

    return 0;
}

int main() {
    int cortes[]{2, 8, 9, 6, 7, 6};
    int n = sizeof(cortes) / sizeof(cortes[0]);
    bool reservadosPermanente[n]{}; // persiste entre pedidos

    int pedidosAtendidos = 0;
    // snapshot[p][i] = true si el corte i pertenece al pedido p (p desde 0)
    // se usa para poder imprimir todo junto al final, como en el enunciado
    bool snapshot[n][n]{};

    // Repetimos mientras se pueda formar un pedido nuevo con los cortes libres
    while (true) {
        bool enPedidoActual[n]{}; // se reinicia en cada intento de pedido
        int exito = resolver(cortes, n, 0, enPedidoActual, reservadosPermanente, 0);
        if (!exito) break;

        for (int i = 0; i < n; i++) snapshot[pedidosAtendidos][i] = enPedidoActual[i];
        pedidosAtendidos++;
    }

    // Igual que el PDF: si no se atiende ningun pedido, se indica en pantalla
    if (pedidosAtendidos == 0) {
        cout << "No se puede atender el pedido" << endl;
        return 0;
    }

    cout << "Numero de pedidos que se puede atender de " << P << " kg: " << pedidosAtendidos << endl;
    cout << "Peso de los cortes de cada pedido: ";
    for (int p = 0; p < pedidosAtendidos; p++) {
        cout << "{";
        bool primero = true;
        for (int i = 0; i < n; i++) {
            if (snapshot[p][i]) {
                if (!primero) cout << ", ";
                cout << cortes[i];
                primero = false;
            }
        }
        cout << "}";
        if (p != pedidosAtendidos - 1) cout << " ";
    }
    cout << endl;

    return 0;
}