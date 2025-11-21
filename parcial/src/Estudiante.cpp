/**
 * @file Estudiante.cpp
 * @brief Implementación de los métodos de la clase Estudiante.
 */

#include "Estudiante.h"

Estudiante::Estudiante(string nombre) {
    this->nombre = nombre;
    creditos_aprobados = 0;
}

void Estudiante::agregarNota(float nota) {
    notas.push_back(nota);
    if (nota >= 3.0) {
        creditos_aprobados += 3; ///< Cada materia aprobada suma 3 créditos.
    }
}

float Estudiante::calcularPromedio() const {
    if (notas.empty()) return 0.0;
    float suma = 0.0;
    for (float n : notas) {
        suma += n;
    }
    return suma / notas.size();
}

string Estudiante::getNombre() const {
    return nombre;
}

int Estudiante::getCreditos() const {
    return creditos_aprobados;
}

void Estudiante::mostrarResumen() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Promedio: " << calcularPromedio() << endl;
    cout << "Creditos aprobados: " << creditos_aprobados << endl;
    cout << "----------------------------" << endl;
}
