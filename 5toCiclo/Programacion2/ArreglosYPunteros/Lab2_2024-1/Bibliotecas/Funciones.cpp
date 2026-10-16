#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
enum libros{CODIGO, TITULO, AUTOR};
enum stock{INICIAL, NO_ATENDIDA};
enum clientes{DNI, CANTPEDIDOS, PEDIDOS};

#include "Funciones.h"

void lecturaDeLibros(const char* nombArch,char***& libros,int**& stock) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    // IIM5175,Diamantes y pedernales,Jose Maria Arguedas,2
    // codigo ,Nombre del libro      , autor             , stock
    char codigo[8], titulo[70], autor[50];
    int s; //stock para los amigos
    char*** bufferLibros = new char**[300];
    int** bufferStock = new int*[300];
    int cant = 0;

    while (true) {
        arch.getline(codigo, 8, ',');
        arch.getline(titulo, 70, ',');
        arch.getline(autor, 50, ',');
        arch >> s;
        arch.get();

        if (arch.eof()) break;

        bufferLibros[cant] = new char*[3];
        bufferStock[cant] = new int[2];

        char** registroLibro = new char*[3];
        registroLibro[CODIGO] = new char[strlen(codigo)+1];
        strcpy(registroLibro[CODIGO], codigo);

        registroLibro[TITULO] = new char[strlen(titulo)+1];
        strcpy(registroLibro[TITULO], titulo);

        registroLibro[AUTOR] = new char[strlen(autor)+1];
        strcpy(registroLibro[AUTOR], autor);

        int* registroStock = new int[2];
        registroStock[INICIAL] = s;
        registroStock[NO_ATENDIDA] = 0;

        bufferLibros[cant] = registroLibro;
        bufferStock[cant] = registroStock;

        cant++;
    }

    libros = new char**[cant+1]{};
    stock = new int*[cant+1]{};
    for (int i = 0; i < cant; i++) {
        libros[i] = bufferLibros[i];
        stock[i] = bufferStock[i];
    }
}

void pruebaDeLecturaDeLIbros(const char* nombArch,char*** libros,int** stock) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    char** libroPorLibro = nullptr;
    int* stockPorLibro = nullptr;

    arch << setw(20) << left << "CODIGO" << setw(67) << "TITULO" << setw(26) << "AUTOR" << "STOCK" << endl;
    for (int i = 0; libros[i]; i++) {
        libroPorLibro = libros[i];
        stockPorLibro = stock[i];

        arch << left << setw(10) << libroPorLibro[CODIGO];
        arch << setw(70) << libroPorLibro[TITULO];
        arch << setw(30) << libroPorLibro[AUTOR];
        arch << right << setw(5) << stockPorLibro[INICIAL];
        arch << setw(5) << stockPorLibro[NO_ATENDIDA];
        arch << endl;
    }
}

void atencionDePedidos(const char* nombArch,char*** libros,int** stock,int**& pedidosClientes,
                       char***& pedidosLibros,bool**& pedidosAtendidos) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir " << nombArch << endl;
        exit(1);
    }

    // 000132,69200503   CPE5718     KGO1734     IUG2294      ILG7766
    // numPedido, dniCliente, librosSolicitados
    int numPedido, dniCliente;
    char libroSolicitado[10];
    char* librosSolicitados[10];
    int cant = 0;
    int cantLibrosPedidos = 0;

    char*** bufferPedidosLibros = new char**[200]{};
    int** bufferPedidosClientes = new int*[200]{};
    bool** bufferPedidosAtendidos = new bool*[200]{};

    while (true) {
        arch >> numPedido;
        arch.get();
        arch >> dniCliente;
        cantLibrosPedidos = 0;
        while (arch.peek() != '\n') {
            arch >> libroSolicitado;
            strcpy(librosSolicitados[cantLibrosPedidos], libroSolicitado);
            cantLibrosPedidos++;
        }

        if (arch.eof()) break;

        int* registrarPedidosClientes = new int[3]{};
        registrarPedidosClientes[DNI] = dniCliente;
        registrarPedidosClientes[CANTPEDIDOS] = numPedido;
        registrarPedidosClientes[PEDIDOS + registrarPedidos]

        cant++;
    }
}