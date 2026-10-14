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

    // 1. Iniciar Sesion de los usuarios
    string correo, contrasena;
    if (!(cin >> correo >> contrasena)) {
        return 0;
    }

    Usuario usuarioLogueado;
    if (!iniciarSesion(usuarios, correo, contrasena, usuarioLogueado)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    // 2. El Menu de opciones
    int opcion;
    while (cin >> opcion) {
        if (opcion == 0) {
            break;
        }

        switch (opcion) {
            case 1: {
                // Listar productos con stock menor a 15
                vector<Producto> productosBajo = productosBajoStock(productos);
                for (const auto& prod : productosBajo) {
                    cout << prod.idProducto << " - " << prod.nombre << " - " << prod.descripcion 
                         << " - " << prod.precio << " - " << prod.stock << "\n";
                }
                break;
            }
            case 2: {
                // Comentarios desde una fecha especifica (dd/mm/yyyy)
                string fechaConsulta;
                if (cin >> fechaConsulta) {
                    vector<Comentario> listaComentarios = comentariosDesde(comentarios, fechaConsulta);
                    for (const auto& com : listaComentarios) {
                        cout << com.idComentario << " - " << com.producto << " - " << com.usuario 
                             << " - " << com.comentario << " - " << com.fecha << "\n";
                    }
                }
                break;
            }
            case 3: {
                vector<string> listaUsuariosFormateada = listarUsuariosFormateados(usuarios);
                for (const auto& usrStr : listaUsuariosFormateada) {
                    cout << usrStr << "\n";
                }
                break;
            }
            case 4: {
                int idProductoAnadir;
                if (cin >> idProductoAnadir) {
                    agregarAlCarrito(carritos, productos, usuarioLogueado, idProductoAnadir);
                }
                break;
            }
            case 5: {
                int idCarritoEncontrado = -1;
                double subtotal = 0.0;
                double impuestos = 0.0;

                for (const auto& car : carritos) {
                    if (car.usuario.idUsuario == usuarioLogueado.idUsuario) {
                        idCarritoEncontrado = car.idCarrito;
                        subtotal = car.subtotal;
                        impuestos = car.impuestos;
                        break;
                    }
                }

                if (idCarritoEncontrado != -1) {
                    vector<Producto> productosCarrito = listarProductosCarrito(carritos, idCarritoEncontrado);
                    for (const auto& prod : productosCarrito) {
                        cout << prod.idProducto << " - " << prod.nombre << " - " << prod.descripcion 
                             << " - " << prod.precio << " - " << prod.stock << "\n";
                    }
                    cout << "Subtotal: " << subtotal << "\n";
                    cout << "Impuestos: " << impuestos << "\n";
                } else {
                    cout << "Subtotal: 0\n";
                    cout << "Impuestos: 0\n";
                }
                break;
            }
            default:
                break;
        }
    }

    return 0;
}