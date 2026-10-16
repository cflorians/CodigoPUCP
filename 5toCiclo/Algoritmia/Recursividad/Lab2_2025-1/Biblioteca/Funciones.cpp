#include <cstring>
#include <iostream>
using namespace std;
#include "Funciones.h"
#include "Lista.h"

void pregunta1() {
    struct Cuadriga elementos[4]{};

    elementos[0].id = 17;
    strcpy(elementos[0].nombre, "Messala");
    strcpy(elementos[0].color, "Rojo");

    elementos[1].id = 4;
    strcpy(elementos[1].nombre, "Ben-Hur");
    strcpy(elementos[1].color, "Azul");

    elementos[2].id = 12;
    strcpy(elementos[2].nombre, "Artax");
    strcpy(elementos[2].color, "Verde");

    elementos[3].id = 7;
    strcpy(elementos[3].nombre, "Drusus");
    strcpy(elementos[3].color, "Negro");

    struct Lista lista{};
    inicializarLista(lista);
    for (int i = 0; i < 4; i++) {
        insertarEnLista(lista, elementos[i]);
    }
    imprimirLista(lista);

    cout << "lista ordenada: "<< endl;
    reordenarLista(lista);
    imprimirLista(lista);
}

void inicializarLista(struct Lista& lista) {
    lista.inicio = nullptr;
    lista.longitud = 0;
}

void insertarEnLista(struct Lista& lista, const struct Cuadriga& elementos) {
    struct Nodo* ultimoNodo = obtenerUltimoNodo(lista);
    struct Nodo* nuevo;
    nuevo = new struct Nodo;
    nuevo->cuadriga = elementos;
    nuevo->sgte = nullptr;

    if (ultimoNodo == nullptr) {
        lista.inicio = nuevo;
    }
    else {
        ultimoNodo->sgte = nuevo;
    }
    lista.longitud++;
}

struct Nodo* obtenerUltimoNodo(struct Lista& lista) {
    struct Nodo* ultimo = nullptr;
    struct Nodo* recorrido = lista.inicio;
    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->sgte;
    }
    return ultimo;
}

void imprimirLista(const struct Lista& lista) {
    struct Nodo* recorrido = lista.inicio;
    while (recorrido != nullptr) {
        cout << "[ID: " << recorrido->cuadriga.id;
        cout << ", Nombre: " << recorrido->cuadriga.nombre;
        cout << ", Equipo: " << recorrido->cuadriga.color;
        cout << "]" << endl;
        recorrido = recorrido->sgte;
    }
    // cout << lista.longitud << endl;
}

void reordenarLista(struct Lista& lista) {
    // aqui guardaremos los pares que vayamos encontrando
    struct Nodo* paresInicio = nullptr;
    struct Nodo* paresFin = nullptr;
    // aqui guardaremos los impares que encontremos
    struct Nodo* imparesInicio = nullptr;
    struct Nodo* imparesFin = nullptr;
    // este sera nuestro recorrido de la lista
    struct Nodo* actual = lista.inicio;

    while (actual != nullptr) {
        if (actual->cuadriga.id % 2 == 0) {
            // significa que es par por lo cual lo asignamos a los pares
            // pero tenemos que revisar si pares esta vacio o no para asignarlo correctamente
            if (paresInicio == nullptr) {
                paresInicio = actual; // entonces este sera el primer par que encontramos
                paresFin = paresInicio;
            }
            else { // caso contrario lo conectaremos al final de los pares
                paresFin->sgte = actual;
                paresFin = paresFin->sgte;
            }
        }
        else {
            // significa que nos hemos encontrado con un impar
            // igual revisamos si es que es nullptr o no
            if (imparesInicio == nullptr) {
                imparesInicio = actual;
                imparesFin = imparesInicio;
            }
            else {
                imparesFin->sgte = actual;
                imparesFin = imparesFin->sgte;
            }
        }
        // agregamos esto para ir recorriendo la lista
        actual = actual->sgte;
    }

    // aqui unimos los pares con los impares
    if (paresInicio != nullptr) {
        lista.inicio = paresInicio;
        paresFin->sgte = imparesInicio;
    }
    else {
        lista.inicio = imparesInicio;
    }
    imparesFin->sgte = nullptr;
}

void pregunta2() {
    int n=6, m = 7;
    // donde 0 es vacio, el 1 es oro el 2 es roca muy dura y el 3 es las ya visitadas;
    // mapa(y,x)
    int mapa[6][7] {
        {0,1,1,1,1,1,1},
        {0,1,1,0,0,0,0},
        {0,1,0,0,0,0,0},
        {1,0,0,0,2,0,0},
        {1,1,0,0,0,0,0},
        {1,1,0,1,1,0,0}
    };
    int c = 6;

    buscarVetas(3,2, n, m, mapa, c, 0, 1);
}

void buscarVetas(int x,int y,int n,int m,int mina[][7],int combustible, int dirX, int dirY) {
    // CASO BASE
    if (combustible < 0 or x<0 or n >= m or y<0 or y>= m) return;

    int celda = mina[x][y];

    // cuando el robot choca con una roca
    if (celda == 2) {
        dirX = -dirX;
        dirY = -dirY;

        // si tiene combustible avanza en la direccion opuesta
        if (combustible > 0) {
            buscarVetas(x + dirX, y + dirY, n, m, mina, combustible - 1, dirX, dirY);
        }
        return; // para que no escanee ni deje marca
    }

    // si no es una roca, dejamos marca
    mina[x][y] = 3;

    // calculamos las direcciones de escaneo
    int pdx1, pdy1, pdx2, pdy2;
    if (dirX == 0) {
        pdx1 = 1;
        pdx2 = -1;
        pdy1 = 0;
        pdy2 = 0;
    }
    else {
        pdx1 = 0;
        pdx2 = 0;
        pdy1 = 1;
        pdy2 = -1;
    }

    // variables temporales
    int scanX, scanY;

    // Escaneo perpendicular 1
    scanX = x + pdx1;
    scanY = y + pdy1;
    while (scanX >= 0 and scanX < n and scanY >= 0 and scanY < m) {
        if (mina[scanX][scanY] == 2 or mina[scanX][scanY] == 3) break;
        if (mina[scanX][scanY] == 1) { // encuentra oro
            cout << "Oro: " << scanX << " " << scanY << endl;
            break;
        }
        scanX += pdx1;
        scanY += pdy1;
    }

    // escaneo perpendicular 2
    scanX = x + pdx2;
    scanY = y + pdy2;
    while (scanX >= 0 and scanX < n and scanY >= 0 and scanY < m) {
        if (mina[scanX][scanY] == 2 or mina[scanX][scanY] == 3) break;
        if (mina[scanX][scanY] == 1) {
            cout << "Oro: " << scanX << " " << scanY << endl;
            break;
        }
        scanX += pdx2;
        scanY += pdy2;
    }

    // escaneo hacia atras
    int opx = -dirX;
    int opy = -dirY;
    scanX = x + opx;
    scanY = y + opy;
    while (scanX >= 0 and scanX < n and scanY >= 0 and scanY < m) {
        if (mina[scanX][scanY] == 2 or mina[scanX][scanY] == 3) break;
        if (mina[scanX][scanY] == 1) {
            cout << "Oro: " << scanX << " " << scanY << endl;
            break;
        }
        scanX += opx;
        scanY += opy;
    }

    // PARTE RECURSIVA
    if (combustible > 0) {
        buscarVetas(x + dirX, y + dirY, n, m, mina, combustible - 1, dirX, dirY);
    }

}