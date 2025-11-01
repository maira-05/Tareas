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
        
    }

};