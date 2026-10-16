#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Bibliotecas/FuncionesAdicionales.h"
#include "Bibliotecas/Comentario.h"
#include "Bibliotecas/Palabra.h"
#include "Bibliotecas/Plato.h"
#include "Bibliotecas/Atencion.h"

int main(int argc, char* argv[]) {
    struct Palabra lexicon[100];
    int cantLexicon;

    struct Plato* platos = new struct Plato[200];
    int cantPlatos;

    struct Atencion atenciones[100];
    int cantAtenciones;

    leerLexicon(lexicon, cantLexicon);
    leerPlatos(platos, cantPlatos);
    leerAtenciones(atenciones, cantAtenciones, platos, cantPlatos);
    leerComentarios(atenciones, cantAtenciones, lexicon, cantLexicon);
    emitirReporte(atenciones, cantAtenciones);

    return 0;
}