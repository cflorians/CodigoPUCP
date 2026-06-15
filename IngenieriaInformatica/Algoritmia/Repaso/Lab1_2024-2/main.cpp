#include <cstring>
#include <iostream>
using namespace std;

int contarCombinaciones(char palabra[], char letrasFabricadas[], int cantLetras, bool libre[], int posPalabra, int indicesElegidos[]) {
    // CASO BASE
    if (posPalabra == strlen(palabra)) return 1;

    int combinaciones = 0;
    // PARTE RECURSIVA
    for (int i = 0; i < cantLetras; i++) {
        if (palabra[posPalabra] == letrasFabricadas[i] and libre[i]) {

            bool esValido = true; // asumimos que es valido

            for (int j = 0; j < posPalabra; j++) {
                if (palabra[j] == palabra[posPalabra]) {
                    if (i <= indicesElegidos[j]) {
                        esValido = false;
                        break;
                    }
                }
            }

            if (esValido) {
                libre[i] = false;
                indicesElegidos[posPalabra] = i;
                combinaciones += contarCombinaciones(palabra, letrasFabricadas, cantLetras, libre, posPalabra + 1, indicesElegidos);
                libre[i] = true;
            }
        }
    }

    return combinaciones;
}

void pregunta1() {
    char letrasFabricadas[10]{'G', 'A', 'L', 'A', 'O', 'G', 'L', 'M'};
    bool libre[10];
    int posPalabra;
    int cantLetras = 8;
    int indicesElegidos[10]{};
    char palabras[8][9] {
        {"GOL"},
        {"GALA"},
        {"ALA"},
        {"LOMA"}
    };
    int combPosibles;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) libre[j] = true;
        posPalabra = 0;
        combPosibles = contarCombinaciones(palabras[i], letrasFabricadas, cantLetras, libre, posPalabra, indicesElegidos);
        cout << "La palabra " << palabras[i] << " tiene " << combPosibles << " combinaciones de Letras" << endl;
    }
}

void recorrerAlmacen(int n, int m, int almacen[][5], int posX, int posY, int& maximo, int reponer[][5]) {
    // CASO BASE
    if (posX == n) return;

    if (almacen[posX][posY] > maximo) maximo = almacen[posX][posY];
    // PARTE RECURSIVA
    // recordamos que x y y estan invertidos
    if (posY + 1 < m) {
        recorrerAlmacen(n, m, almacen, posX, posY + 1, maximo, reponer);
    }
    else {
        // recorremos la siguiente fila desde el inicio
        recorrerAlmacen(n,m,almacen, posX+1, 0, maximo, reponer);
    }

    reponer[posX][posY] = maximo - almacen[posX][posY];
}

void pregunta2() {
    int almacen[5][5] {
        {4,3,6,8,7},
        {6,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };
    int n=5, m=5;
    int reponer[5][5];
    int maximo = 0;

    recorrerAlmacen(n,m, almacen, 0, 0, maximo, reponer);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << reponer[i][j] << " ";
        }
        cout << endl;

    }

}

int main(int argc, char** argv) {

    pregunta1();

    pregunta2();

    return 0;
}
