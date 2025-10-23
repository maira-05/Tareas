#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>
using namespace std;
class Vehiculo {
private:
    string marca;
    string modelo;
    string placa;
    bool disponible;

public:
    Vehiculo(string m, string mo, string p);
    virtual ~Vehiculo(); 
    string getmarca() const ;
    string getmodelo() const ;
    string getplaca() const ;
    bool estaDisponible() const ;
    void setdisponible(bool d) ;

    virtual void mostrarInformacion() const;
};

class Auto : public Vehiculo {
private:
    int pasajeros;
public:
    Auto(string m, string mo, string p, int pa);

    void mostrarInformacion() const override;
};

class Bicicleta : public Vehiculo {
public:
    Bicicleta(string m, string mo, string p);

    void mostrarInformacion() const override;
};


#endif