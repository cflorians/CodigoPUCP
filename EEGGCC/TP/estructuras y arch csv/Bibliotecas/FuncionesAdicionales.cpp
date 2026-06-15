#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Estructuras.h"
using namespace std;

#include "FuncionesAdicionales.h"

void leerDatos(struct Empresa *empresa, int& cantEmpresas) {
    ifstream arch("ArchivosDeDatos/EmpresasRegistradas_Lab08.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de empresas" << endl;
        exit(1);
    }

    // 79672079,contreras chang johana cinthia,Chorrillos
    cantEmpresas = 0;
    while (arch >> empresa[cantEmpresas].dni) {
        arch.ignore();
        arch.getline(empresa[cantEmpresas].representante, 50, ',');
        arch.getline(empresa[cantEmpresas].distrito, 50, '\n');
        cantEmpresas++;
    }
}

void mostrarDatos(const struct Empresa *empresa, int cantEmpresas) {
    ofstream reporte("ArchivosDeReporte/reporte.txt", ios::out);

    for (int i=0; i<cantEmpresas; i++) {
        reporte << empresa[i].dni << setw(5) << ' ' << empresa[i].representante;
        reporte << setw(65-strlen(empresa[i].representante)) << empresa[i].distrito << endl;
    }
}

void toMayusIniciales(char* cadena) {
    for (int i=0; cadena[i]; i++) {
        if (cadena[i-1] == ' ' or i==0) cadena[i] -= 'a' - 'A';
    }
}

void toMayus(char* cadena) {
    for (int i=0; cadena[i]; i++) {
        if ('a' <= cadena[i] and cadena[i] <= 'z') cadena[i] -= 'a' - 'A';
    }
}

void ordenarPorDistrito(struct Empresa *empresa, int cantEmpresas) {
    for (int i=0; i<cantEmpresas-1; i++) {
        for (int j=i+1; j<cantEmpresas; j++) {
            if (strcmp(empresa[i].distrito, empresa[j].distrito) > 0) {
                int temp = empresa[i].dni;
                empresa[i].dni = empresa[j].dni;
                empresa[j].dni = temp;

                char tempRepresentante[50];
                strcpy(tempRepresentante, empresa[i].representante);
                strcpy(empresa[i].representante, empresa[j].representante);
                strcpy(empresa[j].representante, tempRepresentante);

                char tempDistrito[50];
                strcpy(tempRepresentante, empresa[i].distrito);
                strcpy(empresa[i].distrito, empresa[j].distrito);
                strcpy(empresa[j].distrito, tempRepresentante);
            }
            if (strcmp(empresa[i].distrito, empresa[j].distrito) == 0 and
                strcmp(empresa[i].representante, empresa[j].representante) > 0) {
                int temp = empresa[i].dni;
                empresa[i].dni = empresa[j].dni;
                empresa[j].dni = temp;

                char tempRepresentante[50];
                strcpy(tempRepresentante, empresa[i].representante);
                strcpy(empresa[i].representante, empresa[j].representante);
                strcpy(empresa[j].representante, tempRepresentante);

                char tempDistrito[50];
                strcpy(tempRepresentante, empresa[i].distrito);
                strcpy(empresa[i].distrito, empresa[j].distrito);
                strcpy(empresa[j].distrito, tempRepresentante);
            }
        }
    }
}