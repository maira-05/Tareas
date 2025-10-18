#include <iostream>
#include <vector>
using namespace std;

class Usuario {
    private:
        int opcion;
    public:
        Usuario(int op) {
            opcion = op;
        }
        int getOpcion() {
            return opcion;
        }
        int setOpcion(int op) {
            if (1 <= opcion<= 2){
                return opcion;
            }
            else {
                cout << "Opción inválida. Intente de nuevo." << endl;
            }
        }
        void mostrarUsiario(){
            if (opcion == 1){
                cout << "Estudiante" << endl;
            }
            else if(opcion == 2){
                cout <<"Profesor" << endl;
            }
            else {
                cout << "Opción inválida" << endl;
            }
        }
};

class Libro {
private:
    string titulo;
    string autor;
    int ISBN;
    bool disponible;

public:
    Libro(string t, string a, int i) {
        titulo = t;
        autor = a;
        ISBN = i;
        disponible = true;
    }

    string getTitulo() {
        return titulo;
    }
    string getAutor() {
        return autor;
    }
    int getIsbn() const {
        return ISBN;
    }

    void mostrarInfo() {
        cout << "Título: " << titulo 
             << ", Autor: " << autor 
             << ", ISBN: " << ISBN << endl;
        cout << "Estado: " << (disponible ? "Disponible" : "No disponible") << endl;
    }
    // Función que verifica si el ISBN ya existe
    bool existeISBN(const vector<Libro>& libros, int isbn) {
        for (const auto& libro : libros) {
            if (libro.getIsbn() == isbn) {
                return true;  // Ya existe
            }
        }
        return false;  // No existe
    }
};


class Biblioteca {
    private:
        int seleccion2;
    public:
        Biblioteca(int sel2){
            seleccion2 = sel2;
        }
        int getSeleccion2(){
            return seleccion2;
        }
        int setSeleccion2(int sel2){
            if (1 <= seleccion2 <= 4){
                return seleccion2;
            }
            else {
                cout << "Opción inválida. Intente de nuevo." << endl;
            }
        }
        void mostrarBiblioteca(){
            if (seleccion2 == 1){
                cout << "Agregar Libro" << endl;
            }
            else if(seleccion2 == 2){
                cout <<"Eliminar Libro" << endl;
            }
            else if(seleccion2 == 3){
                cout <<"Buscar Libro" << endl;
            }
            else if(seleccion2 == 4){
                cout <<"Mostrar Libros" << endl;
            }
            else {
                cout << "Opción inválida" << endl;
            }
        }

};

int main() {
    int seleccion;
    int seleccion2;
    cout << "1. Estudiante" <<endl;
    cout << "2. Profesor" <<endl;
    cin >> seleccion;
    
    cin.ignore(); // limpiar el buffer
    Usuario persona(seleccion);
    persona.mostrarUsiario();

    if (seleccion == 1){
        cout << "Bienvenido Estudiante" << endl;
    }
    else if (seleccion == 2){
        cout << "Bienvenido Profesor" << endl;
    }
    else {
        cout << "Opción inválida" << endl;
    }

 
    /*  
    vector<Libro> biblioteca;
    string titulo, autor;
    int isbn;

    while (true) {
        cout << "\nIngrese título (o 'fin' para terminar): ";
        getline(cin, titulo);
        if (titulo == "fin") break;

        cout << "Ingrese autor: ";
        getline(cin, autor);

        cout << "Ingrese ISBN: ";
        cin >> isbn;
        cin.ignore(); // limpiar el buffer

        if (existeISBN(biblioteca, isbn)) {
            cout << "Este libro ya está disponible en la biblioteca.\n";
        } else {
            biblioteca.push_back(Libro(titulo, autor, isbn));
            cout << "Libro agregado correctamente.\n";
        }
    }

    cout << "\nLista de libros en la biblioteca:\n";
    for (auto& libro : biblioteca) {
        libro.mostrarInfo();
        cout << "----------------------------\n";
    }
    */

    return 0;
}
