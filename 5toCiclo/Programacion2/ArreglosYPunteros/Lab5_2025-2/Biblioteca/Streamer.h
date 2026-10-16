//
// Created by carlo on 5/11/2026.
//

#ifndef LAB5_2025_2_STREAMER_H
#define LAB5_2025_2_STREAMER_H

class Streamer {
private:
    char* cuenta{};
    long long int tiempoTotal{};
    double promedioEspectadores{};
    int nSeguidores{};
    char* categoria{};
public:
    Streamer(); // Constructor
    Streamer(const char*, long long int, double, int, const char*); // Constructor con parametros
    ~Streamer(); // Destructor
    Streamer(const class Streamer&); // Constructor copia
    Streamer& operator=(const Streamer& otro);
    // Setters
    void setCuenta(const char*);
    void setTiempoTotal(long long int);
    void setPromedio(double);
    void setNSeguidores(int);
    void setCategoria(const char*);
    // Getters
    char* getCuenta();
    long long int getTiempoTotal();
    double getPromedio();
    int getNSeguidores();
    char* getCategoria();
    // Metodos pedidos
    void leer_streamer(ifstream&);
    void mostrar_streamer();
    void mostrar_streamer(ofstream &arch);
    void copiar(const class Streamer&); // igual que el constructor copia
};

#endif //LAB5_2025_2_STREAMER_H
