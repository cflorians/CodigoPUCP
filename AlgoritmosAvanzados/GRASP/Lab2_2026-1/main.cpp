#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <climits>

using namespace std;

const int ITERACIONES = 1000;
const double alfa = 0.2;
const int capacidad = 50;

struct Pedido {
    char id;
    int peso;
};

struct Camion {
    vector<Pedido> pedidos;
    int usado = 0;
};

void cargaPedidos(vector<Pedido>& pedidos) {
    pedidos.push_back({'A',15});
    pedidos.push_back({'B',32});
    pedidos.push_back({'C',20});
    pedidos.push_back({'D',42});
    pedidos.push_back({'E',8});
    pedidos.push_back({'F',18});
}

bool compara(const Pedido& a, const Pedido& b) {
    return a.peso > b.peso;
}

int tamRCL(const vector<Pedido>& pedidos, double umbral) {
    int tam = 0;
    for (Pedido p : pedidos) {
        if (p.peso >= umbral) tam++;
        else break;
    }
    return tam;
}

int indiceCamion(vector<Camion>& camiones, int peso) {
    // verificamos si es que entra o no
    int i=0;
    while (i < camiones.size()) {
        if (camiones[i].usado + peso <= capacidad) return i;
        i++;
    }
    // si es que no hay un camion en el que entre
    // creamos un camion nuevo
    Camion c{};
    camiones.push_back(c);
    return i;
}

vector<Camion> grasp(const vector<Pedido>& pedidos) {
    int beta, tau;
    int k, indice, indCamion;
    int cantCamiones, mejorCantCamiones = INT_MAX;
    double umbral;
    vector<Camion> solucion;
    vector<Pedido> temp;

    for (int i = 0; i < ITERACIONES; i++) {
        cantCamiones = 0;
        temp = pedidos;
        vector<Camion> camiones;
        while (not temp.empty()) {
            beta = temp.front().peso;
            tau = temp.back().peso;
            umbral = beta - alfa*(beta - tau);

            k = tamRCL(temp, umbral);
            indice = rand() % k;

            // obtenemos el camion donde colocar
            indCamion = indiceCamion(camiones, temp[indice].peso);

            // colocamos el pedido en el camion
            camiones[indCamion].pedidos.push_back(temp[indice]);
            camiones[indCamion].usado += temp[indice].peso;

            // borramos el pedido de el vector
            temp.erase(temp.begin() + indice);
        }

        cantCamiones = (int)camiones.size();
        if (mejorCantCamiones > cantCamiones) {
            mejorCantCamiones = cantCamiones;
            solucion = camiones;
        }
    }

    return solucion;
};

int main() {
    vector<Pedido> pedidos;
    vector<Camion> solucion;
    cargaPedidos(pedidos);

    srand(time(NULL));

    sort(pedidos.begin(), pedidos.end(), compara);
    solucion = grasp(pedidos);

    cout << "============================================" << endl;
    cout << "GRASP CONSTRUCCION - MEDIEXPRESS S.A.C" << endl;
    cout << "============================================" << endl;
    cout << "Pedidos: " << pedidos.size() << endl;
    cout << "Alfa: " << alfa << " Iteraciones: " << ITERACIONES << endl;
    cout << "Capacidad de carga por camión (K): " << capacidad << " kg" << endl;
    cout << "============================================" << endl;

    int i=1;
    for (const Camion& c : solucion) {
        cout << "Camion " << i << " (cap=" << capacidad << "kg): ";
        for (int j=0; j<c.pedidos.size(); j++) {
            cout << c.pedidos[j].id << (j == c.pedidos.size() - 1 ? " " : ", ");
        }
        cout << "| Peso: " << c.usado << "/" << capacidad << "kg" << endl;
        i++;
    }
    cout << "============================================" << endl;
    cout << "Cantidad total de camiones = " << solucion.size() << endl;

    return 0;
}
