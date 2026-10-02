#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define N 6
#define PRESUPUESTO 120

struct Proyecto {
    int id;
    int costo;
    int ganancia;
    int predecesoras;
};

bool ordena(const Proyecto &a, const Proyecto &b) {
    double ratioA = (double)a.ganancia/a.costo;
    double ratioB = (double)b.ganancia/b.costo;

    if (ratioA == ratioB) {
        return a.costo < b.costo;
    }
    return ratioA > ratioB;
}

void carteraProyectos(vector <Proyecto>& proyectos) {
    // guarda por id
    bool seleccionados[N]{};
    int i;
    int ganancia = 0, resto = PRESUPUESTO, costoTotal = 0;

    cout << "Proyectos seleccionados: ";
    for (Proyecto p : proyectos) {
        for (Proyecto p2 : proyectos) {
            // revisamos si esta seleccionado
            if (not seleccionados[p2.id-1]) {
                // revisamos sus predecesores
                if (p2.predecesoras == 0 or seleccionados[p2.predecesoras-1]) {
                    // revisamos si caben en el presupuesto
                    if (p2.costo <= resto) {
                        // lo tomamos
                        resto -= p2.costo;
                        costoTotal += p2.costo;
                        seleccionados[p2.id-1] = true;
                        ganancia += p2.ganancia;
                        cout << 'P' << p2.id << ' ';
                        break;
                    }
                }
            }
        }
    }
    cout << endl;

    cout << "Presupuesto usado: " << costoTotal << " de " << PRESUPUESTO << endl;
    cout << "Ganancia total: " << ganancia << endl;
}

int main() {

    vector<Proyecto> proyectos;
    proyectos.push_back({1, 40, 60, 0});
    proyectos.push_back({2, 20, 50, 3});
    proyectos.push_back({3, 30, 36, 0});
    proyectos.push_back({4, 10, 30, 2});
    proyectos.push_back({5, 50, 55, 0});
    proyectos.push_back({6, 20, 24, 1});

    sort(proyectos.begin(), proyectos.end(), ordena);
    cout << "Orden por ratio: ";
    for (Proyecto p : proyectos) {
        cout << 'P' << p.id << ' ';
    }
    cout << endl;

    carteraProyectos(proyectos);

    return 0;
}
