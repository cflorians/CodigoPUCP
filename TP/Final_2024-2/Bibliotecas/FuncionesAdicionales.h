//
// Created by carlo on 11/28/2025.
//

#ifndef FINAL_2024_2_FUNCIONESADICIONALES_H
#define FINAL_2024_2_FUNCIONESADICIONALES_H

void leerLexicon(struct Palabra *lexicon, int& cantLexicon);
char* insertarChar(char* cadena);
void leerPlatos(struct Plato *platos, int& cantPlatos);
int buscarPosPlato(char* codigo, struct Plato *platos, int cantPlatos);
void leerAtenciones(struct Atencion *atenciones, int& cantAtenciones, struct Plato *platos, int cantPlatos);
void leerComentarios(struct Atencion *atenciones, int cantAtenciones, struct Palabra *lexicon, int cantLexicon);
int buscarAtencion(int codigo, struct Atencion *atenciones, int cantAtenciones);
char* preProcesarComentario(char* comentario);
void procesarComentario(int pos, int cantComentarios, char* comentario, struct Atencion *atenciones, int cantAtenciones, struct Palabra *lexicon, int cantLexicon);
int buscarPalabra(char* palabra, struct Palabra *lexicon, int cantLexicon);
void emitirReporte(struct Atencion *atenciones, int cantAtenciones);
void separador(ofstream& arch, char separador);
void mostarHora(ofstream& arch, int hora);

#endif //FINAL_2024_2_FUNCIONESADICIONALES_H