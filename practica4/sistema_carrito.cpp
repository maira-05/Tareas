#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad; 

public:
    Producto() : nombre(""), precio(0.0), cantidad(0) {}
    Producto(string n, double p, int c)
        : nombre(n), precio(p), cantidad(c) {}

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void setCantidad(int c) { cantidad = c; }
};

class ItemCarrito {
private:
    Producto producto;
    int cantidadComprada;

public:
    ItemCarrito(Producto p, int c)
        : producto(p), cantidadComprada(c) {}

    Producto getProducto() const { return producto; }
    int getCantidadComprada() const { return cantidadComprada; }

    double subtotal() const {
        return producto.getPrecio() * cantidadComprada;
    }
};

class CarritoCompras {
private:
    vector<ItemCarrito> items;

public:
    void agregarProducto(Producto p, int cantidad) {
        items.push_back(ItemCarrito(p, cantidad));
    }

    void eliminarProducto(const string& nombre) {
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
        double total = 0;
        for (const auto& item : items)
            total += item.subtotal();
        return total;
    }

    void mostrarCarrito() const {
        cout << "\n --- Carrito de Compras ---\n";
        if (items.empty()) {
            cout << "(Vacío)\n";
        } else {
            for (const auto& item : items) {
                cout << "- " << item.getProducto().getNombre()
                     << " x" << item.getCantidadComprada()
                     << " = $" << item.subtotal() << endl;
            }
            cout << "---------------------------\n";
            cout << "Total: $" << calcularTotal() << endl;
        }
    }

    bool estaVacio() const {
        return items.empty();
    }

    vector<ItemCarrito> getItems() const {
        return items;
    }
};

class Usuario {
private:
    string nombre;
    vector<string> historial; 

public:
    Usuario() : nombre("") {}
    Usuario(string n) : nombre(n) {}

    string getNombre() const { return nombre; }

    bool yaCompro(const string& producto) const {
        for (const auto& p : historial) {
            if (p == producto)
                return true;
        }
        return false;
    }

    void registrarCompra(const CarritoCompras& carrito) {
        for (const auto& item : carrito.getItems()) {
            string nombreProd = item.getProducto().getNombre();
            if (!yaCompro(nombreProd)) {
                historial.push_back(nombreProd);
            }
        }
    }

    void mostrarHistorial() const {
        cout << "\nHistorial de compras de " << nombre << ":\n";
        if (historial.empty()) {
            cout << "(No hay compras registradas)\n";
        } else {
            for (const auto& p : historial)
                cout << "- " << p << endl;
        }
    }
};

int main() {
    vector<Producto> productos = {
        Producto("Camiseta básica", 49900, 20),
        Producto("Pantalón de mezclilla", 89900, 15),
        Producto("Audífonos Bluetooth", 159900, 10),
        Producto("Mouse inalámbrico", 59900, 25),
        Producto("Lámpara LED", 74900, 12),
        Producto("Taza personalizada", 29900, 30),
        Producto("Perfume floral", 119900, 8),
        Producto("Shampoo natural", 39900, 16),
        Producto("Peluche de gato", 54900, 22),
        Producto("Set de colores", 44900, 18)
    };

    map<string, Usuario> usuarios;
    string nombreUsuario;

    while (true) {
        cout << "\n===== TIENDA EN LÍNEA =====\n";
        cout << "1. Iniciar sesión o registrarse\n";
        cout << "2. Mostrar usuarios registrados\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        int opcion;
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida\n";
            continue;
        }
        cin.ignore();

        if (opcion == 1) {
            cout << "\nIngrese su nombre: ";
            getline(cin, nombreUsuario);

            if (usuarios.find(nombreUsuario) == usuarios.end()) {
                usuarios[nombreUsuario] = Usuario(nombreUsuario);
                cout << "Bienvenido/a, " << nombreUsuario << " (nuevo usuario)\n";
            } else {
                cout << "Bienvenido/a de nuevo, " << nombreUsuario << "!\n";
            }

            Usuario& usuario = usuarios[nombreUsuario];
            CarritoCompras carrito;

            while (true) {
                cout << "\n--- MENÚ DE COMPRAS (" << usuario.getNombre() << ") ---\n";
                cout << "1. Ver catálogo \n";
                cout << "2. Agregar producto al carrito\n";
                cout << "3. Eliminar producto del carrito\n";
                cout << "4. Ver carrito\n";
                cout << "5. Finalizar compra\n";
                cout << "6. Ver historial de compras\n";
                cout << "7. Cerrar sesión\n";
                cout << "Seleccione una opción: ";

                int opcionMenu;
                if (!(cin >> opcionMenu)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida\n";
                    continue;
                }
                cin.ignore();

                if (opcionMenu == 1) {
                    cout << "\n--- 🏪 Catálogo de productos ---\n";
                    for (size_t i = 0; i < productos.size(); ++i) {
                        cout << i + 1 << ". " << productos[i].getNombre()
                             << " - $" << productos[i].getPrecio()
                             << " (Disponibles: " << productos[i].getCantidad() << ")\n";
                    }

                } else if (opcionMenu == 2) {
                    int indice, cantidad;
                    cout << "\nIngrese el número del producto: ";
                    cin >> indice;
                    cout << "Cantidad: ";
                    cin >> cantidad;
                    cin.ignore();

                    if (indice > 0 && indice <= (int)productos.size()) {
                        Producto& prod = productos[indice - 1];

                        if (cantidad > prod.getCantidad()) {
                            cout << "⚠ No hay suficiente stock. Solo quedan "
                                 << prod.getCantidad() << " unidades disponibles.\n";
                        } else if (usuario.yaCompro(prod.getNombre())) {
                            cout << "Ya compraste este producto anteriormente.\n";
                        } else {
                            carrito.agregarProducto(prod, cantidad);
                            cout << "✅ Producto agregado al carrito.\n";
                        }
                    } else {
                        cout << "Producto inválido.\n";
                    }

                } else if (opcionMenu == 3) {
                    string nombreProd;
                    cout << "Nombre del producto a eliminar: ";
                    getline(cin, nombreProd);
                    carrito.eliminarProducto(nombreProd);

                } else if (opcionMenu == 4) {
                    carrito.mostrarCarrito();

                } else if (opcionMenu == 5) {
                    if (!carrito.estaVacio()) {
                        // 🔽 Actualizar inventario tras la compra
                        for (const auto& item : carrito.getItems()) {
                            string nombreProd = item.getProducto().getNombre();
                            int cantidadComprada = item.getCantidadComprada();

                            for (auto& prod : productos) {
                                if (prod.getNombre() == nombreProd) {
                                    int nuevaCantidad = prod.getCantidad() - cantidadComprada;
                                    if (nuevaCantidad < 0) nuevaCantidad = 0;
                                    prod.setCantidad(nuevaCantidad);
                                    break;
                                }
                            }
                        }

                        usuario.registrarCompra(carrito);
                        cout << "\n✅ Compra realizada exitosamente.\n";

                        // Mostrar inventario actualizado
                        cout << "\n📦 Inventario actualizado:\n";
                        for (size_t i = 0; i < productos.size(); ++i) {
                            cout << i + 1 << ". " << productos[i].getNombre()
                                 << " - Disponibles: " << productos[i].getCantidad() << endl;
                        }

                        carrito = CarritoCompras();
                    } else {
                        cout << "El carrito está vacío.\n";
                    }

                } else if (opcionMenu == 6) {
                    usuario.mostrarHistorial();

                } else if (opcionMenu == 7) {
                    cout << "Cerrando sesión de " << usuario.getNombre() << "\n";
                    break;

                } else {
                    cout << "Opción inválida\n";
                }
            }

        } else if (opcion == 2) {
            cout << "\nUsuarios registrados:\n";
            if (usuarios.empty()) {
                cout << "(Ninguno)\n";
            } else {
                for (const auto& kv : usuarios) {
                    cout << "- " << kv.first << "\n";
                }
            }
        } else if (opcion == 3) {
            cout << "Saliendo...\n";
            break;
        } else {
            cout << "Opción inválida\n";
        }
    }

    cout << "\nGracias por visitar la tienda.\n";
    return 0;
}
