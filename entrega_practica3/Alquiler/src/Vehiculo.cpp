#include "../include/Vehiculo.h"

Vehiculo::Vehiculo(string m, string mo, string p){
    marca = m;
    modelo = mo;
    placa = p;
    disponible = true;
}

Vehiculo::~Vehiculo(){}
string Vehiculo::getmarca() const { return marca; }
string Vehiculo::getmodelo() const { return modelo; }
string Vehiculo::getplaca() const { return placa; }
bool Vehiculo::estaDisponible() const { return disponible; }
void Vehiculo::setdisponible(bool d) { disponible = d; }
void Vehiculo::mostrarInformacion() const {
    cout << "Marca: " << marca
         << " | Modelo: " << modelo
         << " | Placa: " << placa
         << ", Disponible: " << (disponible ? "Si" : "No") << endl;
}

Auto::Auto(string m, string mo, string p, int pa)
    : Vehiculo(m, mo, p), pasajeros(pa) {}

void Auto::mostrarInformacion() const {
    cout << "[Auto] ";
    Vehiculo::mostrarInformacion();
    cout << "   Capacidad de pasajeros: " << pasajeros << endl;
}
Bicicleta::Bicicleta(string m, string mo, string p)
    : Vehiculo(m, mo, p) {}

void Bicicleta::mostrarInformacion() const {
    cout << "[Bicicleta] ";
    Vehiculo::mostrarInformacion();
}