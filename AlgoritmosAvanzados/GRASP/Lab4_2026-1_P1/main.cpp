#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>
using namespace std;

const int ITERACIONES = 1000;
const double alfa = 0.3;
const int presupuesto = 400;

struct Proyecto {
    int id;
    int costo;
    int ganancia;
    int predecesores[11]; // el ultimo caracter es el fin de los predecesores
};

void cargaDatos(vector<Proyecto>& proyectos) {
    proyectos.push_back({1,100,200,{}});
    proyectos.push_back({2, 50,300,{1}});
    proyectos.push_back({3,150,300,{1}});
    proyectos.push_back({4, 50,400,{}});
    proyectos.push_back({5, 50,200,{4}});
    proyectos.push_back({6,150,800,{2,4}});
    proyectos.push_back({7,100,250,{}});
}

bool compara(const Proyecto& a, const Proyecto& b) {
    return (a.ganancia - a.costo) > (b.ganancia - b.costo);
}

bool cumplePredecesores(const Proyecto& p, const vector<int>& s) {
    bool encontrado;
    for (int i = 0; p.predecesores[i] ; i++) {
        encontrado = false;
        // si no encontramos el predecesor en s, entonces no es valido
        for (int j : s) {
            if (j == p.predecesores[i]) encontrado = true; // significa que este predecesor existe
        }
        if (not encontrado) return false;
    }
    return true;
}

vector<Proyecto> filtraProyectos(const vector<Proyecto>& proyectos, const vector<int>& s, int max) {
    vector<Proyecto> filtrado;
    // se colocara en filtrado
    for (Proyecto p : proyectos) {
        if (cumplePredecesores(p, s) and p.costo <= max) filtrado.push_back(p);
    }
    return filtrado;
}

int tamRCL(const vector<Proyecto>& p, double umbral) {
    int tam = 0;
    while (tam < p.size() and (p[tam].ganancia - p[tam].costo) >= umbral) tam++;
    return tam;
}

int construir(vector<Proyecto> proyectos, vector<int>& solucion) {
    int beta, tau, k, indice, beneficio = 0, costo = 0;
    double umbral;

    while (not proyectos.empty()) {
        vector<Proyecto> filtrado = filtraProyectos(proyectos, solucion, (presupuesto - costo));

        if (filtrado.empty()) break;

        beta = filtrado.front().ganancia - filtrado.front().costo;
        tau = filtrado.back().ganancia - filtrado.back().costo;
        umbral = beta - alfa*(beta-tau);

        // ahora hallamos el tamaño de nuestra RCL
        k = tamRCL(filtrado, umbral);
        indice = rand() % k;

        // ahora que tenemos un indice, lo metemos en la solucion
        solucion.push_back(filtrado[indice].id);
        // sumamos la ganancia para esta solucion
        costo += filtrado[indice].costo;
        beneficio += filtrado[indice].ganancia - filtrado[indice].costo;

        // buscamos el que se debe borrar en proyectos
        for (auto it = proyectos.begin(); it != proyectos.end(); ++it) {
            if (filtrado[indice].id == it->id) {
                // lo borramos y break
                proyectos.erase(it);
                break;
            }
        }
    }
    return beneficio;
}

int grasp(vector<Proyecto>& proyectos, vector<int>& seleccionados) {
    int mejorBeneficio = INT_MIN, beneficioActual;
    // beneficio = ganancia - costo

    // ordenamos por beneficio
    sort(proyectos.begin(), proyectos.end(), compara);

    for (int i = 0; i < ITERACIONES; i++) {
        vector<int> temp;

        beneficioActual = construir(proyectos, temp);

        if (mejorBeneficio < beneficioActual) {
            seleccionados = temp;
            mejorBeneficio = beneficioActual;
        }
    }
    return mejorBeneficio;
}

int main() {
    vector<Proyecto> proyectos;
    vector<int> seleccionados;
    int beneficioTotal;

    srand(time(NULL));

    cargaDatos(proyectos);

    beneficioTotal = grasp(proyectos, seleccionados);

    cout << "Proyectos seleccionados: " << endl;
    for (int s : seleccionados) cout << s << " ";
    cout << endl << "Beneficio total: " << beneficioTotal << endl;

    return 0;
}
