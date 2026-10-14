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

    // 1. login
    string correo, contrasena;
    if (!(cin >> correo >> contrasena)) {
        return 0;
    }

    Usuario actual;
    if (!iniciarSesion(usuarios, correo, contrasena, actual)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    int opcion;
    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Productos con stock menor que 15" << endl;
        cout << "2. Comentarios desde una fecha" << endl;
        cout << "3. Listar usuarios" << endl;
        cout << "4. Adicionar producto al carrito" << endl;
        cout << "5. Listar productos del carrito" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            break;
        }
        if (opcion == 0) {
            break;
        }

        if (opcion == 1) {
            vector<Producto> bajos = productosBajoStock(productos);
            for (size_t i = 0; i < bajos.size(); i++) {
                cout << bajos[i].idProducto << " | " << bajos[i].nombre << " | stock: " << bajos[i].stock << endl;
            }
        } else if (opcion == 2) {
            string fecha;
            if (!(cin >> fecha)) break;
            vector<Comentario> lista = comentariosDesde(comentarios, fecha);
            for (size_t i = 0; i < lista.size(); i++) {
                cout << lista[i].fecha << " | " << lista[i].producto << " | " << lista[i].usuario
                     << " | " << lista[i].comentario << endl;
            }
        } else if (opcion == 3) {
            vector<string> lineas = listarUsuariosFormateados(usuarios);
            for (size_t i = 0; i < lineas.size(); i++) {
                cout << lineas[i] << endl;
            }
        } else if (opcion == 4) {
            int idProducto;
            if (!(cin >> idProducto)) break;
            ResultadoCarrito r = agregarAlCarrito(carritos, productos, actual, idProducto);
            if (r == CARRITO_OK) {
                cout << "Producto agregado al carrito" << endl;
            } else if (r == CARRITO_PRODUCTO_INVALIDO) {
                cout << "Producto inexistente" << endl;
            } else {
                cout << "Producto sin stock" << endl;
            }
        } else if (opcion == 5) {
            int pos = -1;
            for (size_t i = 0; i < carritos.size(); i++) {
                if (carritos[i].usuario.idUsuario == actual.idUsuario) {
                    pos = (int)i;
                    break;
                }
            }
            if (pos == -1) {
                cout << "El carrito esta vacio" << endl;
            } else {
                vector<Producto> items = listarProductosCarrito(carritos, carritos[pos].idCarrito);
                for (size_t i = 0; i < items.size(); i++) {
                    cout << items[i].idProducto << " | " << items[i].nombre << " | " << items[i].precio << endl;
                }
                cout << "Subtotal: " << carritos[pos].subtotal << endl;
                cout << "Impuestos: " << carritos[pos].impuestos << endl;
            }
        } else {
            cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}