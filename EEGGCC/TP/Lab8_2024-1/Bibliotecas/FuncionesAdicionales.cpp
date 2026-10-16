#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Estructuras.h"
using namespace std;

#include "FuncionesAdicionales.h"

void leerDatosCalificaciones(struct Alumno *arrAlumnos, int& cantAlumnos) {
    ifstream arch("ArchivosDeDatos/Calificaciones_laboratorio8.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de Calificaciones.txt" << endl;
        exit(1);
    }
    // DER614   5.75   20238549   16   20205830   17   20205844
    // codCurso cred   codAlumno  nota
    cantAlumnos = 0;
    char codCurso[10]{};
    double creditosCurso;
    int codAlumno, nota, pos;
    while (arch >> codCurso >> creditosCurso) {

        while (arch.peek() != '\n') {
            arch >> codAlumno >> nota;

            pos = buscarPosAlumno(arrAlumnos, codAlumno, cantAlumnos);
            if (pos == cantAlumnos) {
                arrAlumnos[pos].codigo = codAlumno;
                cantAlumnos++;
            }
            arrAlumnos[pos].numeroDeCreditos += creditosCurso;
            arrAlumnos[pos].sumaPonderada += nota*creditosCurso;
            arrAlumnos[pos].numeroDeCursos++;
        }
    }

    for (int i=0; i<cantAlumnos; i++) {
        arrAlumnos[i].promedioPonderado = arrAlumnos[i].sumaPonderada / arrAlumnos[i].numeroDeCreditos;
    }
}

int buscarPosAlumno(const struct Alumno *arrAlumnos, int codAlumno, int cantAlumnos) {
    for (int i=0; i < cantAlumnos; i++) {
        if (codAlumno == arrAlumnos[i].codigo) return i;
    }
    return cantAlumnos;
}

void leerDatosAlumnos(struct Alumno *arrAlumnos, int cantAlumnos) {
    ifstream arch("ArchivosDeDatos/Alumnos_laboratorio8.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de alumnos.csv" << endl;
        exit(1);
    }

    // 20227341,DIAZ ANTEZANO MAGALI SILVANA,EEGGCC
    int codAlumno, pos;
    char nombreAlumno[40]{}, facultad[15]{};

    while (arch >> codAlumno) {
        arch.ignore();
        arch.getline(nombreAlumno, 40, ',');
        arch.getline(facultad, 15, '\n');
        pos = buscarPosAlumno(arrAlumnos, codAlumno, cantAlumnos);
        strcpy(arrAlumnos[pos].nombre, nombreAlumno);
        strcpy(arrAlumnos[pos].facultad.codigo, facultad);
    }
}

void leerDatosFacultades(struct Alumno *arrAlumnos, int cantAlumnos) {
    ifstream arch("ArchivosDeDatos/Facultades_laboratorio8.txt", ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo de Facultades.txt" << endl;
        exit(1);
    }

    char nombreFacu[40]{}, codFacu[15]{};

    while (arch >> nombreFacu >> codFacu) {
        quitarGuiones(nombreFacu);
        for (int i=0; i < cantAlumnos; i++) {
            if (strcmp(arrAlumnos[i].facultad.codigo, codFacu) == 0) {
                strcpy(arrAlumnos[i].facultad.nombre, nombreFacu);
            }
        }
    }
}

void emitirReporte(struct Alumno *arrAlumnos, int cantAlumnos) {
    ofstream reporte("ArchivosDeReporte/ReporteDePagoPorAlumno.txt", ios::out);

    int posMaxCreditos;
    double maxCreditos=0;

    emitirEncabezado(reporte);
    procesarAlumno(reporte, arrAlumnos, cantAlumnos, maxCreditos, posMaxCreditos);
    separador(reporte,'=');
    reporte << "Alumno con mayor numero de creditos matriculados: "<< endl << setw(19) << ' ';
    reporte << arrAlumnos[posMaxCreditos].nombre << " [" << arrAlumnos[posMaxCreditos].codigo << "]" << " con "
            << arrAlumnos[posMaxCreditos].numeroDeCreditos << " creditos de la " << arrAlumnos[posMaxCreditos].facultad.nombre << endl;

}

void procesarAlumno(ofstream& reporte, struct Alumno *arrAlumnos, int cantAlumnos, double& maxCreditos, int& posMaxCreditos) {
    for (int i=0; i < cantAlumnos; i++) {
        reporte << arrAlumnos[i].codigo << " - " << arrAlumnos[i].nombre << setw(45 - strlen(arrAlumnos[i].nombre))
                << arrAlumnos[i].numeroDeCursos << setw(18) << fixed << setprecision(2) << arrAlumnos[i].sumaPonderada << setw(15) << fixed << setprecision(2)
                << arrAlumnos[i].numeroDeCreditos << setw(17) << fixed << setprecision(2) << arrAlumnos[i].promedioPonderado
                << setw(strlen(arrAlumnos[i].facultad.nombre) + 8) << arrAlumnos[i].facultad.nombre << endl;
        if (arrAlumnos[i].numeroDeCreditos > maxCreditos) {
            maxCreditos = arrAlumnos[i].numeroDeCreditos;
            posMaxCreditos = i;
        }
    }
}

void emitirEncabezado(ofstream& reporte) {
    reporte << setw(80) << "INSTITUCION EDUCATIVA_TP" << endl;
    reporte << setw(89) << "PROMEDIO PONDERADO DE ALUMNOS MATRICULADOS" << endl;
    reporte << setw(75) << "CICLO: 2024-1" << endl;
    reporte << setw(79) << "TODAS LAS FACULTADES" << endl;
    separador(reporte, '=');
    reporte << setw(11) << "ALUMNO" << setw(49) << "No. de Cursos" << setw(17) << "Suma Ponderada" << setw(17) << "No. de Creditos"
            << setw(16) << "Prom Ponderado" << setw(12) << "Facultad" << endl;
    separador(reporte, '-');
}

void separador(ofstream& reporte, char separador) {
    reporte << setfill(separador);
    reporte << setw(140) << separador << endl;
    reporte << setfill(' ');
}

void quitarGuiones(char *cadena) {
    for (int i=0; cadena[i]; i++) {
        if (cadena[i] == '_') cadena[i] = ' ';
    }
}