#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
using namespace std;

const int ITERACIONES = 1000;
const double alfa = 0.2;

enum costoZona{uno, dos};

struct Pedido{
    char id;
    int peso;
    int zona;
};

struct Camion {
    int id;
    int usado = 0;
    int capacidad;
    int costoZona[2];
    vector<Pedido> pedidos;
    int costoTotal = 0;
    int costoUnico = 0;
};

void cargaDatos(vector<Camion>& c, vector<Pedido>& p) {
    // cargamos los camiones
    c.push_back({1,0,40,{4,9}});
    c.push_back({2,0,35,{7,3}});
    c.push_back({3,0,50,{5,6}});
    // cargamos los pedidos
    p.push_back({'A', 20, uno});
    p.push_back({'B', 18, dos});
    p.push_back({'C', 15, uno});
    p.push_back({'D', 12, dos});
    p.push_back({'E', 10, dos});
    p.push_back({'F',  8, uno});
}

bool comparaPedido(const Pedido& a, const Pedido& b) {
    return a.peso > b.peso;
}

int tamRCL(vector<Pedido>& p, double umbral) {
    int tam = 0;
    while (tam < p.size() and p[tam].peso >= umbral) tam++;
    return tam;
}
vector<Camion> validos(const vector<Camion>& c, const Pedido& p) {
    vector<Camion> camValidos;
    // recorremos los camiones
    for (const Camion& camion : c) {
        // verificamos si es que cabe y lo agregamos a nuestros validos
        if (camion.usado + p.peso <= camion.capacidad) camValidos.push_back(camion);
    }
    return camValidos;
}

bool ordenaCamiones(const Camion& cam1, const Camion& cam2) {
    return cam1.costoUnico < cam2.costoUnico;
}

void ordenaValidos(vector<Camion>& camiones, int zona) {
    // primero determinamos el precio segun la zona a la que va el pedido
    for (Camion& camion : camiones) {
        camion.costoUnico = camion.costoZona[zona];
    }
    // ahora que ya tenemos los costos unicos determinados por zonas, ordenamos el camion
    sort(camiones.begin(), camiones.end(), ordenaCamiones);
}

int tamRCL(const vector<Camion>& c, double umbral) {
    int tam = 0;
    while (tam < c.size() and c[tam].costoUnico <= umbral) tam++;
    return tam;
}

int construir(vector<Camion>& c, vector<Pedido> p) {
    int beta, tau, k, indiceCamion, indicePedido, costoTotal = 0;
    double umbral;

    // ordenamos los pedidos
    sort(p.begin(), p.end(), comparaPedido);
    while (not p.empty()) {
        // obtenemos el umbral
        beta = p.front().peso;
        tau = p.back().peso;
        umbral = beta - alfa*(beta - tau);
        // obtenemos un indice
        k = tamRCL(p, umbral);
        indicePedido = rand() % k;

        // buscamos los camiones validos
        vector<Camion> v = validos(c, p[indicePedido]);
        // ahora en v tenemos los camiones en los que cabe el pedido
        if (v.empty()) return INT_MAX; // solucion invalida
        // ahora lo que hacemos es ordenar los camiones
        ordenaValidos(v, p[indicePedido].zona);
        // ahora que tenemos los camiones ordenados de menor a mayor costo
        // calculamos su umbral
        beta = v.front().costoUnico;
        tau = v.back().costoUnico;
        umbral = beta + alfa*(tau - beta);
        // ahora hallamos un indice
        k = tamRCL(v, umbral);
        indiceCamion = rand() % k;
        // el indice obtenido es en v

        // ya que tenemos elegido un camion y un pedido, los asignamos
        // en los camiones originales
        for (auto it = c.rbegin(); it != c.rend(); ++it) {
            if (it->id == v[indiceCamion].id) {
                // cuando lo encontramos, asignamos
                it->pedidos.push_back(p[indicePedido]);
                it->costoTotal += v[indiceCamion].costoUnico;
                it->usado += p[indicePedido].peso;
                break;
            }
        }

        costoTotal += v[indiceCamion].costoUnico;

        // borramos el pedido
        p.erase(p.begin() + indicePedido);
    }
    return costoTotal;
}

int grasp(vector<Camion>& c, const vector<Pedido>& p) {
    int menorCosto = INT_MAX, costoActual;
    vector<Camion> mejorCamion;
    for (int i =0; i < ITERACIONES; i++) {
        vector<Camion> temp = c;

        costoActual = construir(temp, p);

        if (costoActual < menorCosto) {
            menorCosto = costoActual;
            mejorCamion = temp;
        }
    }
    c = mejorCamion;
    return menorCosto;
}

int main() {
    vector<Camion> camiones;
    vector<Pedido> pedidos;
    int costoTotal;

    srand(time(NULL));

    cargaDatos(camiones, pedidos);

    costoTotal = grasp(camiones, pedidos);

    cout << "============================================" << endl;
    cout << "GRASP CONSTRUCTION - MEDIEXPRESS S.A.C" << endl;
    cout << "============================================" << endl;
    cout << "Pedidos: " << pedidos.size() << "    Camiones: " << camiones.size() << endl;
    cout << "Alfa: " << alfa << "     Iteraciones: " << ITERACIONES << endl;
    cout << "============================================" << endl;

    int i = 1;
    for (const Camion& c : camiones) {
        cout << "Camion " << i << " (cap=" << c.capacidad << "kg): ";
        for (auto it = c.pedidos.begin(); it != c.pedidos.end(); ++it) {
            cout << it->id << (it != c.pedidos.end()-1 ? ", ":" ");
        }
        cout << "| Peso: " << c.usado << "/" << c.capacidad << "kg | Costo: " << c.costoTotal << endl;
        i++;
    }
    cout << "Costo total de entrega = " << costoTotal << endl;


    return 0;
}
