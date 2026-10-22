/* ejemplo1_mapa_bits.c — Guía previa del laboratorio 4
 * Mapa de bits para administrar la memoria libre de una máquina sin abstracción.
 * Compilar: gcc -std=c17 -Wall -Wextra -g ejemplo1_mapa_bits.c -o ejemplo1
 */
#include <stdio.h>

#define RAM_KIB 128
#define UNIDAD_KIB 4
#define N_UNIDADES (RAM_KIB / UNIDAD_KIB)   /* 128/4 = 32 unidades */

/* Un bit por unidad: 32 unidades = 4 bytes de mapa. */
static unsigned char mapa[N_UNIDADES / 8];

static int bit_en(int unidad)
{
    return (mapa[unidad / 8] >> (unidad % 8)) & 1;
}

static void marcar(int unidad)
{
    mapa[unidad / 8] |= (unsigned char)(1u << (unidad % 8));
}

static void desmarcar(int unidad)
{
    mapa[unidad / 8] &= (unsigned char)~(1u << (unidad % 8));
}

static void imprimir_mapa(void)
{
    int u;

    printf("  ");
    for (u = 0; u < N_UNIDADES; u++) {
        putchar(bit_en(u) ? '1' : '0');
        if (u % 8 == 7)
            putchar(' ');
    }
    printf("   (byte 0 = unidades 0-7, byte 1 = unidades 8-15, ...)\n");
}

/* Primer ajuste sobre el mapa: busca la primera corrida de n unidades
 * libres, las marca y devuelve la unidad donde empiezan. */
static int asignar_unidades(int n)
{
    int corrida = 0;
    int u, k;

    for (u = 0; u < N_UNIDADES; u++) {
        if (bit_en(u)) {
            corrida = 0;
        } else {
            corrida++;
            if (corrida == n) {
                for (k = u - n + 1; k <= u; k++)
                    marcar(k);
                return u - n + 1;
            }
        }
    }
    return -1;
}

static void liberar_unidades(int inicio, int n)
{
    int k;

    for (k = inicio; k < inicio + n; k++)
        desmarcar(k);
}

int main(void)
{
    int a, b, c;

    printf("RAM de %d KiB con unidades de %d KiB: %d unidades = %d bits = %d bytes de mapa.\n",
           RAM_KIB, UNIDAD_KIB, N_UNIDADES, N_UNIDADES, N_UNIDADES / 8);

    printf("Arranque:\n");
    imprimir_mapa();

    a = asignar_unidades(6);    /* 6 x 4 KiB = 24 KiB */
    b = asignar_unidades(3);    /* 3 x 4 KiB = 12 KiB */
    printf("Se asignan 24 KiB (unidad %d) y 12 KiB (unidad %d):\n", a, b);
    imprimir_mapa();

    liberar_unidades(a, 6);
    printf("Se liberan los 24 KiB:\n");
    imprimir_mapa();

    c = asignar_unidades(5);
    printf("Se asignan 20 KiB: caen a partir de la unidad %d (dirección física %d KiB).\n",
           c, c * UNIDAD_KIB);
    imprimir_mapa();

    return 0;
}
