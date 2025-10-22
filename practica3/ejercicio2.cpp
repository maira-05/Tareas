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

    
    virtual void mostrarInformacion() const {
        cout << "Marca: " << marca
             << " | Modelo: " << modelo
             << " | Placa: " << placa
             <<", Disponible: "
             << (disponible ? "Si":"No")<<endl;
    }
    virtual ~Vehiculo(){}

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
    Bicicleta(string m, string mo, string p)
        : Vehiculo(m, mo, p){}

    void mostrarInformacion() const {
        cout << "[Bicicleta] ";
        Vehiculo::mostrarInformacion();
    }

    
};

class SistemaAlquiler {
private:
    vector<Vehiculo*> vehiculos;
public:
    SistemaAlquiler(){
        vehiculos.push_back(new Auto("Toyota", "Corolla", "ABC123", 5));
        vehiculos.push_back(new Auto("Chevrolet", "Spark", "XYZ789", 4));
        vehiculos.push_back(new Auto("Nissan", "Versa", "JKL456", 5));

        vehiculos.push_back(new Bicicleta("Trek", "FX 3", "BIC001"));
        vehiculos.push_back(new Bicicleta("Giant", "Escape 2", "BIC002"));
        vehiculos.push_back(new Bicicleta("Specialized", "Sirrus", "BIC003"));
    }

};
int main(){
    cout << "Sistema de Alquiler de Vehículos" << endl;
    
}