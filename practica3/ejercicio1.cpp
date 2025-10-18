#include <iostream>
#include <vector>
using namespace std;

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
};

// Función que verifica si el ISBN ya existe
bool existeISBN(const vector<Libro>& libros, int isbn) {
    for (const auto& libro : libros) {
        if (libro.getIsbn() == isbn) {
            return true;  // Ya existe
        }
    }
    return false;  // No existe
}
class Biblioteca {
    private:
        int agregarLibro;
        int eliminarLibro;
        int buscarLibro;
        int mostrarLibros;
    public:

};

int main() {
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

    return 0;
}
