#include <iostream>
#include "../include/Biblioteca.h"

#include "../include/Usuario.h"
using namespace std;

int main() {
    Biblioteca biblioteca;

    while (true) {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Estudiante\n";
        cout << "2. Profesor\n";
        cout << "0. Salir del programa\n";
        cout << "Seleccione una opción: ";

        int opcion;
        cin >> opcion;

        if (opcion == 0) {
            cout << "Saliendo del programa...\n";
            break;
        }

        if (opcion != 1 && opcion != 2) {
            cout << "Opción inválida. Intente de nuevo.\n";
            continue;
        }

        string nombre;
        cin.ignore();
        cout << "Ingrese su nombre: ";
        getline(cin, nombre);

        Usuario* usuarioActual = nullptr;
        if (opcion == 1) {
            usuarioActual = new Estudiante(nombre);
            cout << "\nBienvenido, " << nombre << " (Estudiante)\n";
        } else {
            usuarioActual = new Profesor(nombre);
            cout << "\nBienvenido, " << nombre << " (Profesor)\n";
        }

        while (true) {
            cout << "\n----- MENU BIBLIOTECA -----\n";
            cout << "1. Mostrar libros disponibles\n";
            cout << "2. Devolver libro\n";
            cout << "3. Llevar libro\n";
            cout << "4. Buscar libro\n";
            cout << "5. Cerrar sesión y volver al menú principal\n";
            cout << "0. Salir del programa\n";
            cout << "Seleccione una opción: ";

            int subOpcion;
            cin >> subOpcion;

            if (subOpcion == 0) {
                cout << "Saliendo del programa...\n";
                delete usuarioActual;
                return 0;
            }

            if (subOpcion == 5) {
                cout << "\nCerrando sesión...\n";
                delete usuarioActual;
                break;
            }

            switch (subOpcion) {
                case 1: biblioteca.mostrarLibros(*usuarioActual); break;
                case 2: biblioteca.devolverLibro(*usuarioActual); break;
                case 3: biblioteca.llevarLibro(*usuarioActual); break;
                case 4: biblioteca.buscarLibro(*usuarioActual); break;
                default: cout << "Opción inválida.\n"; break;
            }
        }
    }

    return 0;
}
