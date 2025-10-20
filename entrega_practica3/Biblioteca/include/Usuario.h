#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

// ===== Clase base: Usuario =====
class Usuario {
protected:
    string nombre;
public:
    Usuario(string n);
    virtual ~Usuario() {}
    string getNombre() const;
    virtual int diasPrestamo() const = 0;
    virtual string tipoUsuario() const = 0;
};

// ===== Clase derivada: Estudiante =====
class Estudiante : public Usuario {
public:
    Estudiante(string n);
    int diasPrestamo() const override;
    string tipoUsuario() const override;
};

// ===== Clase derivada: Profesor =====
class Profesor : public Usuario {
public:
    Profesor(string n);
    int diasPrestamo() const override;
    string tipoUsuario() const override;
};

#endif
