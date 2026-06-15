//
// Created by carlo on 10/30/2025.
//

#ifndef LAB7_2024_2_FUNCIONESADICIONALES_H
#define LAB7_2024_2_FUNCIONESADICIONALES_H

void leerRepartidores(int* dni, int* codDist, int& cantRepartidores, char** nombre, char** vehiculo, char** nomDistRepartidor);
void eliminarGuiones(char* cadena);
void toMayus(char* cadena);
char* asiginarChar(char* cadena);
void leerPlatosOfrecidos(int* codigoPlato, double* precioPlato, double* descuentoPlato, char** nombrePlato, char** categoriaPlato, int& cantPlatos);
double atod(char* cadena);
void verificarAsignacion(int* dniRepartidores,int* codDistRepartidores,int cantRepartidores,char** nombreRepartidores,char** vehiculoRepartidores,
                         char** nomDistRepartidores,int* codPlatos,double* precioPlatos,double* descuentoPlatos,char** nombrePlatos,char** categoriaPlatos,
                         int cantPlatos, const char* archivo);
void ordenarPorNombre(int* dniRepartidor, int* codDistRepartidor, int cantRepartidores, char** nombreRepartidor, char** vehiculoRepartidor, char** nomDistRepartidor);
void intercambiarDatos(int* arr1, int pos1, int pos2);
void intercambiarDatos(char** arr, int pos1, int pos2);
void leerRepartos(int* codDistRepartidor, char** vehiculoRepartidor, int* totalPlatosRepartidor, double* montoTotalPorPlato,
                  double* descuentoPorPlatos, double* descuentoPorCliente, double* pagoARepartidor, double* totalIngresadoRepartidor,
                  double* montoVendidoPlato, double* decuentoPlato,double* descuentoAlCliente, double* totalIngresadoPlato, int cantRepartidores);

#endif //LAB7_2024_2_FUNCIONESADICIONALES_H