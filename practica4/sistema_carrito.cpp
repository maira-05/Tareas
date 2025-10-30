#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Producto {
    private:
    string nombre;
    double precio;
    int cantidad;
    public:
    Producto(string n, double p, int c)
        : nombre(n), precio(p), cantidad(c) {}
    string getNombre() const { 
        return nombre; 
    }
    double getPrecio() const { 
        return precio; 
    }
    int getCantidad() const { 
        return cantidad; 
    }
    void setCantidad(int c) { 
        cantidad = c; 
    }
};
class ItemCarrito {
    private:
    Producto producto;
    int cantidad;
    public:
    ItemCarrito(Producto p, int c)
        : producto(p), cantidad(c) {}
    Producto getProducto() const { 
        return producto; 
    }
    int getCantidad() const { 
        return cantidad; 
    }   
    void setCantidad(int c) { 
        cantidad = c; 
    }
    double getSubtotal() const { 
        return producto.getPrecio() * cantidad; 
    }

}; 
class CarritoCompras {
    private:
    vector<ItemCarrito> items;
    public:
    void agregarProducto(Producto p, int cantidad) {
        items.push_back(ItemCarrito(p, cantidad));
    }
    void eliminarProducto(string nombre) {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].getProducto().getNombre() == nombre) {
                items.erase(items.begin() + i);
                cout << "Producto eliminado del carrito.\n";
                return;
            }
        }
        cout << "Producto no encontrado en el carrito.\n";
    }
    double calcularTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getSubtotal();
        }
        return total;
    }
    void mostrarCarrito() const {
        cout << "\n===== Carrito de Compras =====\n";
        if (items.empty()) {
            cout << "(Vacío)\n";
        } 
        else {
            for (const auto& item : items) {
                cout << "Producto: " << item.getProducto().getNombre()
                     << " | Precio: $" << item.getProducto().getPrecio()
                     << " | Cantidad: " << item.getCantidad()
                     << " | Subtotal: $" << item.getSubtotal() << endl;
            }
            cout << "Total a pagar: $" << calcularTotal() << endl;
        }
    }
    bool estaVacio() const{
        return items.empty();
    }
    vector<ItemCarrito> getItems()const{
        return items;
    }
    
};
class Usuario {
    private:
    string nombre;
    vector<CarritoCompras> historial;
    public:
    Usuario(string n) : nombre(n) {}
    string getNombre() const {
        return nombre;
    }
    void agregarCompra(CarritoCompras carrito){
        historial.push_back(carrito);
    }
    void mostrarHistorial() const {
        cout << "\n===== Historial de Compras de " << nombre << " =====\n";
        if (historial.empty()) {
            cout << "(No hay compras realizadas)\n";
        } 
        else {
            for (size_t i = 0; i < historial.size(); ++i) {
                cout << "\n-- Compra #" << (i + 1) << " --\n";
                historial[i].mostrarCarrito();
            }
        }
    }
};
int main(){

}