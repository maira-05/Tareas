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
        cout << "Marca: "<<marca<<", Modelo: "<<modelo<< ",Placa: "<<placa<<", Disponible: "<< (disponible ? "Si":"No")<<endl;
    }
    

};
class Auto: public Vehiculo {
private:
    int pasajeros;
public:
    auto(string m, string mo, string p, int pa)
        : Vehiculo(m, mo, p){
        pasajeros = pa;
    }

    int getpasajeros;{
        return pasajeros;
    }

    void mostrarcap() const{
        cout << "Auto";
        Vehiculo::mostrarcap();
        cout << "capacidad de pasajeros" << pasajeros << endl;
    }
};


class Bicicleta {

};
class SistemaAlquiler {

};