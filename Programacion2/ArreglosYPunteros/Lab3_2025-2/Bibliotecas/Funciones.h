
#ifndef LAB3_2025_2_FUNCIONES_H
#define LAB3_2025_2_FUNCIONES_H

void cargarStreamers(void*& streamers);
void* leerRegistro(ifstream& arch);
char* obtenerCadenaExacta(ifstream& arch, char limit);
void incrementarCapacidad(void**& streamers,int& nd,int& capacidad);
void pruebaStreamers(void* strmr);
void imprimirStreamer(void* strmr);

void cargarComentarios(void*& coment);
void* leerComentario(ifstream& arch);
void pruebaComentarios(void* coment);
void imprimirComentarios(void* coment);

void actualizaComentarios(void* streamers,void* comentarios);
void recorrerComentarios(void* streamer, void* coment);
bool comparar(void* strmr,void* coment);
void asignarComentario(void* streamer,void* comentarios);
int obtenerNumeroDeComentarios(void* strmr);
void aumentoCapacidadComentarios(void*& streamer,int& nd);
void colocarComentario(void* strm,void* coment, int nd);

void imprimeStreamers(void* strm);
void separador(ofstream& arch, char separador);
void mostrarStreamer(void* strm,ofstream& arch);
void imprimirReporteStreamer(void* strm, ofstream& arch);
void mostrarComentariosStreamer(void* strm,ofstream& arch);
void imprimirComentario(void* comentariosStreamer,ofstream& arch);

#endif //LAB3_2025_2_FUNCIONES_H
