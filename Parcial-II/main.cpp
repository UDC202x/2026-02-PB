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

#include "plataforma.h"

using namespace std;

int main() {
    vector<Usuario> usuarios = cargarUsuarios();
    vector<Producto> productos = cargarProductos();
    vector<Comentario> comentarios = cargarComentarios();
    vector<CarritoDeCompras> carritos;

    string correoIngresado, contrasenaIngresada;

    cout << "=== INICIO DE SESION ===\n";
    cout << "Correo: ";
    if (!(cin >> correoIngresado)) return 0;

    cout << "Contrasena: ";
    if (!(cin >> contrasenaIngresada)) return 0;

    Usuario usuarioActual{};

    if (!iniciarSesion(usuarios, correoIngresado,
                       contrasenaIngresada, usuarioActual)) {
        cout << "Usuario invalido\n";
        return 0;
    }

    cout << "Inicio de sesion exitoso\n";

    int opcion = -1;

    while (opcion != 0) {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Listar productos con stock menor que 15\n";
        cout << "2. Comentarios desde una fecha\n";
        cout << "3. Listar usuarios\n";
        cout << "4. Adicionar producto al carrito\n";
        cout << "5. Listar productos del carrito\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            if (cin.eof()) break;

            cout << "Entrada invalida. El programa terminara.\n";
            break;
        }

        switch (opcion) {
            case 1: {
                vector<Producto> resultado =
                    productosBajoStock(productos, 15);

                for (const Producto& p : resultado) {
                    cout << p.idProducto << " | " << p.nombre
                         << " | Stock: " << p.stock
                         << " | Precio: " << p.precio << '\n';
                }
                break;
            }

            case 2: {
                string fecha;
                cout << "Ingrese la fecha (dd/mm/yyyy): ";

                if (!(cin >> fecha)) return 0;

                vector<Comentario> resultado =
                    comentariosDesde(comentarios, fecha);

                if (resultado.empty()) {
                    cout << "No hay comentarios desde esa fecha "
                            "o la fecha no es valida.\n";
                }

                for (const Comentario& c : resultado) {
                    cout << c.idComentario << " | " << c.producto
                         << " | " << c.usuario << " | "
                         << c.comentario << " | " << c.fecha << '\n';
                }
                break;
            }

            case 3: {
                vector<string> resultado =
                    listarUsuariosFormateados(usuarios);

                for (const string& linea : resultado) {
                    cout << linea << '\n';
                }
                break;
            }

            case 4: {
                int idProducto;
                cout << "Ingrese el ID del producto: ";

                if (!(cin >> idProducto)) {
                    if (cin.eof()) return 0;

                    cout << "Entrada invalida. El programa terminara.\n";
                    return 0;
                }

                ResultadoCarrito resultado =
                    agregarAlCarrito(carritos, productos,
                                     usuarioActual, idProducto);

                if (resultado == CARRITO_PRODUCTO_INVALIDO) {
                    cout << "Producto inexistente.\n";
                } else if (resultado == CARRITO_SIN_STOCK) {
                    cout << "El producto no tiene stock disponible.\n";
                } else {
                    cout << "Producto agregado al carrito.\n";
                }
                break;
            }

            case 5: {
                int idCarrito = -1;

                for (const CarritoDeCompras& c : carritos) {
                    if (c.usuario.idUsuario == usuarioActual.idUsuario) {
                        idCarrito = c.idCarrito;
                        break;
                    }
                }

                if (idCarrito == -1) {
                    cout << "No tienes un carrito creado.\n";
                    break;
                }

                vector<Producto> resultado =
                    listarProductosCarrito(carritos, idCarrito);

                for (const Producto& p : resultado) {
                    cout << p.nombre << " | Precio: "
                         << p.precio << '\n';
                }

                for (const CarritoDeCompras& c : carritos) {
                    if (c.idCarrito == idCarrito) {
                        cout << "Subtotal: " << c.subtotal << '\n';
                        cout << "Impuestos (19%): "
                             << c.impuestos << '\n';
                        cout << "Total: "
                             << c.subtotal + c.impuestos << '\n';
                        break;
                    }
                }
                break;
            }

            case 0:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
    }

    return 0;
}
