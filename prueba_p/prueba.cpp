#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Estudiante {
private:
    string nombre;
    vector<float> notas;
    int creditos_aprobados;

public:
    Estudiante(string nombre) {
        this->nombre = nombre;
        creditos_aprobados = 0;
    }

    void agregarNota(float nota) {
        notas.push_back(nota);
        if (nota >= 3.0) {
            creditos_aprobados += 3; // Ejemplo: cada materia vale 3 créditos
        }
    }

    float calcularPromedio() const {
        if (notas.empty()) return 0.0;
        float suma = 0.0;
        for (float n : notas) {
            suma += n;
        }
        return suma / notas.size();
    }

    string getNombre() const {
        return nombre;
    }

    int getCreditos() const {
        return creditos_aprobados;
    }

    void mostrarResumen() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Promedio: " << calcularPromedio() << endl;
        cout << "Creditos aprobados: " << creditos_aprobados << endl;
        cout << "----------------------------" << endl;
    }
};

int main() {
    // Se crea un conjunto de estudiantes
    vector<Estudiante> estudiantes;

    // Registrar varios estudiantes
    estudiantes.push_back(Estudiante("Juan Perez"));
    estudiantes.push_back(Estudiante("Maria Gomez"));
    estudiantes.push_back(Estudiante("Luis Rodriguez"));

    // Simular registro de notas
    estudiantes[0].agregarNota(4.5);
    estudiantes[0].agregarNota(3.8);

    estudiantes[1].agregarNota(2.9);
    estudiantes[1].agregarNota(3.2);

    estudiantes[2].agregarNota(4.0);
    estudiantes[2].agregarNota(4.7);

    // Mostrar resumen general de todos los estudiantes
    cout << "\n=== RESUMEN DE ESTUDIANTES ===\n";
    for (const Estudiante &e : estudiantes) {
        e.mostrarResumen();
    }

    // Calcular promedio general del grupo
    float suma_promedios = 0.0;
    for (const Estudiante &e : estudiantes) {
        suma_promedios += e.calcularPromedio();
    }
    float promedio_general = suma_promedios / estudiantes.size();

    cout << "Promedio general de todos los estudiantes: " << promedio_general << endl;

    return 0;
}
