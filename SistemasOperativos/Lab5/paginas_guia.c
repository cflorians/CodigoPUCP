#define _POSIX_C_SOURCE 200809L
/* paginas_guia.c — Guía previa del laboratorio 5 (Algoritmos de paginación)
 * Curso:  1INF29 Sistemas Operativos · PUCP · 2026-2
 * Estado: versión 1
 *
 * Simulador de reemplazo de páginas para la guía previa, con dos algoritmos:
 *   fifo : desaloja la página que lleva más tiempo cargada.
 *   opt  : algoritmo óptimo; desaloja la página cuya próxima referencia está
 *          más lejos (o que ya no se vuelve a pedir).
 * En la sesión se entrega la versión completa, con más algoritmos.
 *
 * Compilar: gcc -std=c17 -Wall -Wextra -g paginas_guia.c -o paginas
 *
 * Uso:
 *   ./paginas <fifo|opt> <marcos> <p1> <p2> ... <pn>
 *   ./paginas <fifo|opt> <marcos> -f <archivo>
 *   Opción -q (antes del algoritmo): solo el resumen.
 *
 * Convenciones del diagrama de marcos:
 *   - Los marcos se numeran de izquierda a derecha, desde 0.
 *   - Un fallo con marco libre ocupa el marco libre de menor índice.
 *   - Un fallo sin marco libre carga la página nueva en el marco que
 *     ocupaba la víctima.
 *   - Si dos páginas empatan como víctima (solo ocurre en OPT cuando ninguna
 *     se vuelve a pedir), se elige la del marco de menor índice.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MARCOS 16
#define MAX_REFS 64
#define MAX_PAGINA 999
#define LIBRE (-1)

typedef enum { FIFO, OPT } Algoritmo;

static const char *const NOMBRES[] = { "FIFO", "OPT" };

typedef struct {
    int fallos;
    int aciertos;
} Resultado;

static void uso(const char *prog)
{
    fprintf(stderr,
        "Uso:\n"
        "  %s <fifo|opt> <marcos> <p1> <p2> ... <pn>\n"
        "  %s <fifo|opt> <marcos> -f <archivo>\n"
        "  %s -q <fifo|opt> <marcos> <p1> ...   (solo resumen)\n"
        "\n"
        "  marcos : entero de 1 a %d\n"
        "  pi     : número de página, entero de 0 a %d\n"
        "  cadena : de 1 a %d referencias\n"
        "  archivo: enteros separados por espacios, comas o saltos de línea;\n"
        "           lo que sigue a '#' en una línea es un comentario\n"
        "\n"
        "Ejemplo: %s fifo 3 7 0 1 2 0 3 0 4\n",
        prog, prog, prog, MAX_MARCOS, MAX_PAGINA, MAX_REFS, prog);
}

/* Convierte un texto a entero en [0, MAX_PAGINA]; devuelve 0 si es válido. */
static int leer_pagina(const char *txt, int *out)
{
    char *fin;
    errno = 0;
    long v = strtol(txt, &fin, 10);
    if (errno != 0 || fin == txt || *fin != '\0' || v < 0 || v > MAX_PAGINA)
        return -1;
    *out = (int)v;
    return 0;
}

/* Lee la cadena de referencias desde un archivo de texto. */
static int leer_archivo(const char *ruta, int *refs, int *n)
{
    FILE *f = fopen(ruta, "r");
    if (f == NULL) {
        fprintf(stderr, "Error: no se pudo abrir '%s': %s\n", ruta, strerror(errno));
        return -1;
    }
    char linea[512];
    *n = 0;
    while (fgets(linea, sizeof linea, f) != NULL) {
        char *c = strchr(linea, '#');
        if (c != NULL)
            *c = '\0';
        for (char *tok = strtok(linea, " \t\r\n,;"); tok != NULL;
             tok = strtok(NULL, " \t\r\n,;")) {
            if (*n >= MAX_REFS) {
                fprintf(stderr, "Error: la cadena supera %d referencias.\n", MAX_REFS);
                fclose(f);
                return -1;
            }
            if (leer_pagina(tok, &refs[*n]) != 0) {
                fprintf(stderr, "Error: '%s' no es una página válida (0 a %d).\n",
                        tok, MAX_PAGINA);
                fclose(f);
                return -1;
            }
            (*n)++;
        }
    }
    fclose(f);
    return 0;
}

static int digitos(int v)
{
    int d = 1;
    while (v >= 10) {
        v /= 10;
        d++;
    }
    return d;
}

/* Distancia hasta la próxima referencia de 'pag' después de la posición 'desde';
 * si no vuelve a aparecer, devuelve n + 1 (equivale a "infinito"). */
static int proxima_ref(const int *refs, int n, int desde, int pag)
{
    for (int i = desde + 1; i < n; i++)
        if (refs[i] == pag)
            return i - desde;
    return n + 1;
}

/* Elige la página víctima según el algoritmo y devuelve el marco que ocupa.
   Todos los marcos están ocupados. */
static int elegir_victima(Algoritmo alg, int marcos, const int *marco,
                          const int *t_carga, const int *refs, int n, int paso)
{
    int v = 0;
    if (alg == FIFO) {
        for (int k = 1; k < marcos; k++)
            if (t_carga[k] < t_carga[v])
                v = k;
    } else {
        int mejor = proxima_ref(refs, n, paso, marco[0]);
        for (int k = 1; k < marcos; k++) {
            int d = proxima_ref(refs, n, paso, marco[k]);
            if (d > mejor) {
                mejor = d;
                v = k;
            }
        }
    }
    return v;
}

static void imprimir_marcos(const int *marco, int marcos, int ancho)
{
    putchar('[');
    for (int k = 0; k < marcos; k++) {
        if (k > 0)
            putchar(' ');
        if (marco[k] == LIBRE)
            printf("%*s", ancho, "-");
        else
            printf("%*d", ancho, marco[k]);
    }
    putchar(']');
}

/* Simula un algoritmo sobre la cadena. Si 'detalle' es distinto de cero,
 * imprime el diagrama de marcos paso a paso. */
static Resultado simular(Algoritmo alg, int marcos, const int *refs, int n,
                         int detalle)
{
    int marco[MAX_MARCOS];
    int t_carga[MAX_MARCOS];  /* instante en que se cargó la página del marco */
    Resultado r = { 0, 0 };

    for (int k = 0; k < marcos; k++) {
        marco[k] = LIBRE;
        t_carga[k] = 0;
    }

    int maxp = 0;
    for (int i = 0; i < n; i++)
        if (refs[i] > maxp)
            maxp = refs[i];
    int ancho = digitos(maxp);
    int ancho_marcos = marcos * (ancho + 1) + 1;  /* ancho de "[a b c]" */
    int ancho_col = ancho_marcos < 6 ? 6 : ancho_marcos;  /* al menos "Marcos" */

    if (detalle) {
        printf("Algoritmo %s con %d marcos, %d referencias\n", NOMBRES[alg], marcos, n);
        printf("%4s  %4s  %-*s  %-9s  %s\n", "Paso", "Ref", ancho_col,
               "Marcos", "Resultado", "Víctima");
    }

    for (int i = 0; i < n; i++) {
        int pag = refs[i];
        int paso = i + 1;
        int en_marco = -1;
        for (int k = 0; k < marcos; k++)
            if (marco[k] == pag)
                en_marco = k;

        const char *res;
        char victima[64] = "-";

        if (en_marco >= 0) {
            r.aciertos++;
            res = "acierto";
        } else {
            r.fallos++;
            int destino = -1;
            for (int k = 0; k < marcos && destino < 0; k++)
                if (marco[k] == LIBRE)
                    destino = k;
            if (destino >= 0) {
                snprintf(victima, sizeof victima, "ninguna (marco %d libre)", destino);
            } else {
                destino = elegir_victima(alg, marcos, marco, t_carga, refs, n, i);
                snprintf(victima, sizeof victima, "página %d (marco %d)",
                         marco[destino], destino);
            }
            marco[destino] = pag;
            t_carga[destino] = paso;
            res = "fallo";
        }

        if (detalle) {
            printf("%4d  %4d  ", paso, pag);
            imprimir_marcos(marco, marcos, ancho);
            printf("%*s  %-9s  %s\n", ancho_col - ancho_marcos, "",
                   res, victima);
        }
    }
    return r;
}

static void imprimir_resumen(const char *nombre, int n, Resultado r)
{
    printf("Total de fallos de página: %d\n", r.fallos);
    printf("Total de aciertos: %d de %d referencias\n", r.aciertos, n);
    printf("Tasa de aciertos (%s): %.1f %%\n", nombre, 100.0 * r.aciertos / n);
}

int main(int argc, char *argv[])
{
    const char *prog = argv[0];
    int detalle = 1;
    int a = 1;

    if (a < argc && strcmp(argv[a], "-q") == 0) {
        detalle = 0;
        a++;
    }
    if (argc - a < 3) {
        uso(prog);
        return 1;
    }

    const char *modo = argv[a++];
    Algoritmo alg;
    if (strcmp(modo, "fifo") == 0)
        alg = FIFO;
    else if (strcmp(modo, "opt") == 0)
        alg = OPT;
    else {
        fprintf(stderr, "Error: algoritmo '%s' desconocido.\n\n", modo);
        uso(prog);
        return 1;
    }

    char *fin;
    errno = 0;
    long m = strtol(argv[a], &fin, 10);
    if (errno != 0 || fin == argv[a] || *fin != '\0' || m < 1 || m > MAX_MARCOS) {
        fprintf(stderr, "Error: el número de marcos debe ser un entero de 1 a %d.\n\n",
                MAX_MARCOS);
        uso(prog);
        return 1;
    }
    int marcos = (int)m;
    a++;

    int refs[MAX_REFS];
    int n = 0;
    if (strcmp(argv[a], "-f") == 0) {
        if (argc - a != 2) {
            fprintf(stderr, "Error: -f requiere exactamente un nombre de archivo.\n\n");
            uso(prog);
            return 1;
        }
        if (leer_archivo(argv[a + 1], refs, &n) != 0)
            return 1;
    } else {
        for (; a < argc; a++) {
            if (n >= MAX_REFS) {
                fprintf(stderr, "Error: la cadena supera %d referencias.\n\n", MAX_REFS);
                uso(prog);
                return 1;
            }
            if (leer_pagina(argv[a], &refs[n]) != 0) {
                fprintf(stderr, "Error: '%s' no es una página válida (0 a %d).\n\n",
                        argv[a], MAX_PAGINA);
                uso(prog);
                return 1;
            }
            n++;
        }
    }
    if (n == 0) {
        fprintf(stderr, "Error: la cadena de referencias está vacía.\n\n");
        uso(prog);
        return 1;
    }

    Resultado r = simular(alg, marcos, refs, n, detalle);
    if (detalle)
        putchar('\n');
    imprimir_resumen(NOMBRES[alg], n, r);
    return 0;
}
