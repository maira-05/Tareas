#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ==================== CLASE LIBRO ====================
class Libro {
private:
    string titulo;
    string autor;
    int ISBN;
    bool disponible;
    string prestadoA;
    int diasPrestamo;

public:
    Libro(string t, string a, int i)
        : titulo(t), autor(a), ISBN(i), disponible(true), prestadoA(""), diasPrestamo(0) {}

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getIsbn() const { return ISBN; }
    bool estaDisponible() const { return disponible; }
    string getPrestadoA() const { return prestadoA; }
    int getDiasPrestamo() const { return diasPrestamo; }

    void mostrarInfo(bool esProfesor = false) const {
        cout << "Título: " << titulo 
             << " | Autor: " << autor
             << " | ISBN: " << ISBN
             << " | Estado: " << (disponible ? "Disponible" : "No disponible");
        if (!disponible && esProfesor)
            cout << " | Prestado a: " << prestadoA;
        cout << endl;
    }

    void prestar(string usuario, int dias) {
        if (disponible) {
            disponible = false;
            prestadoA = usuario;
            diasPrestamo = dias;
            cout << "✅ Libro \"" << titulo << "\" prestado a " << usuario 
                 << " por " << dias << " días.\n";
        } else {
            cout << "❌ El libro \"" << titulo << "\" ya está prestado.\n";
        }
    }

    bool devolver(string usuario, int diasUsados) {
        if (!disponible && prestadoA == usuario) {
            disponible = true;
            cout << "📘 Libro \"" << titulo << "\" devuelto.\n";
            if (diasUsados > diasPrestamo)
                cout << "⚠️ Devolución atrasada (" << diasUsados - diasPrestamo << " días tarde).\n";
            else
                cout << "✅ Devolución a tiempo.\n";
            prestadoA = "";
            diasPrestamo = 0;
            return true;
        }
        cout << "❌ No puedes devolver este libro.\n";
        return false;
    }
};

// ==================== CLASE USUARIO ====================
class Usuario {
protected:
    string nombre;
    int limiteDias;

public:
    Usuario(string n, int dias) : nombre(n), limiteDias(dias) {}
    virtual ~Usuario() {}

    string getNombre() const { return nombre; }
    int getLimiteDias() const { return limiteDias; }

    virtual void mostrarTipo() const = 0;
};

class Estudiante : public Usuario {
public:
    Estudiante(string n) : Usuario(n, 3) {}
    void mostrarTipo() const override {
        cout << "👩‍🎓 Usuario: " << nombre << " (Estudiante, límite 3 días)" << endl;
    }
};

class Profesor : public Usuario {
public:
    Profesor(string n) : Usuario(n, 7) {}
    void mostrarTipo() const override {
        cout << "👨‍🏫 Usuario: " << nombre << " (Profesor, límite 7 días)" << endl;
    }
};

// ==================== CLASE BIBLIOTECA ====================
class Biblioteca {
private:
    vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro) {
        for (const auto& l : libros)
            if (l.getIsbn() == libro.getIsbn()) {
                cout << "❌ Ya existe un libro con ese ISBN.\n";
                return;
            }
        libros.push_back(libro);
        cout << "✅ Libro agregado correctamente.\n";
    }

    void mostrarLibros(bool esProfesor) const {
        if (libros.empty()) {
            cout << "📚 No hay libros en la biblioteca.\n";
            return;
        }
        cout << "\n===== LISTA DE LIBROS =====\n";
        for (const auto& l : libros)
            l.mostrarInfo(esProfesor);
    }

    void buscarLibro(bool esProfesor) const {
        int opcion;
        cout << "\nBuscar por:\n1. Título\n2. Autor\n> ";
        cin >> opcion;
        cin.ignore();
        string valor;
        bool encontrado = false;

        if (opcion == 1) {
            cout << "Ingrese título: ";
            getline(cin, valor);
            for (const auto& l : libros)
                if (l.getTitulo() == valor) {
                    l.mostrarInfo(esProfesor);
                    encontrado = true;
                }
        } else if (opcion == 2) {
            cout << "Ingrese autor: ";
            getline(cin, valor);
            for (const auto& l : libros)
                if (l.getAutor() == valor) {
                    l.mostrarInfo(esProfesor);
                    encontrado = true;
                }
        }
        if (!encontrado)
            cout << "❌ No se encontró ningún libro.\n";
    }

    Libro* obtenerLibro(string titulo, string autor) {
        for (auto& l : libros)
            if (l.getTitulo() == titulo && l.getAutor() == autor)
                return &l;
        return nullptr;
    }
};

// ==================== MAIN ====================
int main() {
    Biblioteca biblioteca;
    biblioteca.agregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", 1001));
    biblioteca.agregarLibro(Libro("El Principito", "Antoine de Saint-Exupéry", 1002));
    biblioteca.agregarLibro(Libro("1984", "George Orwell", 1003));

    int tipoUsuario;
    string nombre;
    cout << "=== SISTEMA DE BIBLIOTECA ===\n";
    cout << "1. Estudiante\n2. Profesor\n> ";
    cin >> tipoUsuario;
    cin.ignore();

    Usuario* usuario = nullptr;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);

    if (tipoUsuario == 1)
        usuario = new Estudiante(nombre);
    else if (tipoUsuario == 2)
        usuario = new Profesor(nombre);
    else {
        cout << "Opción inválida.\n";
        return 0;
    }

    usuario->mostrarTipo();

    int opcion;
    do {
        cout << "\n===== MENÚ SECUNDARIO =====\n";
        cout << "1. Mostrar libros disponibles\n";
        cout << "2. Devolver libro\n";
        cout << "3. Llevar libro\n";
        cout << "4. Buscar libros\n";
        cout << "0. Salir\n> ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            biblioteca.mostrarLibros(tipoUsuario == 2);
        } 
        else if (opcion == 2) {
            string titulo, autor;
            int dias;
            cout << "Ingrese título del libro a devolver: ";
            getline(cin, titulo);
            cout << "Ingrese autor: ";
            getline(cin, autor);
            cout << "Ingrese los días que pasaron desde el préstamo: ";
            cin >> dias;
            cin.ignore();
            Libro* l = biblioteca.obtenerLibro(titulo, autor);
            if (l) l->devolver(usuario->getNombre(), dias);
            else cout << "❌ Libro no encontrado.\n";
        } 
        else if (opcion == 3) {
            string titulo, autor;
            cout << "Ingrese título del libro: ";
            getline(cin, titulo);
            cout << "Ingrese autor: ";
            getline(cin, autor);
            Libro* l = biblioteca.obtenerLibro(titulo, autor);
            if (l) l->prestar(usuario->getNombre(), usuario->getLimiteDias());
            else cout << "❌ Libro no encontrado.\n";
        } 
        else if (opcion == 4) {
            biblioteca.buscarLibro(tipoUsuario == 2);
        }

    } while (opcion != 0);

    cout << "👋 Gracias por usar la biblioteca.\n";
    delete usuario;
    return 0;
}
