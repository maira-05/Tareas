//Ejercicio 1: Sistema de Gestión de Biblioteca (versión básica)
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
        Libro(string t, string a, int i){
            titulo = t;
            autor = a;
            ISBN = i;
            disponible = true;
        }
        string getTitulo(){
            return titulo;
        }
        string getAutor(){
            return autor;
        }
        int getIsbn(){
            return ISBN;
        }
        int setIsbn(){
            if(ISBN > 0){
                return ISBN;
            } else {
                cout << "ISBN inválido." << endl;
            }
        }
        bool getDisponible(){
            return disponible;
        }
        bool setDisponible(bool d){
            disponible = d;
            return disponible;
        }
};