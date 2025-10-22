// Ejercicio 2: Sistema de Alquiler de Vehículos
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= CLASE VEHICULO =================
class Vehiculo {
private:
    string marca;
    string modelo;
    string placa;
    bool disponible;

public:
    Vehiculo(string m, string mo, string p)
        : marca(m), modelo(mo), placa(p), disponible(true) {}

    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    string getPlaca() const { return placa; }
    bool estaDisponible() const { return disponible; }

    void setDisponible(bool d) { disponible = d; }

<<<<<<< HEAD
    virtual void mostrarInformacion() const {
        cout << "Marca: " << marca
             << ", Modelo: " << modelo
             << ", Placa: " << placa
             << ", Disponible: " << (disponible ? "Sí" : "No") << endl;
    }
=======
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
>>>>>>> 31847bf311c489d0f706dc5e0084aef13e4018bc

    virtual ~Vehiculo() {}
};

<<<<<<< HEAD
// ================= CLASE AUTO =================
class Auto : public Vehiculo {
=======
class Auto: public Vehiculo {
>>>>>>> 31847bf311c489d0f706dc5e0084aef13e4018bc
private:
    int pasajeros;
public:
    Auto(string m, string mo, string p, int pa)
        : Vehiculo(m, mo, p), pasajeros(pa) {}

    void mostrarInformacion() const override {
        cout << "[Auto] ";
        Vehiculo::mostrarInformacion();
        cout << "   Capacidad de pasajeros: " << pasajeros << endl;
    }
};

// ================= CLASE BICICLETA =================
class Bicicleta : public Vehiculo {
public:
    Bicicleta(string m, string mo, string p)
<<<<<<< HEAD
        : Vehiculo(m, mo, p) {}

    void mostrarInformacion() const override {
        cout << "[Bicicleta] ";
        Vehiculo::mostrarInformacion();
    }
};

// ================= CLASE SISTEMA DE ALQUILER =================
class SistemaAlquiler {
private:
    vector<Vehiculo*> vehiculos;

public:
    SistemaAlquiler() {
        // Vehículos precargados
        vehiculos.push_back(new Auto("Toyota", "Corolla", "ABC123", 5));
        vehiculos.push_back(new Auto("Chevrolet", "Spark", "XYZ789", 4));
        vehiculos.push_back(new Auto("Nissan", "Versa", "JKL456", 5));

=======
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

>>>>>>> 31847bf311c489d0f706dc5e0084aef13e4018bc
        vehiculos.push_back(new Bicicleta("Trek", "FX 3", "BIC001"));
        vehiculos.push_back(new Bicicleta("Giant", "Escape 2", "BIC002"));
        vehiculos.push_back(new Bicicleta("Specialized", "Sirrus", "BIC003"));
    }

    ~SistemaAlquiler() {
        for (auto v : vehiculos)
            delete v;
    }
<<<<<<< HEAD

    void registrarVehiculo() {
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

    void mostrarVehiculosDisponibles() const {
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

    void mostrarTodosVehiculos() const {
        cout << "\n--- Todos los Vehículos ---\n";
        for (auto v : vehiculos) {
            v->mostrarInformacion();
        }
    }

    void alquilarVehiculo() {
        string placa;
        cout << "\n--- Alquilar Vehículo ---\n";
        cout << "Ingrese la placa del vehículo: ";
        cin >> placa;

        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (v->estaDisponible()) {
                    v->setDisponible(false);
                    cout << "Vehículo con placa " << placa << " alquilado exitosamente.\n";
                } else {
                    cout << "El vehículo ya está alquilado.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }

    void devolverVehiculo() {
        string placa;
        cout << "\n--- Devolver Vehículo ---\n";
        cout << "Ingrese la placa del vehículo: ";
        cin >> placa;

        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (!v->estaDisponible()) {
                    v->setDisponible(true);
                    cout << "Vehículo con placa " << placa << " devuelto exitosamente.\n";
                } else {
                    cout << "El vehículo ya estaba disponible.\n";
                }
                return;
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }
};

// ================= FUNCIÓN PRINCIPAL =================
int main() {
    SistemaAlquiler sistema;
    int opcion;

    do {
        cout << "\n===== Sistema de Alquiler de Vehículos =====\n";
        cout << "1. Registrar vehículo\n";
        cout << "2. Mostrar vehículos disponibles\n";
        cout << "3. Alquilar vehículo\n";
        cout << "4. Devolver vehículo\n";
        cout << "5. Mostrar todos los vehículos\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: sistema.registrarVehiculo(); break;
            case 2: sistema.mostrarVehiculosDisponibles(); break;
            case 3: sistema.alquilarVehiculo(); break;
            case 4: sistema.devolverVehiculo(); break;
            case 5: sistema.mostrarTodosVehiculos(); break;
            case 6: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 6);

    return 0;
}
=======
};

int main(){
    cout << "Sistema de Alquiler de Vehículos" << endl;
    
}
>>>>>>> 31847bf311c489d0f706dc5e0084aef13e4018bc
