//Ejercicio 1: Sistema de Gestión de Biblioteca (versión básica)
#include <iostream>
#include <vector>
using namespace std;
class Libro {
    private:
        string titulo;
        string autor;
        int ISBN;
        bool disponible(){
            return true;
        };
    public:
        Libro(string t, string a, int i){
            titulo = t;
            autor = a;
            ISBN = i;

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
        

        
};