#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Bibliotecas/Funciones.h"

int main(int argc, char** argv) {
    
    void *streamers, *comentarios;

    cargarStreamers(streamers);
    // pruebaStreamers(streamers);

    cargarComentarios(comentarios);
    // pruebaComentarios(comentarios);

    actualizaComentarios(streamers, comentarios);
    imprimeStreamers(streamers);
    
    return 0;
}
