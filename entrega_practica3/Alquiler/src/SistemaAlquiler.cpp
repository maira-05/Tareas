#include "../include/SistemaAlquiler.h"


SistemaAlquiler :: SistemaAlquiler() {
        vehiculos.push_back(new Auto("Toyota", "Corolla", "ABC123", 5));
        vehiculos.push_back(new Auto("Chevrolet", "Spark", "XYZ789", 4));
        vehiculos.push_back(new Auto("Nissan", "Versa", "JKL456", 5));

        vehiculos.push_back(new Bicicleta("Trek", "FX 3", "BIC001"));
        vehiculos.push_back(new Bicicleta("Giant", "Escape 2", "BIC002"));
        vehiculos.push_back(new Bicicleta("Specialized", "Sirrus", "BIC003"));
    }

    SistemaAlquiler::~SistemaAlquiler() {
        for (auto v : vehiculos)
            delete v;
    }

    void SistemaAlquiler::registrarVehiculo() {
        int tipo;
        cout << "\n--- Registrar Vehículo ---\n";
        cout << "1. Auto\n2. Bicicleta\nSeleccione tipo: ";
        cin >> tipo;

        string marca, modelo, placa;
        cout << "Marca: ";
        cin >> marca;
        cout << "Modelo: ";
        cin >> modelo;
        cout << "Placa: ";
        cin >> placa;

        if (tipo == 1) {
            int pasajeros;
            cout << "Capacidad de pasajeros: ";
            cin >> pasajeros;
            vehiculos.push_back(new Auto(marca, modelo, placa, pasajeros));
        } else if (tipo == 2) {
            vehiculos.push_back(new Bicicleta(marca, modelo, placa));
        } else {
            cout << "Tipo inválido.\n";
        }
    }

    void SistemaAlquiler::mostrarVehiculosDisponibles() const {
        cout << "\n--- Vehículos Disponibles ---\n";
        bool hayDisponibles = false;
        for (auto v : vehiculos) {
            if (v->estaDisponible()) {
                v->mostrarInformacion();
                hayDisponibles = true;
            }
        }
        if (!hayDisponibles)
            cout << "No hay vehículos disponibles.\n";
    }

    void SistemaAlquiler::mostrarTodosVehiculos() const {
        cout << "\n--- Todos los Vehículos ---\n";
        for (auto v : vehiculos) {
            v->mostrarInformacion();
        }
    }

    void SistemaAlquiler::alquilarVehiculo() {
        string placa;
        cout << "\n--- Alquilar Vehículo ---\n";
        cout << "Ingrese la placa del vehículo: ";
        cin >> placa;

        for (auto v : vehiculos) {
            if (v->getplaca() == placa) {
                if (v->estaDisponible()) {
                    v->setdisponible(false);
                    cout << "Vehículo con placa " << placa << " alquilado exitosamente.\n";
                } else {
                    cout << "El vehículo ya está alquilado.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }

    void SistemaAlquiler::devolverVehiculo() {
        string placa;
        cout << "\n--- Devolver Vehículo ---\n";
        cout << "Ingrese la placa del vehículo: ";
        cin >> placa;

        for (auto v : vehiculos) {
            if (v->getplaca() == placa) {
                if (!v->estaDisponible()) {
                    v->setdisponible(true);
                    cout << "Vehículo con placa " << placa << " devuelto exitosamente.\n";
                } else {
                    cout << "El vehículo ya estaba disponible.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }