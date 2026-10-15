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

    // TODO: login y menu
    (void)usuarios; (void)productos; (void)comentarios; (void)carritos;
    
    string correo, contrasena;
    if (!(cin >> correo)) return 0;
    if (!(cin >> contrasena)) return 0;

    Usuario usuario;
    if (!iniciarSesion(usuarios, correo, contrasena, usuario)) {
        cout << "Usuario invalido" << endl;
        return 0;
    }

    int opcion = -1;
    while (cin >> opcion) {
        if (opcion == 0) break;
        if (opcion == 1) {
            vector<Producto> lista = productosBajoStock(productos, 15);
            for (const Producto& p : lista)
                cout << p.idProducto << " " << p.nombre << " " << p.descripcion << " " << p.precio << " " << p.stock << endl;
        }
        else if (opcion == 2) {
            string fecha;
            if (!(cin >> fecha)) break;
            vector<Comentario> lista = comentariosDesde(comentarios, fecha);
            for (const Comentario& c : lista)
                cout << c.idComentario << " " << c.producto << " " << c.usuario << " " << c.comentario << " " << c.fecha << endl;
        }
        else if (opcion == 3) {
            vector<string> lista = listarUsuariosFormateados(usuarios);
            for (const string& nombre : lista) cout << nombre << endl;
        }
        else if (opcion == 4) {
            int id;
            if (!(cin >> id)) break;
            ResultadoCarrito r = agregarAlCarrito(carritos, productos, usuario, id);
            if (r == CARRITO_PRODUCTO_INVALIDO) cout << "Producto invalido o sin stock" << endl;
        }
        else if (opcion == 5) {
            int idCarrito = 0;
            for (const CarritoDeCompras& c : carritos)
                if (c.usuario.idUsuario == usuario.idUsuario) idCarrito = c.idCarrito;
            vector<Producto> lista = listarProductosCarrito(carritos, idCarrito);
            for (const Producto& p : lista)
                cout << p.idProducto << " " << p.nombre << " " << p.precio << endl;
            for (const CarritoDeCompras& c : carritos)
                if (c.idCarrito == idCarrito)
                    cout << "Subtotal: " << c.subtotal << endl << "Impuestos: " << c.impuestos << endl;
        }
    }
    return 0;
}