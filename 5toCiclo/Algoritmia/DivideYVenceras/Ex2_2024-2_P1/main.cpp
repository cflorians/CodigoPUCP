#include <iostream>
using namespace std;

struct Dupla {
    int lote;
    int cantidad;
};

int hallaLoteInicial(Dupla A[], int ini, int fin, int cant) {
    // CASO BASE
    if (ini >= fin) {
        if (A[ini].cantidad == cant) return A[ini].lote;
        else return -1;
    }

    // PARTE RECURSIVA
    int mid = (ini + fin)/2;
    if (A[mid].cantidad < cant) return hallaLoteInicial(A, mid + 1, fin, cant);
    else return hallaLoteInicial(A, ini, mid, cant);
}

int hallaLoteFinal(Dupla A[], int ini, int fin, int cant) {
    // CASO BASE
    if (ini >= fin) {
        if (A[ini].cantidad == cant) return A[ini].lote;
        else return -1;
    }

    // PARTE RECURSIVA
    int mid = (ini + fin)/2;
    if (A[mid].cantidad < cant) return hallaLoteFinal(A, mid+1, fin, cant);
    else if (A[mid].cantidad > cant) return hallaLoteFinal(A, ini, mid-1, cant);
    else {
        int resultado = hallaLoteFinal(A, mid+1, fin, cant);
        if (resultado != -1) return resultado;
        else return A[mid].lote;
    }
}

///====================== B =========================

struct Plato {
    string nombre;
    int cantidadDisponible;
    int cantidadReservada;
    double porcentajeReservas;
};

void quickSort(Plato platos[], int ini, int fin) {
    // CASO BASE
    if (ini >= fin) return;

    // PARTE RECURSIVA
    // elegir pivote (ultimo elemento del arreglo)
    int pivote = fin;
    Plato platoPivote = platos[pivote];
    int n = fin-ini;
    Plato menores[n]; // n porque se puede dar el caso que
    Plato mayores[n]; // el ultimo elemento sea el menor o el mayor
    int cantMenores = 0, cantMayores = 0;

    // colocarlos en 2 sub arreglos (menores que y mayores que)
    for (int i = ini; i < fin; i++) { // n-1 porque son los elementos menos el pivote
        if (i != pivote) {  // Asegúrate de no incluir el pivote
            if (platos[i].porcentajeReservas < platos[pivote].porcentajeReservas) {
                menores[cantMenores++] = platos[i];
            } else {
                mayores[cantMayores++] = platos[i];
            }
        }
    }
    // ahora tenemos a menores y mayores desordenados
    // colocamos el pivote en su posicion correcta

    int k = 0;
    int i=ini;
    for (i=ini; k < cantMayores; i++) {
        platos[i] = mayores[k];
        k++;
    }
    int posPivote = i;
    platos[i] = platoPivote;

    k=0;
    i = posPivote + 1;
    while (k<cantMenores) {
        platos[i] = menores[k];
        i++;
        k++;
    }

    quickSort(platos, ini, posPivote-1);
    quickSort(platos, posPivote + 1, fin);
}

int main() {
    ///====================== A =========================
    // Dupla A[] {
    //     {15872, 3},
    //     {15865, 4},
    //     {15866, 4},
    //     {14357, 6},
    //     {14365, 6},
    //     {14368, 6},
    //     {14370, 6},
    //     {19258, 8},
    //     {19260, 8}
    // };
    // int n = sizeof(A)/sizeof(A[0]);
    //
    // int cantProd;
    //
    // cantProd = 3;
    // cout << "Para hallar los lotes de " << cantProd << " productos:" << endl;
    // cout << "Lote Inicial: " << hallaLoteInicial(A, 0, n-1, cantProd) << endl;
    // cout << "Lote Final: " << hallaLoteFinal(A, 0, n-1, cantProd) << endl;
    //
    // cantProd = 6;
    // cout << "Para hallar los lotes de " << cantProd << " productos:" << endl;
    // cout << "Lote Inicial: " << hallaLoteInicial(A, 0, n-1, cantProd) << endl;
    // cout << "Lote Final: " << hallaLoteFinal(A, 0, n-1, cantProd) << endl;
    //
    // cantProd = 8;
    // cout << "Para hallar los lotes de " << cantProd << " productos:" << endl;
    // cout << "Lote Inicial: " << hallaLoteInicial(A, 0, n-1, cantProd) << endl;
    // cout << "Lote Final: " << hallaLoteFinal(A, 0, n-1, cantProd) << endl;

    ///====================== B =========================
    Plato platos[]{
        {"Lomo Saltado", 50, 30},
        {"Ceviche", 40, 35},
        {"Aji de Gallina", 30, 10},
        {"Causa Limeña", 20, 20},
        {"Arroz con Pollo", 60, 45}
    };
    int n = sizeof(platos) / sizeof(platos[0]);

    // calculamos los porcentajes
    for (int i=0; i < n; i++) {
        platos[i].porcentajeReservas =
            ((double)platos[i].cantidadReservada/platos[i].cantidadDisponible)*100;
    }

    quickSort(platos, 0, n-1);

    cout << "Top 3 platos con mayor porcentaje de reservas: " << endl;
    for (int i=0; i<3; i++) {
        cout << platos[i].nombre << " - " << platos[i].porcentajeReservas << "%" << endl;
    }

    return 0;
}
