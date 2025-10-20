#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
#include "Usuario.h"
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int ISBN;
    bool disponible;
    string prestadoA;

public:
    Libro(string t, string a, int i);
    string getTitulo() const;
    string getAutor() const;
    int getIsbn() const;
    bool estaDisponible() const;
    string getPrestadoA() const;

    void prestar(const Usuario& usuario);
    void devolver();
    void mostrarInfo(bool verPrestadoA = false) const;
};

#endif
