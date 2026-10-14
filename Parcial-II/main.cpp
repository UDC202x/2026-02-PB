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

    Usuario UsuarioConfirmado;
    string correo;
    string contrasena;

    cout << "Digite su correo: ";
    cin >> correo;
    cout << "Contraseña: ";
    cin >> contrasena;

    bool inicio = iniciarSesion(usuarios, correo, contrasena, UsuarioConfirmado);
    if (inicio == false) {
        cout << "Usuario invalido" << endl;
        return 0;  
    }

    int opcion = -1;
    while (opcion != 0) {
        cout << "MENU PLATAFORMA" << endl
             << "1. Listar productos (stock < 15)" << endl
             << "2. Comentarios desde una fecha" << endl
             << "3. Listar usuarios" << endl
             << "4. Adicionar producto al carrito" << endl
             << "5. Listar productos del carrito" << endl
             << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            break;
        }

        if (opcion == 0) {
            break;
        }

        switch (opcion) {
            case 1: {
                vector<Producto> listafiltrada = productosBajoStock(productos, UMBRAL_STOCK_BAJO);
                for (size_t i = 0; i < listafiltrada.size(); i++) {
                    cout << listafiltrada[i].idProducto << " - " 
                         << listafiltrada[i].nombre << " - $" 
                         << listafiltrada[i].precio << " - Stock: " 
                         << listafiltrada[i].stock << endl;
                }
                break;
            }
            case 2: {
                string fecha;
                cout << "Ingrese la fecha (dd/mm/yyyy): ";
                cin >> fecha;
                vector<Comentario> coms = comentariosDesde(comentarios, fecha);
                for (size_t i = 0; i < coms.size(); i++) {
                    cout << coms[i].idComentario << " - " 
                         << coms[i].producto << " - " 
                         << coms[i].usuario << " - " 
                         << coms[i].fecha << ": " 
                         << coms[i].comentario << endl;
                }
                break;
            }
            case 3: {
                vector<string> listaUsuarios = listarUsuariosFormateados(usuarios);
                for (size_t i = 0; i < listaUsuarios.size(); i++) {
                    cout << listaUsuarios[i] << endl;
                }
                break;
            }
            case 4: {
                int idProd;
                cout << "Ingrese ID del producto: ";
                cin >> idProd;
                agregarAlCarrito(carritos, productos, UsuarioConfirmado, idProd);
                break;
            }
            case 5: {
                int idCarritoUsuario = -1;
                for (size_t i = 0; i < carritos.size(); i++) {
                    if (carritos[i].usuario.idUsuario == UsuarioConfirmado.idUsuario) {
                        idCarritoUsuario = carritos[i].idCarrito;
                        break;
                    }
                }

                if (idCarritoUsuario != -1) {
                    vector<Producto> prodsCarrito = listarProductosCarrito(carritos, idCarritoUsuario);
                    for (size_t i = 0; i < prodsCarrito.size(); i++) {
                        cout << prodsCarrito[i].idProducto << " - " 
                             << prodsCarrito[i].nombre << " - $" 
                             << prodsCarrito[i].precio << endl;
                    }

                    for (size_t i = 0; i < carritos.size(); i++) {
                        if (carritos[i].idCarrito == idCarritoUsuario) {
                            cout << "Subtotal: $" << carritos[i].subtotal << endl;
                            cout << "Impuestos: $" << carritos[i].impuestos << endl;
                            break;
                        }
                    }
                }
                break;
            }
            default:
                break;
        }
    }

    return 0;
}