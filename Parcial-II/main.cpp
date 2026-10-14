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

    // Login y menu
    string correo, contrasena;
    if (!(cin >> correo >> contrasena)) return 0;

    Usuario usuarioActual;
    if (!iniciarSesion(usuarios, correo, contrasena, usuarioActual)) {
        cout << "Usuario invalido\n";
        return 0;
    }

    int opcion;
    while (true) {
        if (!(cin >> opcion)) {
            // Prevenir ciclo infinito ante texto no numerico o fin de entrada
            cin.clear();
            string entradaIgnorada;
            if (!(cin >> entradaIgnorada)) break; 
            continue;
        }

        if (opcion == 0) {
            break;
        } else if (opcion == 1) {
            auto bajoStock = productosBajoStock(productos);
            for (const auto& p : bajoStock) {
                cout << p.idProducto << " - " << p.nombre << " | Stock: " << p.stock << "\n";
            }
        } else if (opcion == 2) {
            string fecha;
            cin >> fecha;
            auto comentariosFiltrados = comentariosDesde(comentarios, fecha);
            for (const auto& c : comentariosFiltrados) {
                cout << c.idComentario << " | " << c.fecha << " | " << c.usuario << " | " << c.producto << " | " << c.comentario << "\n";
            }
        } else if (opcion == 3) {
            auto listaUsuarios = listarUsuariosFormateados(usuarios);
            for (const auto& u : listaUsuarios) {
                cout << u << "\n";
            }
        } else if (opcion == 4) {
            int idProducto;
            if (cin >> idProducto) {
                ResultadoCarrito res = agregarAlCarrito(carritos, productos, usuarioActual, idProducto);
                if (res == CARRITO_PRODUCTO_INVALIDO) {
                    cout << "Producto invalido\n";
                } else if (res == CARRITO_SIN_STOCK) {
                    cout << "Sin stock\n";
                } else {
                    cout << "Producto agregado al carrito\n";
                }
            } else {
                cin.clear();
                string temp;
                cin >> temp;
            }
        } else if (opcion == 5) {
            int idCarrito = -1;
            double subtotal = 0.0;
            double impuestos = 0.0;
            
            // Buscar el carrito del usuario actual
            for (const auto& c : carritos) {
                if (c.usuario.idUsuario == usuarioActual.idUsuario) {
                    idCarrito = c.idCarrito;
                    subtotal = c.subtotal;
                    impuestos = c.impuestos;
                    break;
                }
            }

            if (idCarrito != -1) {
                auto prodsCarrito = listarProductosCarrito(carritos, idCarrito);
                for (const auto& p : prodsCarrito) {
                    cout << p.idProducto << " - " << p.nombre << " | $" << p.precio << "\n";
                }
                cout << "Subtotal: $" << subtotal << "\n";
                cout << "Impuestos: $" << impuestos << "\n";
            } else {
                cout << "El carrito esta vacio.\n";
            }
        }
    }

    return 0;
}