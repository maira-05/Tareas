#include "../include/Usuario.h"


// ===== Implementación de Usuario =====
Usuario::Usuario(string n) {
    nombre = n;
}

string Usuario::getNombre() const {
    return nombre;
}

// ===== Implementación de Estudiante =====
Estudiante::Estudiante(string n) : Usuario(n) {}

int Estudiante::diasPrestamo() const {
    return 3;
}

string Estudiante::tipoUsuario() const {
    return "Estudiante";
}

// ===== Implementación de Profesor =====
Profesor::Profesor(string n) : Usuario(n) {}

int Profesor::diasPrestamo() const {
    return 7;
}

string Profesor::tipoUsuario() const {
    return "Profesor";
}
