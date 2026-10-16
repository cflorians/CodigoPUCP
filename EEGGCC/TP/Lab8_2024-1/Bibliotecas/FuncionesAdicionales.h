
#ifndef LAB8_2024_1_FUNCIONESADICIONALES_H
#define LAB8_2024_1_FUNCIONESADICIONALES_H

void leerDatosCalificaciones(struct Alumno *arrAlumnos, int& cantAlumnos);
int buscarPosAlumno(const struct Alumno *arrAlumnos, int codAlumno, int cantAlumnos);
void leerDatosAlumnos(struct Alumno *arrAlumnos, int cantAlumnos);
void leerDatosFacultades(struct Alumno *arrAlumnos, int cantAlumnos);
void separador(ofstream& reporte, char separador);
void emitirEncabezado(ofstream& reporte);
void emitirReporte(struct Alumno *arrAlumnos, int cantAlumnos);
void procesarAlumno(ofstream& reporte, struct Alumno *arrAlumnos, int cantAlumnos, double& maxCreditos, int& posMaxCreditos);
void quitarGuiones(char *cadena);

#endif //LAB8_2024_1_FUNCIONESADICIONALES_H