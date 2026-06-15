
#ifndef ESTRUCTURAS_Y_ARCH_CSV_FUNCIONESADICIONALES_H
#define ESTRUCTURAS_Y_ARCH_CSV_FUNCIONESADICIONALES_H

void leerDatos(struct Empresa *empresa, int& cantEmpresas);
void mostrarDatos(const struct Empresa *empresa, int cantEmpresas);
void toMayusIniciales(char* cadena);
void toMayus(char* cadena);
void ordenarPorDistrito(struct Empresa *empresa, int cantEmpresas);

#endif //ESTRUCTURAS_Y_ARCH_CSV_FUNCIONESADICIONALES_H