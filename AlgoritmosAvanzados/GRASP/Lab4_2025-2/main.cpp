#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>
using namespace std;

const int ITERACIONES = 1000;
const double alfa = 0.3;
const int costoMax = 20;

struct Ciudad {
    int id;
    int costo;
};

struct Motorizado {
    int id;
    vector<int> costoCiudad;
    int costoUnico;
};

struct Solucion {
    int ciudad;
    int motorizado;
};

void cargaDatos(vector<Ciudad>& c, vector<Motorizado>& m) {
    // cargamos los datos de las ciudades
    c.push_back({1,16});
    c.push_back({2,15});
    c.push_back({3,12});
    c.push_back({4,18});

    // cargamos los datos de los motorizados
    vector<int> costoCiudades;
    costoCiudades.push_back(3);
    costoCiudades.push_back(4);
    costoCiudades.push_back(5);
    costoCiudades.push_back(6);
    m.push_back({1,costoCiudades});

    costoCiudades.clear();
    costoCiudades.push_back(5);
    costoCiudades.push_back(2);
    costoCiudades.push_back(3);
    costoCiudades.push_back(4);
    m.push_back({2,costoCiudades});

    costoCiudades.clear();
    costoCiudades.push_back(7);
    costoCiudades.push_back(5);
    costoCiudades.push_back(4);
    costoCiudades.push_back(2);
    m.push_back({3,costoCiudades});

    costoCiudades.clear();
    costoCiudades.push_back(8);
    costoCiudades.push_back(7);
    costoCiudades.push_back(5);
    costoCiudades.push_back(1);
    m.push_back({4,costoCiudades});

    costoCiudades.clear();
    costoCiudades.push_back(4);
    costoCiudades.push_back(3);
    costoCiudades.push_back(7);
    costoCiudades.push_back(5);
    m.push_back({5,costoCiudades});
}

bool compara(const Motorizado& m1, const Motorizado& m2) {
    return m1.costoUnico < m2.costoUnico;
}

vector<Motorizado> ordenaMotorizado(const vector<Motorizado>& m, int ciudad) {
    vector<Motorizado> ordenado = m;
    // devolvemos el arreglo ordenado de motorizados por precio ascendente
    // de una ciudad en especifico
    for (Motorizado& motorizado : ordenado) {
        // ciudad-1 porque cuando es llamado se le llama con id y no con el indice
        motorizado.costoUnico = motorizado.costoCiudad[ciudad-1];
    }

    sort(ordenado.begin(), ordenado.end(), compara);

    return ordenado;
}

bool valida(int costoCiudad, int costoMotorizado) {
    return (costoCiudad + costoMotorizado) <= costoMax;
}

int tamRCL(const vector<Motorizado>& m, double umbral) {
    int tam = 0;
    while (tam < m.size() and m[tam].costoUnico <= umbral) tam++;
    return tam;
}

int construir(vector<Ciudad> c, vector<Motorizado>& m, vector<Solucion>& s) {
    int beta, tau;
    double umbral;
    int k, indice;
    int costo = 0;

    while (not c.empty()) {
        // elegimos ciudad tal cual y como viene ordenada
        Ciudad ciudadActual = c.front();
        c.erase(c.begin());

        // ahora que tenemos la ciudad, hacemos RCL de los motorizados
        vector<Motorizado> mCiudad = m;
        while (not mCiudad.empty()) {
            mCiudad = ordenaMotorizado(mCiudad, ciudadActual.id);

            beta = mCiudad.front().costoUnico;
            tau = mCiudad.back().costoUnico;
            umbral = beta + alfa*(tau - beta);

            k = tamRCL(mCiudad, umbral);
            indice = rand() % k;

            // validamos
            if (valida(ciudadActual.costo, mCiudad[indice].costoUnico)) {
                // ahora que tenemos una moto aleatoria, la asignamos y la borramos para esta ciudad
                s.push_back({ciudadActual.id, mCiudad[indice].id});
                costo += ciudadActual.costo + mCiudad[indice].costoUnico;
                break;
            }
            mCiudad.erase(mCiudad.begin() + indice);
        }
    }

    return costo;
};

int grasp(vector<Ciudad>& c, vector<Motorizado>& m, vector<Solucion>& s) {
    int costoActual, mejorCosto = INT_MAX;
    vector<Solucion> mejorSolucion;

    for (int i=0; i<ITERACIONES; i++) {
        vector<Solucion> temp;

        costoActual = construir(c, m, temp);

        // si es que es una mejor solucion
        if (costoActual < mejorCosto) {
            mejorCosto = costoActual;
            mejorSolucion = temp;
        }
    }

    s = mejorSolucion;
    return mejorCosto;
}

int main() {
    vector<Ciudad> ciudades;
    vector<Motorizado> motorizados;
    vector<Solucion> solucion;
    int costoTotal;

    cargaDatos(ciudades,motorizados);

    srand(time(NULL));

    costoTotal = grasp(ciudades, motorizados, solucion);

    cout << "Ciudad   Motorizado" << endl;
    for (Solucion s : solucion) {
        cout << "  " << s.ciudad << "          " << s.motorizado << endl;
    }
    cout << "Costo total = " << costoTotal << endl;


    return 0;
}
