#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAdicionales.h"

void leerDatosAlumnos(int* codigoAlumno, char** nombreAlumno, char* escalaAlumno, int& cantAlumnos) {
    //20227341   Landa_Piscoya_Christian   D
    char nombre[50]{};

    ifstream arch("ArchivosDeDatos/Alumnos_lab7.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de alumnos" << endl;
        exit(1);
    }

    cantAlumnos = 0;

    while (arch >> codigoAlumno[cantAlumnos]) {
        arch >> nombre;
        arch >> escalaAlumno[cantAlumnos];

        toMayus(nombre);
        quitarGuiones(nombre);

        nombreAlumno[cantAlumnos] = insertarNombre(nombre);

        cantAlumnos++;
    }
}

void quitarGuiones(char* cadena) {
    for (int i=0; cadena[i] ; i++) {
        if (cadena[i] == '_') cadena[i] = ' ';
    }
}

void toMayus(char* cadena) {
    for (int i=0; cadena[i] ; i++) {
        if ('a' <= cadena[i] and cadena[i] <= 'z') cadena[i] -= 'a'-'A';
    }
}

char* insertarNombre(char* cadena) {
    char* nueva = new char[strlen(cadena) + 1];
    strcpy(nueva, cadena);
    return nueva;
}

void leerDatosCursos(int* codigoCurso, double* creditosCurso, int& cantCursos) {
    // 231289    Turbomaquinas_Y_Maquinas_De_Desplazamiento_Positivo    3.00
    char nombreCurso[75]{};

    ifstream arch("ArchivosDeDatos/Cursos_lab7.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de cursos" << endl;
        exit(1);
    }

    cantCursos = 0;

    while (arch >> codigoCurso[cantCursos]) {
        arch >> nombreCurso >> creditosCurso[cantCursos];

        cantCursos++;
    }
}

void leerDatosEscalas(int *anioEscala, int* cicloEscala, char* escalaValor, double* costoCredito, int& cantEscalas) {
    // 2021-2    C    288.65
    char c;

    ifstream arch("ArchivosDeDatos/Escalas_lab7.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de escalas" << endl;
        exit(1);
    }

    cantEscalas = 0;

    while (arch >> anioEscala[cantEscalas]) {
        arch >> c >> cicloEscala[cantEscalas];
        arch >> escalaValor[cantEscalas];
        arch >> costoCredito[cantEscalas];

        cantEscalas++;
    }
}

void procesarMatricula(int anio, int ciclo, int* cantCursosAlumno, double* numCreditosAlumno, double* montoPagado,
                       int* codigoCurso, double* creditosCurso, int& cantCursos, int* codigoAlumno,
                       char* escalaAlumno, int cantAlumnos, int *anioEscala, int* cicloEscala, char* escalaValor,
                       double* costoCredito, int cantEscalas){
    // 2022-1    20212697    481203    109239
    // ciclo    codigoAlum   cursos matriculados
    int anioActual, cicloActual, codigoAlumnoActual, cursoActual, posAlumno, posCurso, posCredito;
    double creditos, costoPorCredito;
    char c;

    ifstream arch("ArchivosDeDatos/Matricula_lab7.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de matricula" << endl;
        exit(1);
    }

    while (arch >> anioActual >> c >> cicloActual) {
        creditos = 0;

        if (anioActual == anio and cicloActual == ciclo) {
            arch >> codigoAlumnoActual;
            posAlumno = buscarAlumno(codigoAlumnoActual, codigoAlumno, cantAlumnos);

            while (arch.peek() != '\n') {
                arch >> cursoActual;
                posCurso = buscarCurso(cursoActual, codigoCurso, cantCursos);
                creditos += creditosCurso[posCurso];
                cantCursosAlumno[posAlumno]++;
            }

            posCredito = buscarValorCredito(escalaAlumno[posAlumno], anioActual, cicloActual, anioEscala, cicloEscala,
                                            escalaValor, cantEscalas);
            costoPorCredito = costoCredito[posCredito];

            montoPagado[posAlumno] = creditos*costoPorCredito;
            numCreditosAlumno[posAlumno] = creditos;
        }
        else while (arch.get() != '\n');
    }
}

int buscarAlumno(int codigoBuscado, int* codigoAlumno, int cantAlumnos) {
    int inicio, medio, fin, i;
    inicio = 0;
    fin = cantAlumnos;

    for (i = 0; i < cantAlumnos; i++) {
        medio = (inicio + fin) / 2;
        if (codigoBuscado == codigoAlumno[medio]) return medio;
        if (codigoBuscado < codigoAlumno[medio]) fin = medio-1;
        if (codigoBuscado > codigoAlumno[medio]) inicio = medio+1;
    }
    return -1;
}

int buscarCurso(int cursoBuscado, int* codigoCurso, int cantCursos) {
    int inicio, medio, fin, i;
    inicio = 0;
    fin = cantCursos;

    for (i = 0; i < cantCursos; i++) {
        medio = (inicio + fin) / 2;
        if (cursoBuscado == codigoCurso[medio]) return medio;
        if (cursoBuscado < codigoCurso[medio]) fin = medio-1;
        if (cursoBuscado > codigoCurso[medio]) inicio = medio+1;
    }
    return -1;
}

int buscarValorCredito(char escalaAlumno, int anio, int ciclo, int* anioEscalas, int* cicloEscalas,
                       char* escalaValor, int cantEscalas) {
    int i;
    for (i=0; i < cantEscalas; i++) {
        if (anio == anioEscalas[i] and ciclo == cicloEscalas[i] and escalaAlumno == escalaValor[i]) return i;
    }
    return -1;
}

void ordenarAlumnos(int* codigoAlumno, char** nombreAlumno, char* escalaAlumno, int cantAlumnos) {
    int temp;
    char *tempPuntero;
    char tempChar;
    for (int i = 0; i < cantAlumnos-1; i++) {
        for (int j=i+1; j<cantAlumnos; j++) {
            if (codigoAlumno[i] > codigoAlumno[j]) {
                temp = codigoAlumno[i];
                codigoAlumno[i] = codigoAlumno[j];
                codigoAlumno[j] = temp;

                tempPuntero = nombreAlumno[i];
                nombreAlumno[i] = nombreAlumno[j];
                nombreAlumno[j] = tempPuntero;

                tempChar = escalaAlumno[i];
                escalaAlumno[i] = escalaAlumno[j];
                escalaAlumno[j] = tempChar;
            }
        }
    }
}

void ordenarCursos(int* codigoCurso, double* creditosCurso, int cantCursos) {
    int tempInt;
    double tempDouble;
    for (int i = 0; i < cantCursos-1; i++) {
        for (int j=i+1; j<cantCursos; j++) {
            if (codigoCurso[i] > codigoCurso[j]) {
                tempInt = codigoCurso[i];
                codigoCurso[i] = codigoCurso[j];
                codigoCurso[j] = tempInt;

                tempDouble = creditosCurso[i];
                creditosCurso[i] = creditosCurso[j];
                creditosCurso[j] = tempDouble;
            }
        }
    }
}

void emitirReporte(int anio, int ciclo, int* codigoAlumno, char** nombreAlumno, int* cantCursosAlumno,
                   double* numCreditosAlumno, char* escalaAlumno, double* montoPagado,int cantAlumnos) {
    double montoTotal=0;

    ofstream reporte("ArchivosDeReporte/ReporteDePagoPorAlumno.txt", ios::out);

    emitirEncabezado(reporte, anio, ciclo);
    for (int i=0; i < cantAlumnos; i++) {
        reporte << setfill('0');
        reporte << setw(2) << i+1 << ')';
        reporte << setfill(' ');

        reporte << setw(11) << codigoAlumno[i] << " - " << nombreAlumno[i] << setw(40-strlen(nombreAlumno[i]))
                << cantCursosAlumno[i] << setw(15) << fixed << setprecision(2) << numCreditosAlumno[i]
                << setw(10) << escalaAlumno[i] << setw(17) << montoPagado[i] << endl;

        montoTotal += montoPagado[i];
    }

    separadorCaracter(reporte, '-');
    reporte << "MONTO TOTAL PAGADO: " << setw(79) << montoTotal << endl;
    separadorCaracter(reporte, '=');
}

void emitirEncabezado(ofstream& reporte, int anio, int ciclo) {
    reporte << setw(63) << "INSTITUCION EDUCATIVA_TP" << endl;
    reporte << setw(68) << "DETALLES DE PAGO REALIZADO POR CICLO" << endl;
    reporte << setw(51) << "CICLO: " << anio << '-' << ciclo << endl;
    separadorCaracter(reporte, '=');
    reporte << setw(3) << "No." << setw(11) << "ALUMNO" << setw(47) << "No. DE CURSOS" << setw(13) << "CREDITOS"
            << setw(10) << "ESCALA" << setw(16) << "MONTO PAGADO" << endl;
    separadorCaracter(reporte, '-');
}

void separadorCaracter(ofstream& reporte, char separador) {
    reporte << setfill(separador);
    reporte << setw(100) << separador << endl;
    reporte << setfill(' ');
}

void ordenarPorEscalaYNombre(int* codigoAlumno, char** nombreAlumno, int* cantCursosAlumno,
                             double* numCreditosAlumno, char* escalaAlumno, double* montoPagado,int cantAlumnos) {
    int tempInt;
    double tempDouble;
    char tempChar;
    char* tempStr;
    for (int i=0; i < cantAlumnos-1; i++) {
        for (int j=i+1; j < cantAlumnos; j++) {
            if (escalaAlumno[i] > escalaAlumno[j]) {
                tempInt = codigoAlumno[i];
                codigoAlumno[i] = codigoAlumno[j];
                codigoAlumno[j] = tempInt;

                tempStr = nombreAlumno[i];
                nombreAlumno[i] = nombreAlumno[j];
                nombreAlumno[j] = tempStr;

                tempInt = cantCursosAlumno[i];
                cantCursosAlumno[i] = cantCursosAlumno[j];
                cantCursosAlumno[j] = tempInt;

                tempDouble = numCreditosAlumno[i];
                numCreditosAlumno[i] = numCreditosAlumno[j];
                numCreditosAlumno[j] = tempDouble;

                tempDouble = montoPagado[i];
                montoPagado[i] = montoPagado[j];
                montoPagado[j] = tempDouble;

                tempChar = escalaAlumno[i];
                escalaAlumno[i] = escalaAlumno[j];
                escalaAlumno[j] = tempChar;
            }
            if (escalaAlumno[i] == escalaAlumno[j] and strcmp(nombreAlumno[i], nombreAlumno[j]) > 0) {
                //intercambiar otra vez
                tempInt = codigoAlumno[i];
                codigoAlumno[i] = codigoAlumno[j];
                codigoAlumno[j] = tempInt;

                tempStr = nombreAlumno[i];
                nombreAlumno[i] = nombreAlumno[j];
                nombreAlumno[j] = tempStr;

                tempInt = cantCursosAlumno[i];
                cantCursosAlumno[i] = cantCursosAlumno[j];
                cantCursosAlumno[j] = tempInt;

                tempDouble = numCreditosAlumno[i];
                numCreditosAlumno[i] = numCreditosAlumno[j];
                numCreditosAlumno[j] = tempDouble;

                tempDouble = montoPagado[i];
                montoPagado[i] = montoPagado[j];
                montoPagado[j] = tempDouble;
            }
        }
    }
}
