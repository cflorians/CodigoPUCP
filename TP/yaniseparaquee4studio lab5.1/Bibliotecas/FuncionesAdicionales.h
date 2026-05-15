//
// Created by carlo on 5/10/2025.
//

#ifndef YANISEPARAQUEE4STUDIO_LAB5_1_FUNCIONESADICIONALES_H
#define YANISEPARAQUEE4STUDIO_LAB5_1_FUNCIONESADICIONALES_H

void cargarProductos(int* codigo, double* precio, int &cantidad);
void mostrarArreglos(int *codigo, double* precio, int cantidad);
void eliminarRepetidos(int *codigo, double* precio, int cantidad, int *codSinRep, double* precioSinRep, int &cantSinRep);
void ordenarArreglo(int *codSinRep, double* precioSinRep, int cantSinRep);
void hallarMinYMax(double* precioSinRep, int cantSinRep, double &min, double &max);
double buscadorPrecio(int codigoBuscado, int *codSinRep, double* precioSinRep, int cantSinRep);

#endif //YANISEPARAQUEE4STUDIO_LAB5_1_FUNCIONESADICIONALES_H