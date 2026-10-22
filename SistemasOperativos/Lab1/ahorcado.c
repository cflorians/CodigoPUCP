#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ERRORES 6

static const char *dibujos[] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "=========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "=========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "=========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "=========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "=========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "=========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "========="
};

static void mostrar_estado(const char *palabra, const char *oculta,
                           int errores) {
    printf("\n%s\n\nPalabra: ", dibujos[errores]);
    for (size_t i = 0; palabra[i] != '\0'; ++i) {
        printf("%c ", oculta[i]);
    }
    printf("\nErrores: %d/%d\n", errores, MAX_ERRORES);
}

int main(void) {
    const char *palabras[] = {
        "sistema", "terminal", "proceso", "memoria", "archivo"
    };
    const size_t cantidad = sizeof(palabras) / sizeof(palabras[0]);
    char oculta[32];
    int usadas[26] = {0};
    int errores = 0;
    size_t descubiertas = 0;

    srand((unsigned)time(NULL));
    const char *palabra = palabras[rand() % cantidad];
    size_t longitud = strlen(palabra);

    for (size_t i = 0; i < longitud; ++i) {
        oculta[i] = '_';
    }
    oculta[longitud] = '\0';

    printf("=== Ahorcado de Sistemas Operativos ===\n");

    while (errores < MAX_ERRORES && descubiertas < longitud) {
        char entrada[32];
        mostrar_estado(palabra, oculta, errores);
        printf("\nIngresa una letra: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("\nEntrada finalizada.\n");
            return EXIT_FAILURE;
        }

        if (!isalpha((unsigned char)entrada[0])) {
            printf("Ingresa una letra del alfabeto.\n");
            continue;
        }

        char letra = (char)tolower((unsigned char)entrada[0]);
        if (letra < 'a' || letra > 'z') {
            printf("Usa una letra sin tilde.\n");
            continue;
        }
        int indice = letra - 'a';
        if (usadas[indice]) {
            printf("Ya probaste la letra '%c'.\n", letra);
            continue;
        }
        usadas[indice] = 1;

        int encontrada = 0;
        for (size_t i = 0; i < longitud; ++i) {
            if (palabra[i] == letra) {
                oculta[i] = letra;
                ++descubiertas;
                encontrada = 1;
            }
        }

        if (!encontrada) {
            ++errores;
            printf("La letra '%c' no aparece.\n", letra);
        }
    }

    mostrar_estado(palabra, oculta, errores);
    if (descubiertas == longitud) {
        printf("\n¡Ganaste! La palabra era \"%s\".\n", palabra);
        return EXIT_SUCCESS;
    }

    printf("\nPerdiste. La palabra era \"%s\".\n", palabra);
    return EXIT_SUCCESS;
}
