#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ====================== CLASE USUARIO ======================
class Usuario {
protected:
    string nombre;
public:
    Usuario(string n) {
        nombre = n;
    }
    virtual ~Usuario() {} 
    string getNombre() const { return nombre; }
    virtual int diasPrestamo() const = 0; 
    virtual string tipoUsuario() const = 0;
};

// ====================== CLASE ESTUDIANTE ======================
class Estudiante : public Usuario {
public:
    Estudiante(string n) : Usuario(n) {}
    int diasPrestamo() const override { return 3; }
    string tipoUsuario() const override { return "Estudiante"; }
};

// ====================== CLASE PROFESOR ======================
class Profesor : public Usuario {
public:
    Profesor(string n) : Usuario(n) {}
    int diasPrestamo() const override { return 7; }
    string tipoUsuario() const override { return "Profesor"; }
};

// ====================== CLASE LIBRO ======================
class Libro {
private:
    string titulo;
    string autor;
    int ISBN;
    bool disponible;
    string prestadoA;

public:
    Libro(string t, string a, int i) {
            titulo = t;
            autor = a;
            ISBN = i;
            disponible = true;
            prestadoA = "";
        }

    string getTitulo() const { 
        return titulo; 
    }
    string getAutor() const { 
        return autor; 
    }
    int getIsbn() const { 
        return ISBN; 
    }
    bool estaDisponible() const { 
        return disponible; 
    }
    string getPrestadoA() const { 
        return prestadoA; 
    }

    void prestar(const Usuario& usuario) {
        disponible = false;
        prestadoA = usuario.getNombre();
    }

    void devolver() {
        disponible = true;
        prestadoA = "";
    }

    void mostrarInfo(bool verPrestadoA = false) const {
        cout << "Título: " << titulo << " | Autor: " << autor
             << " | ISBN: " << ISBN
             << " | Estado: " << (disponible ? "Disponible" : "No disponible");
        if (verPrestadoA && !disponible)
            cout << " | Prestado a: " << prestadoA;
        cout << endl;
    }
};

// ====================== CLASE BIBLIOTECA ======================
class Biblioteca {
private:
    vector<Libro> libros;

public:
    Biblioteca() {
        // Agregamos algunos libros por defecto
        agregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", 1001), false);
        agregarLibro(Libro("El Principito", "Antoine de Saint-Exupéry", 1002), false);
        agregarLibro(Libro("1984", "George Orwell", 1003), false);
        agregarLibro(Libro("Don Quijote", "Miguel de Cervantes", 1004), false);
    }

    void agregarLibro(const Libro& libro, bool mostrarMensaje = true) {
        for (const auto& l : libros)
            if (l.getIsbn() == libro.getIsbn()) {
                if (mostrarMensaje)
                    cout << "Ya existe un libro con ese ISBN.\n";
                return;
            }
        libros.push_back(libro);
        if (mostrarMensaje)
            cout << "Libro agregado correctamente.\n";
    }

    void mostrarLibros(const Usuario& usuario) {
        cout << "\n===== LISTA DE LIBROS =====\n";
        for (const auto& l : libros)
            l.mostrarInfo(usuario.tipoUsuario() == "Profesor");
    }

    void buscarLibro(const Usuario& usuario) {
        cout << "\nBuscar por:\n1. Título\n2. Autor\n> ";
        int opcion; cin >> opcion;
        cin.ignore();

        string texto;
        cout << "Ingrese el texto de búsqueda: ";
        getline(cin, texto);

        bool encontrado = false;
        for (const auto& l : libros) {
            if ((opcion == 1 && l.getTitulo() == texto) ||
                (opcion == 2 && l.getAutor() == texto)) {
                l.mostrarInfo(usuario.tipoUsuario() == "Profesor");
                encontrado = true;
            }
        }
        if (!encontrado)
            cout << "No se encontraron libros con ese criterio.\n";
    }

    void llevarLibro(Usuario& usuario) {
        string titulo;
        cin.ignore();
        cout << "Ingrese el título del libro que desea llevar: ";
        getline(cin, titulo);

        for (auto& l : libros) {
            if (l.getTitulo() == titulo) {
                if (!l.estaDisponible()) {
                    cout << "El libro no está disponible actualmente.\n";
                    return;
                }
                l.prestar(usuario);
                cout << "Has llevado el libro \"" << l.getTitulo()
                     << "\". Tienes " << usuario.diasPrestamo() << " días para devolverlo.\n";
                return;
            }
        }
        cout << "No se encontró el libro.\n";
    }

    void devolverLibro(Usuario& usuario) {
        string titulo;
        cin.ignore();
        cout << "Ingrese el título del libro que desea devolver: ";
        getline(cin, titulo);

        for (auto& l : libros) {
            if (l.getTitulo() == titulo && !l.estaDisponible() && l.getPrestadoA() == usuario.getNombre()) {
                l.devolver();
                cout << "Libro devuelto correctamente.\n";
                cout << "¿Fue entregado a tiempo? (1=Sí, 2=No): ";
                int op; cin >> op;
                if (op == 2)
                    cout << "El libro fue entregado con retraso tienes una multa de $2000.\n";
                else
                    cout << "El libro fue entregado a tiempo.\n";
                return;
            }
        }
        cout << "No se encontró un libro prestado con ese título o no pertenece a este usuario.\n";
    }
};

// ====================== MAIN ======================
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
