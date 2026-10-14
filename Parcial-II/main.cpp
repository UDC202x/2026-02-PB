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

    string correo;
    string contrasena;
    Usuario actual;

    cin >> correo >> contrasena;
    if (cin.fail() || !iniciarSesion(usuarios, correo, contrasena, actual)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    cout << "Bienvenido, " << actual.nombre << endl;

    int opcion = -1;
    while (opcion != 0) {
        cout << endl;
        cout << "===== MENU =====" << endl;
        cout << "1. Listar productos con stock menor que 15" << endl;
        cout << "2. Comentarios desde una fecha" << endl;
        cout << "3. Listar usuarios" << endl;
        cout << "4. Adicionar producto al carrito" << endl;
        cout << "5. Listar productos del carrito" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        cin >> opcion;
        if (cin.fail()) break;

        if (opcion == 1) {
            vector<Producto> bajos = productosBajoStock(productos);
            for (int i = 0; i < bajos.size(); i++) {
                cout << bajos[i].idProducto << " | " << bajos[i].nombre << " | "
                     << bajos[i].descripcion << " | $" << bajos[i].precio << " | stock: "
                     << bajos[i].stock << endl;
            }
            if (bajos.size() == 0) cout << "No hay productos con stock bajo" << endl;

        } else if (opcion == 2) {
            string fecha;
            cout << "Fecha (dd/mm/yyyy): ";
            cin >> fecha;
            if (cin.fail()) break;
            vector<Comentario> lista = comentariosDesde(comentarios, fecha);
            for (int i = 0; i < lista.size(); i++) {
                cout << lista[i].idComentario << " | " << lista[i].producto << " | "
                     << lista[i].usuario << " | " << lista[i].comentario << " | "
                     << lista[i].fecha << endl;
            }
            if (lista.size() == 0) cout << "No hay comentarios desde esa fecha" << endl;

        } else if (opcion == 3) {
            vector<string> lineas = listarUsuariosFormateados(usuarios);
            for (int i = 0; i < lineas.size(); i++) {
                cout << lineas[i] << endl;
            }

        } else if (opcion == 4) {
            int idProducto;
            cout << "Id del producto: ";
            cin >> idProducto;
            if (cin.fail()) break;
            ResultadoCarrito resultado = agregarAlCarrito(carritos, productos, actual, idProducto);
            if (resultado == CARRITO_OK) {
                cout << "Producto agregado al carrito" << endl;
            } else if (resultado == CARRITO_PRODUCTO_INVALIDO) {
                cout << "Producto inexistente" << endl;
            } else {
                cout << "Producto sin stock" << endl;
            }

        } else if (opcion == 5) {
            int posCarrito = -1;
            for (int i = 0; i < carritos.size(); i++) {
                if (carritos[i].usuario.idUsuario == actual.idUsuario) {
                    posCarrito = i;
                }
            }
            if (posCarrito == -1) {
                cout << "El carrito esta vacio" << endl;
            } else {
                vector<Producto> lista = listarProductosCarrito(carritos, carritos[posCarrito].idCarrito);
                for (int i = 0; i < lista.size(); i++) {
                    cout << lista[i].idProducto << " | " << lista[i].nombre << " | $"
                         << lista[i].precio << endl;
                }
                cout << "Subtotal: " << carritos[posCarrito].subtotal << endl;
                cout << "Impuestos: " << carritos[posCarrito].impuestos << endl;
            }

        } else if (opcion != 0) {
            cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}
