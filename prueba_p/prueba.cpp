#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    int programa;
    int ID
    float promedio;
    int aprobadas;
public:
    Estudiante(string n, int prog, float prom, int A, int I){
        nombre = n;
        programa = prog;
        promedio = prom;
        aprobadas = A;
        ID = I;
    }

    string getNombre() {
        return nombre;
    }
    int getPrograma() {
        return programa;
    }
    float getPromedio() {
        return promedio;
    }
    int getAprobados() {
        return aprobadas;
    }
    int getID() {
        return ID;
    }

    void setPrograma(int prog) {
        if (prog > 0) {
            programa = prog;
        }
        else {
            cout << "Programa invalido" << endl;
        }
    }
    void setPromedio(float prom) {
        if (prom >= 0.0 && prom <= 5.0) {
            promedio = prom;
        }
        else {
            cout << "Promedio invalido" << endl;
        }
    }
    void setAprobadas(int A) {
        if (A >= 0) {
            aprobadas = A;
        }
        else {
            cout << "Numero de materias aprobadas invalido" << endl;
        }
    }
    void setID(int I) {
        if (I > 0) {
            ID = I;
        }
        else {
            cout << "ID invalido" << endl;
        }
    }

    void agregarcreditos() {
        int creditos;
        aprobadas += creditos;
    }

    void registronota() {
        float nota;
        int creditos;
        promedio = ((promedio * aprobadas) + (nota * creditos)) / (aprobadas + creditos);
        aprobadas += creditos;   
    }

    string obtenerresumen() {
        return "nombre:" + nombre
                + ", programa:" + to_string(programa)
                + ", ID:" + to_string(ID)
                + ", promedio:" + to_string(promedio)
                + ", aprobadas:" + to_string(aprobadas);
    }

    bool grado(int creditos_requeridos) {
        return (aprobadas >= creditos_requeridos);
    }

};

main() {
    vector<Estudiante> estudiantes;
    estudiantes.push_back(estudiantes("Juan Perez", 101, 4.5, 30, 12345));
    estudiantes.push_back(estudiantes("Maria Gomez", 102, 3.8, 25, 67890)); 
    estudiantes.push_back(estudiantes("Luis Rodriguez", 103, 4.2, 28, 11223));
    
    estudiantes[0].registronota(4.9, 0.5);
    estudiantes[1].agregarnota(2.2, 0);
    estudiantes[2].agregarnota(3.5, 2.5);

    cout<<"Resumen de estudiantes:"<<endl;
    for (auto &e : estudiantes) {
        cout<<e.obtenerresumen()<<endl;
    }

    float suma_promedios = 0.0;
    for (auto &e : estudiantes) suma_promedios += e.getPromedio();
    float promedio_general = suma_promedios / estudiantes.size();
    cout<<"\nPromedio general de la clase: "<<promedio_general<<endl;   
    

    return 0;
}