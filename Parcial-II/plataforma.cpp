// =====================================================================
//  plataforma.cpp -- PLANTILLA. Implementen aqui TODAS las funciones de plataforma.h.
//  * No modifiquen plataforma.h.
//  * Aqui NO se usa cin/cout (eso va en main.cpp).
//  * Al DEFINIR productosBajoStock NO repitan el valor por defecto del parametro.
// =====================================================================
#include "plataforma.h"
#include <cctype>
#include <cstddef>

namespace{

bool soloDigitos(const std::string& s) {
    if (s.empty()) return false;
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

// Maximo de dias de cada mes (febrero se acepta hasta 29).
int diasDelMes(int mes) {
    static const int dias[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dias[mes - 1];
}

// Convierte "d/mm/yyyy" o "dd/mm/yyyy" en un numero comparable yyyymmdd.
// Devuelve false si el formato o la fecha no son validos.
bool fechaANumero(const std::string& fecha, long& resultado) {
    std::size_t p1 = fecha.find('/');
    if (p1 == std::string::npos) return false;
    std::size_t p2 = fecha.find('/', p1 + 1);
    if (p2 == std::string::npos) return false;
    if (fecha.find('/', p2 + 1) != std::string::npos) return false;

    std::string sd = fecha.substr(0, p1);
    std::string sm = fecha.substr(p1 + 1, p2 - p1 - 1);
    std::string sa = fecha.substr(p2 + 1);

    if (!soloDigitos(sd) || !soloDigitos(sm) || !soloDigitos(sa)) return false;
    if (sd.size() > 2 || sm.size() > 2 || sa.size() != 4) return false;

    int d = std::stoi(sd);
    int m = std::stoi(sm);
    int a = std::stoi(sa);

    if (a < 1 || m < 1 || m > 12) return false;
    if (d < 1 || d > diasDelMes(m)) return false;

    resultado = static_cast<long>(a) * 10000 + m * 100 + d;
    return true;
}

}

//1. Datos iniciales de usuarios
std::vector<Usuario> cargarUsuarios() {
    // TODO: devolver los 5 usuarios de la tabla del enunciado
    std::vector<Usuario> v;
    v.push_back({1, "Juan Perez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de credito"});
    v.push_back({2, "Ana Gomez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"});
    v.push_back({3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal#100", "Transferencia bancaria"});
    v.push_back({4, "Sofia Martinez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"});
    v.push_back({5, "Diego Fernandez", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta debito"});

    return v;
    }

std::vector<Producto> cargarProductos() {
    // TODO: devolver los 50 productos de la tabla del enunciado

    std::vector<Producto> v;
    v.push_back({1, "Laptop", "Portatil con pantalla Full HD y SSD de 512GB", 89999, 10});
    v.push_back({2, "Smartphone", "Telefono con camara de 108MP y carga rapida", 49950, 20});
    v.push_back({3, "Tablet", "Dispositivo con pantalla tactil de 10 pulgadas", 29999, 15});
    v.push_back({4, "Auriculares", "Audifonos inalambricos con cancelacion de ruido", 12999, 25});
    v.push_back({5, "Teclado", "Teclado mecanico con iluminacion RGB", 8999, 30});
    v.push_back({6, "Mouse", "Raton inalambrico con sensor optico de alta precision", 5999, 50});
    v.push_back({7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12});
    v.push_back({8, "Impresora", "Laser multifuncional con Wi-Fi", 17999, 18});
    v.push_back({9, "Camara", "Camara digital con lente profesional", 79999, 8});
    v.push_back({10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardiaco", 19999, 22});
    v.push_back({11, "Silla Gamer", "Silla ergonomica ajustable con soporte lumbar", 29999, 14});
    v.push_back({12, "Microondas", "Horno microondas con multiples funciones", 12999, 40});
    v.push_back({13, "Refrigerador", "Frigorifico doble puerta con sistema No Frost", 119999, 5});
    v.push_back({14, "Lavadora", "Lavadora automatica con capacidad de 10kg", 59999, 7});
    v.push_back({15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35});
    v.push_back({16, "Drone", "Drone con camara 4K y estabilizador", 69999, 9});
    v.push_back({17, "Bocina Bluetooth", "Altavoz portatil con sonido envolvente", 8999, 33});
    v.push_back({18, "Videocamara", "Videocamara profesional con grabacion en 4K", 99999, 6});
    v.push_back({19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11});
    v.push_back({20, "Bateria Externa", "Bateria de 20000mAh con carga rapida", 3999, 45});
    v.push_back({21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28});
    v.push_back({22, "Memoria USB", "Pendrive de 128GB", 2999, 60});
    v.push_back({23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16});
    v.push_back({24, "Joystick", "Control inalambrico para videojuegos", 7999, 20});
    v.push_back({25, "Fuente de Poder", "Fuente de alimentacion para PC de 750W", 8999, 17});
    v.push_back({26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32});
    v.push_back({27, "Altavoces", "Par de bocinas estereo con subwoofer", 13999, 23});
    v.push_back({28, "Webcam", "Camara web Full HD con microfono integrado", 6999, 37});
    v.push_back({29, "Procesador", "CPU Intel i7 de ultima generacion", 34999, 9});
    v.push_back({30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13});
    v.push_back({31, "Memoria RAM", "Modulo de RAM DDR4 de 16GB", 7999, 41});
    v.push_back({32, "Fuente Solar", "Panel solar portatil con bateria integrada", 24999, 4});
    v.push_back({33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50});
    v.push_back({34, "Termostato", "Termostato digital programable", 9999, 22});
    v.push_back({35, "Smart Lock", "Cerradura electronica con huella digital", 19999, 6});
    v.push_back({36, "Proyector", "Proyector LED con resolucion Full HD", 29999, 12});
    v.push_back({37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38});
    v.push_back({38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26});
    v.push_back({39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55});
    v.push_back({40, "Estabilizador", "Estabilizador de voltaje para dispositivos electronicos", 15999, 10});
    v.push_back({41, "Cargador Inalambrico", "Base de carga inalambrica rapida", 4999, 30});
    v.push_back({42, "HDD Externo", "Disco duro portatil de 4TB", 17999, 15});
    v.push_back({43, "Microfono", "Microfono profesional para grabacion", 14999, 7});
    v.push_back({44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20});
    v.push_back({45, "Antena Wi-Fi", "Amplificador de senal inalambrico", 7999, 33});
    v.push_back({46, "Climatizador", "Aire acondicionado portatil con control remoto", 29999, 5});
    v.push_back({47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19});
    v.push_back({48, "Capturadora", "Placa de captura de video en alta resolucion", 19999, 8});
    v.push_back({49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42});
    v.push_back({50, "Timbre Inteligente", "Timbre con camara y conexion a Wi-Fi", 14999, 10});
    
    return v;
}


std::vector<Comentario> cargarComentarios() {
    // TODO: devolver los 50 comentarios de la tabla del enunciado

    std::vector<Comentario> v;
    v.push_back({1, "Laptop", "Juan Perez", "Excelente rendimiento; muy rapida. ¡Me encanta!", "1/05/2025"});
    v.push_back({2, "Smartphone", "Ana Gomez", "Buena camara pero la bateria dura poco.", "3/05/2025"});
    v.push_back({3, "Tablet", "Carlos Ruiz", "No me gusto; pantalla de baja calidad.", "5/05/2025"});
    v.push_back({4, "Auriculares", "Sofia Martinez", "Sonido aceptable pero el material parece fragil.", "6/05/2025"});
    v.push_back({5, "Teclado", "Diego Fernandez", "Muy buen teclado mecanico; excelente respuesta.", "8/05/2025"});
    v.push_back({6, "Mouse", "Ana Gomez", "El sensor no es tan preciso como esperaba.", "10/05/2025"});
    v.push_back({7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resolucion. Muy satisfecho.", "12/05/2025"});
    v.push_back({8, "Impresora", "Juan Perez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"});
    v.push_back({9, "Camara", "Sofia Martinez", "Increible calidad de imagen; fotos super nitidas.", "15/05/2025"});
    v.push_back({10, "Smartwatch", "Diego Fernandez", "Buena bateria; pero la pantalla no es muy brillante.", "18/05/2025"});
    v.push_back({11, "Silla Gamer", "Lucia Rodriguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"});
    v.push_back({12, "Microondas", "Andres Ramirez", "Calienta bien pero hace mucho ruido.", "22/05/2025"});
    v.push_back({13, "Refrigerador", "Maria Garcia", "Espacioso y enfria rapido; muy recomendado.", "24/05/2025"});
    v.push_back({14, "Lavadora", "Javier Martinez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"});
    v.push_back({15, "Cafetera", "Carolina Lopez", "Hace cafe delicioso; facil de usar.", "28/05/2025"});
    v.push_back({16, "Drone", "Daniel Castro", "Muy divertido pero la bateria dura poco.", "30/05/2025"});
    v.push_back({17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexion Bluetooth.", "1/06/2025"});
    v.push_back({18, "Videocamara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "3/06/2025"});
    v.push_back({19, "TV LED", "Fernanda Sanchez", "Imagen excelente pero el sonido podria mejorar.", "5/06/2025"});
    v.push_back({20, "Bateria Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "7/06/2025"});
    v.push_back({21, "Disco Duro", "Gabriela Suarez", "Gran capacidad de almacenamiento; funciona rapido.", "9/06/2025"});
    v.push_back({22, "Memoria USB", "Raul Espinosa", "Buen tamano pero la velocidad de transferencia es baja.", "11/06/2025"});
    v.push_back({23, "Router", "Veronica Mendoza", "Senal potente; cubre toda la casa.", "13/06/2025"});
    v.push_back({24, "Joystick", "Fabio Jimenez", "Comodo y resistente; ideal para gaming.", "15/06/2025"});
    v.push_back({25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"});
    v.push_back({26, "SSD", "Silvia Gomez", "Velocidad increible; mi PC va mucho mas rapido ahora.", "19/06/2025"});
    v.push_back({27, "Altavoces", "Martin Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"});
    v.push_back({28, "Webcam", "Valentina Perez", "Imagen clara pero el microfono es deficiente.", "23/06/2025"});
    v.push_back({29, "Procesador", "Jose Ramirez", "Rendimiento impecable; ideal para gaming y diseno.", "25/06/2025"});
    v.push_back({30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalacion fue complicada.", "27/06/2025"});
    v.push_back({31, "Memoria RAM", "Julio Fernandez", "Expande muy bien el rendimiento del sistema.", "29/06/2025"});
    v.push_back({32, "Fuente Solar", "Amanda Castro", "Energia confiable pero la bateria es pequena.", "1/07/2025"});
    v.push_back({33, "Control Remoto", "Pedro Duarte", "Facil de usar; reconoce muchos dispositivos.", "3/07/2025"});
    v.push_back({34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "5/07/2025"});
    v.push_back({35, "Smart Lock", "Oscar Rodriguez", "Seguridad y tecnologia en un solo dispositivo.", "7/07/2025"});
    v.push_back({36, "Proyector", "Cristina Vargas", "Imagen nitida pero requiere una sala oscura.", "9/07/2025"});
    v.push_back({37, "Switch Ethernet", "Mario Hernandez", "Buena velocidad de conexion; estable.", "11/07/2025"});
    v.push_back({38, "Reloj Digital", "Sofia Ramirez", "Pantalla atractiva pero la bateria dura poco.", "13/07/2025"});
    v.push_back({39, "Luces LED", "Andrea Gutierrez", "Buenas opciones de colores; buen diseno.", "15/07/2025"});
    v.push_back({40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"});
    v.push_back({41, "Cargador Inalambrico", "Patricia Lopez", "Carga rapido pero requiere posicionamiento preciso.", "19/07/2025"});
    v.push_back({42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"});
    v.push_back({43, "Microfono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"});
    v.push_back({44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; util en casa.", "25/07/2025"});
    v.push_back({45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la senal pero el rango es limitado.", "27/07/2025"});
    v.push_back({46, "Climatizador", "Estefania Carrillo", "Enfria rapido pero es algo ruidoso.", "29/07/2025"});
    v.push_back({47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electronicos y programacion.", "31/07/2025"});
    v.push_back({48, "Capturadora", "Luisa Mejia", "Ideal para streaming y grabaciones en alta calidad.", "2/08/2025"});
    v.push_back({49, "Smart Plug", "Victoria Torres", "Muy practico; facil de conectar y configurar.", "4/08/2025"});
    v.push_back({50, "Timbre Inteligente", "Federico Montoya", "Buena camara; util para seguridad.", "6/08/2025"});
    return v;

}

//Iniciar sesion

bool iniciarSesion(const std::vector<Usuario>& usuarios, const std::string& correo,
                   const std::string& contrasena, Usuario& usuarioOut) {
    // TODO
    for (std::size_t i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].correoElectronico == correo && usuarios[i].contrasena == contrasena) {
            usuarioOut = usuarios[i];
            return true;
        }
    }
    return false;
}

//Productos con stock menor que el umbral
std::vector<Producto> productosBajoStock(const std::vector<Producto>& productos, int umbral) {
    std::vector<Producto> resultado;
    for (std::size_t i = 0; i < productos.size(); ++i) {
        if (productos[i].stock < umbral) {
            resultado.push_back(productos[i]);
        }
    }
    return resultado;
}

//Comentarios fecha
std::vector<Comentario> comentariosDesde(const std::vector<Comentario>& comentarios, const std::string& fecha) {
    std::vector<Comentario> resultado;

    long limite = 0;
    if (!fechaANumero(fecha, limite)) {
        return resultado;  // fecha invalida: vector vacio
    }

    for (std::size_t i = 0; i < comentarios.size(); ++i) {
        long actual = 0;
        if (fechaANumero(comentarios[i].fecha, actual) && actual >= limite) {
            resultado.push_back(comentarios[i]);
        }
    }
    return resultado;
}



std::vector<std::string> listarUsuariosFormateados(const std::vector<Usuario>& usuarios) {

   std::vector<std::string> lineas;
    for (std::size_t i = 0; i < usuarios.size(); ++i) {
        std::string nombre = usuarios[i].nombre;
        for (std::size_t j = 0; j < nombre.size(); ++j) {
            nombre[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(nombre[j])));
        }
        std::string linea = "ID: " + std::to_string(usuarios[i].idUsuario) +
                            " | Nombre: " + nombre +
                            " | Correo: " + usuarios[i].correoElectronico +
                            " | Direccion: " + usuarios[i].direccion +
                            " | Metodo de pago: " + usuarios[i].metodoDePago;
        lineas.push_back(linea);
    }
    return lineas;
}

int siguienteIdCarrito(const std::vector<CarritoDeCompras>& carritos) {
    // TODO
    if (carritos.empty()) return 1;
    return carritos.back().idCarrito + 1;
}

ResultadoCarrito agregarAlCarrito(std::vector<CarritoDeCompras>& carritos, std::vector<Producto>& productos,
                                  const Usuario& usuario, int idProducto) {
    
    // 1. Buscar el producto en el inventario original
    int indiceProducto = -1;
    for (std::size_t i = 0; i < productos.size(); ++i) {
        if (productos[i].idProducto == idProducto) {
            indiceProducto = static_cast<int>(i);
            break;
        }
    }
    if (indiceProducto < 0) return CARRITO_PRODUCTO_INVALIDO;

    // 2. Verificar stock
    if (productos[indiceProducto].stock <= 0) return CARRITO_SIN_STOCK;

    // 3. Buscar el carrito del usuario (uno por usuario); crearlo si no existe
    int indiceCarrito = -1;
    for (std::size_t i = 0; i < carritos.size(); ++i) {
        if (carritos[i].usuario.idUsuario == usuario.idUsuario) {
            indiceCarrito = static_cast<int>(i);
            break;
        }
    }
    if (indiceCarrito < 0) {
        CarritoDeCompras nuevo;
        nuevo.idCarrito = siguienteIdCarrito(carritos);
        nuevo.usuario = usuario;
        nuevo.subtotal = 0.0;
        nuevo.impuestos = 0.0;
        carritos.push_back(nuevo);
        indiceCarrito = static_cast<int>(carritos.size()) - 1;
    }

    // 4. Agregar una unidad y descontar 1 del stock del inventario
    Producto unidad = productos[indiceProducto];
    unidad.stock = 1;  // en el carrito el stock representa la cantidad (1 unidad)
    carritos[indiceCarrito].productos.push_back(unidad);
    productos[indiceProducto].stock -= 1;

    // 5. Recalcular subtotal e impuestos
    double subtotal = 0.0;
    for (std::size_t i = 0; i < carritos[indiceCarrito].productos.size(); ++i) {
        subtotal += carritos[indiceCarrito].productos[i].precio;
    }
    carritos[indiceCarrito].subtotal = subtotal;
    carritos[indiceCarrito].impuestos = subtotal * 0.19;

    return CARRITO_OK;
}

//Productos del carrito

std::vector<Producto> listarProductosCarrito(const std::vector<CarritoDeCompras>& carritos, int idCarrito) {
    for (std::size_t i = 0; i < carritos.size(); ++i) {
        if (carritos[i].idCarrito == idCarrito) {
            return carritos[i].productos;
        }
    }
    return {};
}
