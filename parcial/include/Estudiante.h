/**
 * @file Estudiante.h
 * @brief Declaración de la clase Estudiante para la gestión académica.
 * @version 1.0
 * @date 2025-11-01
 * 
 * La clase Estudiante permite registrar notas, calcular el promedio,
 * contar créditos aprobados y mostrar un resumen general de la información del estudiante.
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @class Estudiante
 * @brief Representa a un estudiante con su nombre, notas y créditos aprobados.
 */
class Estudiante {
private:
    string nombre;                 ///< Nombre del estudiante
    vector<float> notas;           ///< Vector con las notas registradas
    int creditos_aprobados;        ///< Total de créditos aprobados

public:
    /**
     * @brief Constructor de la clase Estudiante.
     * @param nombre Nombre del estudiante.
     */
    Estudiante(string nombre);

    /**
     * @brief Agrega una nota al estudiante.
     * @param nota Nota que se va a registrar.
     */
    void agregarNota(float nota);

    /**
     * @brief Calcula el promedio de notas del estudiante.
     * @return Promedio (float) de las notas registradas.
     */
    float calcularPromedio() const;

    /**
     * @brief Obtiene el nombre del estudiante.
     * @return Nombre (string) del estudiante.
     */
    string getNombre() const;

    /**
     * @brief Devuelve el número total de créditos aprobados.
     * @return Créditos aprobados (int).
     */
    int getCreditos() const;

    /**
     * @brief Muestra por consola un resumen del estudiante.
     */
    void mostrarResumen() const;
};

#endif
