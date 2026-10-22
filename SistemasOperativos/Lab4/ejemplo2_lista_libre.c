/* ejemplo2_lista_libre.c — Guía previa del laboratorio 4
 * Lista de agujeros ordenada por dirección y política de primer ajuste.
 * Compilar: gcc -std=c17 -Wall -Wextra -g ejemplo2_lista_libre.c -o ejemplo2
 */
#include <stdio.h>

#define MAX_AGUJEROS 8

typedef struct {
    int inicio;     /* dirección física donde empieza el agujero, en KiB */
    int tam;        /* tamaño del agujero, en KiB */
} Agujero;

/* Tres agujeros iniciales: el resto de la RAM está ocupado. */
static Agujero agujeros[MAX_AGUJEROS] = {
    {   0, 64 },
    {  96, 64 },
    { 224, 32 },
};
static int n_agujeros = 3;

static void imprimir_lista(void)
{
    int i;

    printf("  Lista:");
    if (n_agujeros == 0) {
        printf(" vacía\n");
        return;
    }
    for (i = 0; i < n_agujeros; i++)
        printf(" [%dK..%dK)", agujeros[i].inicio,
               agujeros[i].inicio + agujeros[i].tam);
    printf("\n");
}

static void quitar(int i)
{
    int j;

    n_agujeros--;
    for (j = i; j < n_agujeros; j++)
        agujeros[j] = agujeros[j + 1];
}

/* Primer ajuste: toma el primer agujero que alcanza y lo parte.
 * Devuelve la dirección física donde empieza el bloque, o -1. */
static int asignar(int tam)
{
    int i;

    for (i = 0; i < n_agujeros; i++) {
        if (agujeros[i].tam >= tam) {
            int inicio = agujeros[i].inicio;

            agujeros[i].inicio += tam;
            agujeros[i].tam -= tam;
            if (agujeros[i].tam == 0)
                quitar(i);
            return inicio;
        }
    }
    return -1;
}

/* Pide "tam" KiB e informa el resultado. -1 no es una dirección: es el
 * aviso de que ningún agujero alcanza. */
static void pedir(int tam)
{
    int inicio = asignar(tam);

    if (inicio == -1)
        printf("asignar %3dK -> rechazada: ningún agujero alcanza\n", tam);
    else
        printf("asignar %3dK -> empieza en %dK\n", tam, inicio);
    imprimir_lista();
}

int main(void)
{
    imprimir_lista();
    pedir(20);
    pedir(50);
    pedir(44);
    pedir(100);
    return 0;
}
