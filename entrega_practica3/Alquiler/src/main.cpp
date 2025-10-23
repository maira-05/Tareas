#include <iostream>
#include "../include/SistemaAlquiler.h"
#include "../include/Vehiculo.h"

using namespace std;

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
