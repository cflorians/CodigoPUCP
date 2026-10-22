/* ejemplo3_reubicacion.c — Guía previa del laboratorio 4
 * Reubicación estática en carga: sin MMU, el cargador traslada las direcciones.
 * Compilar: gcc -std=c17 -Wall -Wextra -g ejemplo3_reubicacion.c -o ejemplo3
 */
#include <stdio.h>

typedef struct {
    char op;    /* 'L' = leer de la dirección, 'E' = escribir en la dirección */
    int addr;   /* dirección relativa en bytes, tal como la dejó el compilador */
} Instruccion;

static void imprimir(const Instruccion *p, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("  %c %7d\n", p[i].op, p[i].addr);
}

/* El cargador suma la base de la partición a cada dirección del programa. */
static void reubicar(Instruccion *p, int n, int base)
{
    int i;

    for (i = 0; i < n; i++)
        p[i].addr += base;
}

int main(void)
{
    Instruccion prog[] = {
        { 'L',  16 },
        { 'L',  28 },
        { 'E',  16 },
    };
    int n = (int)(sizeof(prog) / sizeof(prog[0]));
    int base = 128 * 1024;  /* la partición empieza en 128 KiB = 131072 bytes */

    printf("Programa tal como lo dejó el compilador (direcciones en bytes, relativas a 0):\n");
    imprimir(prog, n);

    reubicar(prog, n, base);
    printf("El cargador lo coloca en la partición que empieza en %dK (%d bytes) y suma la base a cada dirección:\n",
           base / 1024, base);
    imprimir(prog, n);

    printf("La instrucción 'L 16' habría leído el byte físico 16; reubicada lee el byte físico %d (128K + 16).\n",
           base + 16);
    return 0;
}
