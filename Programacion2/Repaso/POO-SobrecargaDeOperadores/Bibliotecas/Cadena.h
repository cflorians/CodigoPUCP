//
// Created by carlo on 5/10/2026.
//

#ifndef POO_SOBRECARGADEOPERADORES_CADENA_H
#define POO_SOBRECARGADEOPERADORES_CADENA_H

class Cadena {
private:
    char* cadena;
    int capacidad;
    int longitud;
public:
    // Inicializacion
    Cadena();
    Cadena(const char*);
    Cadena(const Cadena&);
    Cadena(int);
    void operator = (const Cadena&);
    // Asignación
    void assing(const char*);
    void assing(const Cadena&);
    void operator = (const char*);
    void append(const char*);
    void append(const Cadena&);
    void swap(Cadena&);
    // Concatenación
    Cadena operator+(const Cadena&) const; // este const va porque no se modifica la cadena original
    // Comparación
    int compare(const char*) const;
    int compare(const Cadena&) const;
    bool operator == (const Cadena&) const;
    bool operator > (const Cadena&) const;
    bool operator < (const Cadena&) const;
    bool operator >= (const Cadena&) const;
    bool operator <= (const Cadena&) const;
    // Longitud
    int length() const;
    // Impresión
    void print() const;
    // Destructor
    ~Cadena();
};

#endif //POO_SOBRECARGADEOPERADORES_CADENA_H
