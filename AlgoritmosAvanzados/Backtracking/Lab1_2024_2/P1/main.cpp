#include <iostream>
#include <iomanip>
using namespace std;
#define PISOS 5
#define MAX_PACIENTES 7
#define CAP_LAVADORA 50

void imprimirPiso(int ropaPiso[MAX_PACIENTES], bool lavadoPiso[MAX_PACIENTES]) {
    for (int i = 0; i < MAX_PACIENTES; i++) {
        if (lavadoPiso[i]) {
            cout << ropaPiso[i] << "  ";
        }
    }
    cout << endl;
}

void calcularPiso(int ropaPiso[MAX_PACIENTES], bool lavadoPiso[MAX_PACIENTES], int i, int cantRopa, int pesoRopa
                 , int mejorSol[MAX_PACIENTES], int& maxPeso, int& minCant) {
    // aca lo que tenemos que hacer es elegir si queremos tomar o no la ropa
    // CASO BASE
    if (i == MAX_PACIENTES) {
        bool esMejor = (pesoRopa <= CAP_LAVADORA) and
                       ((pesoRopa > maxPeso) or (pesoRopa == maxPeso and cantRopa < minCant));
        if (esMejor) {
            for (int j = 0; j < MAX_PACIENTES; j++) {
                mejorSol[j] = lavadoPiso[j] ? ropaPiso[j] : 0;
            }
            maxPeso = pesoRopa;
            minCant = cantRopa;
        }
        return;
    }
    if (i > MAX_PACIENTES) return;

    // PARTE RECURSIVA
    int pesoAcum = pesoRopa + ropaPiso[i];
    int cantAcum = cantRopa + 1;
    // CASO 1. Lo lavamos
    if (pesoAcum <= CAP_LAVADORA and ropaPiso[i] != 0) {
        lavadoPiso[i] = true;
        calcularPiso(ropaPiso, lavadoPiso, i+1, cantAcum, pesoAcum, mejorSol, maxPeso, minCant);
        // backtracking
        lavadoPiso[i] = false;
    }
    // CASO 2. No lo lavamos
    calcularPiso(ropaPiso, lavadoPiso, i+1, cantRopa, pesoRopa, mejorSol, maxPeso, minCant);
}

void calcularRopa(int kilosRopa[PISOS][MAX_PACIENTES], bool lavados[PISOS][MAX_PACIENTES], int piso
                 , int mejorSol[PISOS][MAX_PACIENTES], int maxPeso[], int minCant[]) {
    // CASOS BASE
    if (PISOS <= piso) return;
    // hacemos los calculos para un piso
    int ropaPiso[MAX_PACIENTES]{};
    for (int i = 0; i < MAX_PACIENTES; i++) ropaPiso[i] = kilosRopa[piso][i];
    calcularPiso(ropaPiso, lavados[piso], 0, 0, 0,
        mejorSol[piso],maxPeso[piso], minCant[piso]);

    // llamamos a calcular ropa para el siguiente piso
    calcularRopa(kilosRopa, lavados, piso+1, mejorSol, maxPeso, minCant);
}

int main() {

    int kilosRopa[PISOS][MAX_PACIENTES] {
        {14,11,10,19,14,11},
        {20,11,11,10,15,17,8},
        {15,16,15,16},
        {11,4,19,12,10},
        {18,12}
    };
    bool lavados[PISOS][MAX_PACIENTES]{};
    int mejorSol[PISOS][MAX_PACIENTES]{};
    int maxPeso[PISOS]{};
    int minCant[PISOS]{100,100,100,100,100};

    calcularRopa(kilosRopa,lavados, 0, mejorSol, maxPeso, minCant);

    for (int i = 0; i < PISOS; i++) {
        for (int j = 0; j < MAX_PACIENTES; j++) {
            if (mejorSol[i][j]) cout << right << setw(2) << mejorSol[i][j] << "  ";
        }
        cout << endl;
    }
    // FALTA AGREGAR EL RESTO DE MINI ITEMS
    return 0;
}
