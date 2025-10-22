//Ejercicio 2: Sistema de Alquiler de Vehículos
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehiculo {
    private:
    string marca;
    string modelo;
    string placa;
    bool disponible;

    public:
    Vehiculo (string m, string mo, string p){
        marca = m;
        modelo = mo;
        placa = p;
        disponible=true;
    }

    string getmarca() const{
        return marca;
    }

    string getmodelo() const{
        return modelo;
    }

    string getplaca() const{
        return placa;
    }

    bool estaDisponible() const {
        return disponible;
    }

    void setdisponible(bool d){
        disponible = d;
    }

    virtual ~Vehiculo(){}
    virtual void mostrarInformacion() const {
        cout << "Marca: "<<marca
             <<", Modelo: "<<modelo
             << ",Placa: "<<placa
             <<", Disponible: "
             << (disponible ? "Si":"No")<<endl;
    }
    

};
class Auto: public Vehiculo {
private:
    int pasajeros;
public:
    Auto(string m, string mo, string p, int pa)
        : Vehiculo(m, mo, p){
        pasajeros = pa;
    }

    int getpasajeros() const{
        return pasajeros;
    }

    void mostrarInformacion() const {
        cout << "[Auto] ";
        Vehiculo::mostrarInformacion();
        cout << "   Capacidad de pasajeros: " << pasajeros << endl;
    }
};


class Bicicleta: public Vehiculo {
public:
    Bicicleta(string m, string mo, string p )
        : Vehiculo(m, mo, p)

};
class SistemaAlquiler {

};