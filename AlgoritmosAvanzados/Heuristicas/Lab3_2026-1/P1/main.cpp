#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Tarea {
    char tarea;
    int tiempo;
    int peso;
};

bool ordenar(const Tarea &t1, const Tarea &t2) {
    double ratio1 = (double)t1.peso/t1.tiempo;
    double ratio2 = (double)t2.peso/t2.tiempo;

    if (ratio1 == ratio2) {
        return t1.tiempo < t2.tiempo;
    }
    return ratio1 > ratio2;
}
/*
 * Descripcion: Algoritmo voraz, ordena el arreglo por ratio peso/tiempo,
 *              en caso de empate ordena por menor tiempo, luego, realiza las tareas
 *              con ese orden, primero las que más peso tienen con menor tiempo de ejecucion
 */
void scheduling(vector<Tarea> &tareas) {
    // aca llega el vector ordenado

    int tiempoEjecucion = 0;
    double costoTotalPonderado = 0;
    double costoPonderado = 0;

    cout << "============================================" << endl;
    cout << "ORDENAMIENTO FINAL SEGUN REGLA DE SMITH" << endl;
    cout << "============================================" << endl;

    for (const Tarea& t : tareas) {
        double ratio = (double)t.peso/t.tiempo;
        cout << "Tarea: " << t.tarea << endl;
        cout << "Tiempo procesamiento: " << fixed << setprecision(2) << (double)t.tiempo << endl;
        cout << "Peso: " << fixed << setprecision(2) << (double)t.peso << endl;
        cout << "Ratio w/p: " << fixed << setprecision(2) << ratio << endl;
        tiempoEjecucion += t.tiempo;
        cout << "Completion Time: " << fixed << setprecision(2) << (double)tiempoEjecucion << endl;
        costoPonderado = t.peso*tiempoEjecucion;
        cout << "Costo Ponderado: " << costoPonderado << endl;
        costoTotalPonderado += costoPonderado;
        cout << "------------------------" << endl;
    }

    cout << "COSTO TOTAL PONDERADO: " << (double)costoTotalPonderado << endl;
}

int main() {

    vector<Tarea> tareas;
    tareas.push_back({'A',4,20});
    tareas.push_back({'B',2,10});
    tareas.push_back({'C',5,15});
    tareas.push_back({'D',3,18});

    sort(tareas.begin(), tareas.end(), ordenar);

    scheduling(tareas);

    return 0;
}
