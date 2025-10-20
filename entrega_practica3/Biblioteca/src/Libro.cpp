#include "../include/Libro.h"


Libro::Libro(string t, string a, int i) {
    titulo = t;
    autor = a;
    ISBN = i;
    disponible = true;
    prestadoA = "";
}

string Libro::getTitulo() const { return titulo; }
string Libro::getAutor() const { return autor; }
int Libro::getIsbn() const { return ISBN; }
bool Libro::estaDisponible() const { return disponible; }
string Libro::getPrestadoA() const { return prestadoA; }

void Libro::prestar(const Usuario& usuario) {
    disponible = false;
    prestadoA = usuario.getNombre();
}

void Libro::devolver() {
    disponible = true;
    prestadoA = "";
}

void Libro::mostrarInfo(bool verPrestadoA) const {
    cout << "Título: " << titulo << " | Autor: " << autor
         << " | ISBN: " << ISBN
         << " | Estado: " << (disponible ? "Disponible" : "No disponible");
    if (verPrestadoA && !disponible)
        cout << " | Prestado a: " << prestadoA;
    cout << endl;
}
