// =====================================================================
//  main.cpp -- PLANTILLA. Unico lugar donde se usa cin/cout.
//  Protocolo de entrada/salida: ver anexo_enunciado.md
//    1) Pedir correo y contrasena (cin >> ...). Si iniciarSesion falla -> imprimir
//       "Usuario invalido" y terminar.
//    2) Menu en ciclo hasta elegir 0:
//       1 Listar productos (stock < 15)      4 Adicionar producto al carrito (pide id)
//       2 Comentarios desde una fecha (pide fecha dd/mm/yyyy)   5 Listar productos del carrito
//       3 Listar usuarios                    0 Salir
// =====================================================================
#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "plataforma.h"

using namespace std;

int main() {

    vector<Usuario> usuarios = cargarUsuarios();
    vector<Producto> productos = cargarProductos();
    vector<Comentario> comentarios = cargarComentarios();
    vector<CarritoDeCompras> carritos;

    // TODO: login y menu

    
    string correo, contrasena;
    cout << "Ingrese su correo electronico: ";
    cin >> correo;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;

    Usuario usuarioActual;
    
    if (!iniciarSesion(usuarios, correo, contrasena, usuarioActual)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    cout << "\n¡Bienvenido, " << usuarioActual.nombre << "!\n" << endl;

    int opcion = -1;
    
    while (opcion != 0) {
        cout << "========================================" << endl;
        cout << "            MENU PRINCIPAL              " << endl;
        cout << "========================================" << endl;
        cout << "1. Listar productos con stock menor que 15" << endl;
        cout << "2. Comentarios desde una fecha" << endl;
        cout << "3. Listar usuarios (nombre en mayuscula, sin contrasena)" << endl;
        cout << "4. Adicionar un producto al carrito" << endl;
        cout << "5. Listar productos del carrito, con subtotal e impuestos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        
        if (!(cin >> opcion)) {
            cout << "\nEntrada invalida. Por favor, ingrese un numero del menu.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
               
                vector<Producto> productosBajos = productosBajoStock(productos);
                cout << "\n--- Productos con stock menor que 15 ---" << endl;
                if (productosBajos.empty()) {
                    cout << "No hay productos con stock menor a 15." << endl;
                } else {
                    for (const auto& p : productosBajos) {
                        cout << "ID: " << p.idProducto 
                             << " | Nombre: " << p.nombre 
                             << " | Stock: " << p.stock 
                             << " | Precio: $" << p.precio << endl;
                    }
                }
                cout << endl;
                break;
            }
            case 2: {
                
                string fecha;
                cout << "Ingrese la fecha (d/mm/yyyy): ";
                cin >> fecha;

                vector<Comentario> comps = comentariosDesde(comentarios, fecha);
                cout << "\n--- Comentarios desde " << fecha << " ---" << endl;
                if (comps.empty()) {
                    cout << "No hay comentarios encontrados o la fecha es invalida." << endl;
                } else {
                    for (const auto& c : comps) {
                        cout << "[" << c.fecha << "] " << c.usuario << " sobre " << c.producto << ": " << c.comentario << endl;
                    }
                }
                cout << endl;
                break;
            }
            case 3: {
                
                vector<string> listaUsrs = listarUsuariosFormateados(usuarios);
                cout << "\n--- Lista de Usuarios Formateados ---" << endl;
                for (const auto& uStr : listaUsrs) {
                    cout << uStr << endl;
                }
                cout << endl;
                break;
            }
            case 4: {
                
                int idProducto;
                cout << "Ingrese el ID del producto que desea adicionar al carrito: ";
                if (!(cin >> idProducto)) {
                    cout << "ID invalido." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                ResultadoCarrito resultado = agregarAlCarrito(carritos, productos, usuarioActual, idProducto);
                
                if (resultado == CARRITO_OK) {
                    cout << "¡Producto agregado exitosamente al carrito!" << endl;
                } else if (resultado == CARRITO_PRODUCTO_INVALIDO) {
                    cout << "Error: El producto con ID " << idProducto << " no existe." << endl;
                } else if (resultado == CARRITO_SIN_STOCK) {
                    cout << "Error: El producto no tiene stock disponible." << endl;
                }
                cout << endl;
                break;
            }
            case 5: {
                
                int idCarroBuscado = 0;
                for (const auto& c : carritos) {
                    if (c.usuario.idUsuario == usuarioActual.idUsuario) {
                        idCarroBuscado = c.idCarrito;
                        break;
                    }
                }

                vector<Producto> prodsCarrito = listarProductosCarrito(carritos, idCarroBuscado);
                cout << "\n--- Productos en su Carrito ---" << endl;
                if (prodsCarrito.empty()) {
                    cout << "Su carrito esta vacio o no ha sido creado todavia." << endl;
                } else {
                    double subtotal = 0.0;
                    for (const auto& p : prodsCarrito) {
                        cout << "- " << p.nombre << " ($" << p.precio << ")" << endl;
                        subtotal += p.precio;
                    }
                    double impuestos = subtotal * TASA_IVA;
                    double total = subtotal + impuestos;
                    
                    cout << "---------------------------------" << endl;
                    cout << "Subtotal:        $" << subtotal << endl;
                    cout << "Impuestos (19%): $" << impuestos << endl;
                    cout << "Total:           $" << total << endl;
                }
                cout << endl;
                break;
            }
            case 0:
                cout << "Saliendo de la plataforma. ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, seleccione un numero del 0 al 5.\n" << endl;
        }
    }

    return 0;
}