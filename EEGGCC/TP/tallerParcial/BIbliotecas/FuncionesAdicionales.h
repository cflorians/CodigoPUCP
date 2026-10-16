
#ifndef TALLERPARCIAL_FUNCIONESADICIONALES_H
#define TALLERPARCIAL_FUNCIONESADICIONALES_H

void abrirArchivos(ifstream& arch, const char* nombreArch);
void abrirArchivos(ofstream& arch, const char* nombreArch);
void cargarDatosLibros(ifstream& arch, int* codigoLibro, double* precioLibro, int& cantLibros);
void generarReporteSimple(ofstream& arch, int* codigoLibro, double* precioLibro, int cantLibros);
int buscarPosicion(double* precioLibro, int cantLibros, double precio);
void generarEspacioParaNuevoDato(int* codigoLibro, double* precioLibro, int cantLibros, int pos);
void saltarTextoHasta(ifstream& arch, char limitador);

#endif //TALLERPARCIAL_FUNCIONESADICIONALES_H