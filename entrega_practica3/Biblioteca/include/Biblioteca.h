#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include "Libro.h"
#include "Usuario.h"
using namespace std;

class Biblioteca {
private:
    vector<Libro> libros;

public:
    Biblioteca();
    void agregarLibro(const Libro& libro, bool mostrarMensaje = true);
    void mostrarLibros(const Usuario& usuario);
    void buscarLibro(const Usuario& usuario);
    void llevarLibro(Usuario& usuario);
    void devolverLibro(Usuario& usuario);
};

#endif
