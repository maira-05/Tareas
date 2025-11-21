/**
 * @file main.cpp
 * @brief Simulación del sistema de gestión académica usando la clase Estudiante.
 * 
 * Este programa crea varios estudiantes, simula el registro de notas,
 * muestra un resumen general de cada uno y calcula el promedio general del grupo.
 */

#include <iostream>
#include <vector>
#include "Estudiante.h"
using namespace std;

/**
 * @brief Función principal del programa.
 * @return int Código de salida del programa.
 */
int main() {
    // Crear un vector de estudiantes
    vector<Estudiante> estudiantes;

    // Registrar varios estudiantes
    estudiantes.push_back(Estudiante("Juan Perez"));
    estudiantes.push_back(Estudiante("Maria Gomez"));
    estudiantes.push_back(Estudiante("Luis Rodriguez"));

    // Simular registro de notas
    estudiantes[0].agregarNota(4.5);
    estudiantes[0].agregarNota(3.8);

    estudiantes[1].agregarNota(2.9);
    estudiantes[1].agregarNota(3.2);

    estudiantes[2].agregarNota(4.0);
    estudiantes[2].agregarNota(4.7);

    // Mostrar resumen general
    cout << "\n=== RESUMEN DE ESTUDIANTES ===\n";
    for (const Estudiante &e : estudiantes) {
        e.mostrarResumen();
    }

    // Calcular promedio general del grupo
    float suma_promedios = 0.0;
    for (const Estudiante &e : estudiantes) {
        suma_promedios += e.calcularPromedio();
    }
    float promedio_general = suma_promedios / estudiantes.size();

    cout << "Promedio general de todos los estudiantes: " << promedio_general << endl;

    return 0;
}
