// main.cpp -- login y menu. Unico lugar donde se usa cin/cout.
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

    string correo, contrasena;
    Usuario actual{};
    if (!(cin >> correo >> contrasena) || !iniciarSesion(usuarios, correo, contrasena, actual)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    int opcion = -1;
    while (true) {
        cout << "\n===== MENU =====\n"
             << "1. Listar productos con stock menor que 15\n"
             << "2. Comentarios desde una fecha\n"
             << "3. Listar usuarios\n"
             << "4. Adicionar producto al carrito\n"
             << "5. Listar productos del carrito\n"
             << "0. Salir\n"
             << "Opcion: ";
        if (!(cin >> opcion)) break;  // texto no numerico o fin de entrada
        if (opcion == 0) break;

        if (opcion == 1) {
            vector<Producto> bajos = productosBajoStock(productos);
            for (size_t i = 0; i < bajos.size(); ++i) {
                cout << bajos[i].idProducto << " | " << bajos[i].nombre << " | " << bajos[i].descripcion
                     << " | $" << bajos[i].precio << " | stock: " << bajos[i].stock << "\n";
            }
        } else if (opcion == 2) {
            string fecha;
            if (!(cin >> fecha)) break;
            vector<Comentario> lista = comentariosDesde(comentarios, fecha);
            if (lista.empty()) cout << "No hay comentarios para esa fecha\n";
            for (size_t i = 0; i < lista.size(); ++i) {
                cout << lista[i].idComentario << " | " << lista[i].producto << " | " << lista[i].usuario
                     << " | " << lista[i].comentario << " | " << lista[i].fecha << "\n";
            }
        } else if (opcion == 3) {
            vector<string> lineas = listarUsuariosFormateados(usuarios);
            for (size_t i = 0; i < lineas.size(); ++i) cout << lineas[i] << "\n";
        } else if (opcion == 4) {
            int id;
            if (!(cin >> id)) break;
            ResultadoCarrito r = agregarAlCarrito(carritos, productos, actual, id);
            if (r == CARRITO_OK) cout << "Producto agregado al carrito\n";
            else if (r == CARRITO_SIN_STOCK) cout << "Producto sin stock\n";
            else cout << "Producto invalido\n";
        } else if (opcion == 5) {
            const CarritoDeCompras* mio = nullptr;
            for (size_t i = 0; i < carritos.size(); ++i) {
                if (carritos[i].usuario.idUsuario == actual.idUsuario) mio = &carritos[i];
            }
            if (mio == nullptr) {
                cout << "El carrito esta vacio\n";
            } else {
                vector<Producto> lista = listarProductosCarrito(carritos, mio->idCarrito);
                for (size_t i = 0; i < lista.size(); ++i) {
                    cout << lista[i].idProducto << " | " << lista[i].nombre << " | $" << lista[i].precio << "\n";
                }
                cout << "Subtotal: " << mio->subtotal << "\n";
                cout << "Impuestos: " << mio->impuestos << "\n";
            }
        } else {
            cout << "Opcion no valida\n";
        }
    }
    return 0;
}
