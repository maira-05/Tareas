#include "../include/Biblioteca.h"


Biblioteca::Biblioteca() {
    agregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", 1001), false);
    agregarLibro(Libro("El Principito", "Antoine de Saint-Exupéry", 1002), false);
    agregarLibro(Libro("1984", "George Orwell", 1003), false);
    agregarLibro(Libro("Don Quijote", "Miguel de Cervantes", 1004), false);
}

void Biblioteca::agregarLibro(const Libro& libro, bool mostrarMensaje) {
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

void Biblioteca::mostrarLibros(const Usuario& usuario) {
    cout << "\n===== LISTA DE LIBROS =====\n";
    for (const auto& l : libros)
        l.mostrarInfo(usuario.tipoUsuario() == "Profesor");
}

void Biblioteca::buscarLibro(const Usuario& usuario) {
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

void Biblioteca::llevarLibro(Usuario& usuario) {
    cin.ignore();
    string titulo;
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

void Biblioteca::devolverLibro(Usuario& usuario) {
    cin.ignore();
    string titulo;
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
