#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {

};
class HealthRecord {

};
class DatabaseManager {

};
class HealthAnalyzer {

};
class CSVExporter {

};
int main() {
    cout << "Proyecto de gestion de registros de salud." << endl;
    while (true) {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Registrarse\n";
        cout << "0. Salir del programa\n";
        cout << "Seleccione una opción: ";
         int opcion;
        cin >> opcion;

        if (opcion == 0) {
            cout << "Saliendo del programa...\n";
            break;
        }

        if (opcion != 1) {
            cout << "Opción inválida. Intente de nuevo.\n";
            continue;
        }
        
        string usuario;
        cin.ignore();
        cout << "Ingrese su usuario: ";
        getline(cin, usuario);
        cout << "Ingrese su ID: ";
        int id;
        cin >> id;
        cin.ignore();
        cout << "Ingrese su contraseña: ";
        string contrasena;
        getline(cin, contrasena);

        User* usuarioActual = new User();
    }
    return 0;
}