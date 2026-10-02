#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define N 6
#define CAP 15

struct Paquete {
    int id;
    int ganancia;
    int peso;
};

bool compara(const Paquete &a, const Paquete &b) {
    if (((double)a.ganancia/a.peso) == ((double)b.ganancia/b.peso)) {
        return (a.peso < b.peso);
    }
    return ((double)a.ganancia/a.peso) > ((double)b.ganancia/b.peso);
}
/*
    * ESTRATEGIA: Algoritmo voraz (mochila 0/1 heuristica).
    *  - Seleccion: ordenar por ganancia/peso descendente; empate -> menor peso.
    *  - Factibilidad: el paquete se carga si peso <= peso sobrante.
    *  - Miopia: cada paquete se evalua una sola vez, sin vuelta atras.
    */
void dronReparto(vector<Paquete> &paquetes, int n) {
    int indicePaquetes = 0;
    int pesoSobrante = CAP;
    int ganancia = 0;

    cout << "Paquetes cargados: ";
    for (Paquete paquete : paquetes) {
        if (paquete.peso <= pesoSobrante) {
            pesoSobrante -= paquete.peso;
            ganancia += paquete.ganancia;
            cout << 'P' << paquete.id << " ";
        }
        indicePaquetes++;
    }
    cout << endl;

    cout << "Peso sobrante: " << pesoSobrante << " kg" << endl;

    cout << "Ganancia: " << ganancia << endl;
}

int main() {

    vector<Paquete> paquetes;
    paquetes.push_back(Paquete(1,12,4));
    paquetes.push_back(Paquete(2,9,3));
    paquetes.push_back(Paquete(3,20,10));
    paquetes.push_back(Paquete(4,6,2));
    paquetes.push_back(Paquete(5,10,5));
    paquetes.push_back(Paquete(6,4,4));
    int n = paquetes.size();

    sort(paquetes.begin(), paquetes.end(), compara);

    dronReparto(paquetes, n);

    return 0;
}
