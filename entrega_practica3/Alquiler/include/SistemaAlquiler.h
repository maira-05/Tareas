#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H
#include <vector>
#include <string>
#include <iostream>
#include "Vehiculo.h"
using namespace std;

class SistemaAlquiler {
private:
    vector<Vehiculo*> vehiculos;

public:
     SistemaAlquiler() ;

    ~SistemaAlquiler() ;
    void registrarVehiculo() ;

    void mostrarVehiculosDisponibles() const ;

    void mostrarTodosVehiculos() const ;

    void alquilarVehiculo() ;

    void devolverVehiculo() ;
};
#endif