// =====================================================================
//  plataforma.cpp -- PLANTILLA. Implementen aqui TODAS las funciones de plataforma.h.
//  * No modifiquen plataforma.h.
//  * Aqui NO se usa cin/cout (eso va en main.cpp).
//  * Al DEFINIR productosBajoStock NO repitan el valor por defecto del parametro.
// =====================================================================
#include "plataforma.h"
#include <cctype>

// Helper interno para convertir "dd/mm/yyyy" a entero YYYYMMDD y permitir comparaciones
static int parseFecha(const std::string& fechaStr) {
    size_t p1 = fechaStr.find('/');
    if (p1 == std::string::npos) return -1;
    size_t p2 = fechaStr.find('/', p1 + 1);
    if (p2 == std::string::npos) return -1;
    
    try {
        int d = std::stoi(fechaStr.substr(0, p1));
        int m = std::stoi(fechaStr.substr(p1 + 1, p2 - p1 - 1));
        int y = std::stoi(fechaStr.substr(p2 + 1));
        return y * 10000 + m * 100 + d;
    } catch (...) {
        return -1;
    }
}

std::vector<Usuario> cargarUsuarios() {
    return {
        {1, "Juan Perez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de credito"},
        {2, "Ana Gomez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"},
        {3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia bancaria"},
        {4, "Sofia Martinez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"},
        {5, "Diego Fernandez", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta debito"}
    };
}

std::vector<Producto> cargarProductos() {
    return {
        {1, "Laptop", "Portatil con pantalla Full HD y SSD de 512GB", 89999, 10},
        {2, "Smartphone", "Telefono con camara de 108MP y carga rapida", 49950, 20},
        {3, "Tablet", "Dispositivo con pantalla tactil de 10 pulgadas", 29999, 15},
        {4, "Auriculares", "Audifonos inalambricos con cancelacion de ruido", 12999, 25},
        {5, "Teclado", "Teclado mecanico con iluminacion RGB", 8999, 30},
        {6, "Mouse", "Raton inalambrico con sensor optico de alta precision", 5999, 50},
        {7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12},
        {8, "Impresora", "Laser multifuncional con Wi-Fi", 17999, 18},
        {9, "Camara", "Camara digital con lente profesional", 79999, 8},
        {10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardiaco", 19999, 22},
        {11, "Silla Gamer", "Silla ergonomica ajustable con soporte lumbar", 29999, 14},
        {12, "Microondas", "Horno microondas con multiples funciones", 12999, 40},
        {13, "Refrigerador", "Frigorifico doble puerta con sistema No Frost", 119999, 5},
        {14, "Lavadora", "Lavadora automatica con capacidad de 10kg", 59999, 7},
        {15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35},
        {16, "Drone", "Drone con camara 4K y estabilizador", 69999, 9},
        {17, "Bocina Bluetooth", "Altavoz portatil con sonido envolvente", 8999, 33},
        {18, "Videocamara", "Videocamara profesional con grabacion en 4K", 99999, 6},
        {19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11},
        {20, "Bateria Externa", "Bateria de 20000mAh con carga rapida", 3999, 45},
        {21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28},
        {22, "Memoria USB", "Pendrive de 128GB", 2999, 60},
        {23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16},
        {24, "Joystick", "Control inalambrico para videojuegos", 7999, 20},
        {25, "Fuente de Poder", "Fuente de alimentacion para PC de 750W", 8999, 17},
        {26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32},
        {27, "Altavoces", "Par de bocinas estereo con subwoofer", 13999, 23},
        {28, "Webcam", "Camara web Full HD con microfono integrado", 6999, 37},
        {29, "Procesador", "CPU Intel i7 de ultima generacion", 34999, 9},
        {30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13},
        {31, "Memoria RAM", "Modulo de RAM DDR4 de 16GB", 7999, 41},
        {32, "Fuente Solar", "Panel solar portatil con bateria integrada", 24999, 4},
        {33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50},
        {34, "Termostato", "Termostato digital programable", 9999, 22},
        {35, "Smart Lock", "Cerradura electronica con huella digital", 19999, 6},
        {36, "Proyector", "Proyector LED con resolucion Full HD", 29999, 12},
        {37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38},
        {38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26},
        {39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55},
        {40, "Estabilizador", "Estabilizador de voltaje para dispositivos electronicos", 15999, 10},
        {41, "Cargador Inalambrico", "Base de carga inalambrica rapida", 4999, 30},
        {42, "HDD Externo", "Disco duro portatil de 4TB", 17999, 15},
        {43, "Microfono", "Microfono profesional para grabacion", 14999, 7},
        {44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20},
        {45, "Antena Wi-Fi", "Amplificador de senal inalambrico", 7999, 33},
        {46, "Climatizador", "Aire acondicionado portatil con control remoto", 29999, 5},
        {47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19},
        {48, "Capturadora", "Placa de captura de video en alta resolucion", 19999, 8},
        {49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42},
        {50, "Timbre Inteligente", "Timbre con camara y conexion a Wi-Fi", 14999, 10}
    };
}

std::vector<Comentario> cargarComentarios() {
    return {
        {1, "Laptop", "Juan Perez", "Excelente rendimiento; muy rapida. ¡Me encanta!", "1/05/2025"},
        {2, "Smartphone", "Ana Gomez", "Buena camara pero la bateria dura poco.", "3/05/2025"},
        {3, "Tablet", "Carlos Ruiz", "No me gusto; pantalla de baja calidad.", "5/05/2025"},
        {4, "Auriculares", "Sofia Martinez", "Sonido aceptable pero el material parece fragil.", "6/05/2025"},
        {5, "Teclado", "Diego Fernandez", "Muy buen teclado mecanico; excelente respuesta.", "8/05/2025"},
        {6, "Mouse", "Ana Gomez", "El sensor no es tan preciso como esperaba.", "10/05/2025"},
        {7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resolucion. Muy satisfecho.", "12/05/2025"},
        {8, "Impresora", "Juan Perez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"},
        {9, "Camara", "Sofia Martinez", "Increible calidad de imagen; fotos super nitidas.", "15/05/2025"},
        {10, "Smartwatch", "Diego Fernandez", "Buena bateria; pero la pantalla no es muy brillante.", "18/05/2025"},
        {11, "Silla Gamer", "Lucia Rodriguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"},
        {12, "Microondas", "Andres Ramirez", "Calienta bien pero hace mucho ruido.", "22/05/2025"},
        {13, "Refrigerador", "Maria Garcia", "Espacioso y enfria rapido; muy recomendado.", "24/05/2025"},
        {14, "Lavadora", "Javier Martinez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"},
        {15, "Cafetera", "Carolina Lopez", "Hace cafe delicioso; facil de usar.", "28/05/2025"},
        {16, "Drone", "Daniel Castro", "Muy divertido pero la bateria dura poco.", "30/05/2025"},
        {17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexion Bluetooth.", "1/06/2025"},
        {18, "Videocamara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "3/06/2025"},
        {19, "TV LED", "Fernanda Sanchez", "Imagen excelente pero el sonido podria mejorar.", "5/06/2025"},
        {20, "Bateria Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "7/06/2025"},
        {21, "Disco Duro", "Gabriela Suarez", "Gran capacidad de almacenamiento; funciona rapido.", "9/06/2025"},
        {22, "Memoria USB", "Raul Espinosa", "Buen tamano pero la velocidad de transferencia es baja.", "11/06/2025"},
        {23, "Router", "Veronica Mendoza", "Senal potente; cubre toda la casa.", "13/06/2025"},
        {24, "Joystick", "Fabio Jimenez", "Comodo y resistente; ideal para gaming.", "15/06/2025"},
        {25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"},
        {26, "SSD", "Silvia Gomez", "Velocidad increible; mi PC va mucho mas rapido ahora.", "19/06/2025"},
        {27, "Altavoces", "Martin Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"},
        {28, "Webcam", "Valentina Perez", "Imagen clara pero el microfono es deficiente.", "23/06/2025"},
        {29, "Procesador", "Jose Ramirez", "Rendimiento impecable; ideal para gaming y diseno.", "25/06/2025"},
        {30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalacion fue complicada.", "27/06/2025"},
        {31, "Memoria RAM", "Julio Fernandez", "Expande muy bien el rendimiento del sistema.", "29/06/2025"},
        {32, "Fuente Solar", "Amanda Castro", "Energia confiable pero la bateria es pequena.", "1/07/2025"},
        {33, "Control Remoto", "Pedro Duarte", "Facil de usar; reconoce muchos dispositivos.", "3/07/2025"},
        {34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "5/07/2025"},
        {35, "Smart Lock", "Oscar Rodriguez", "Seguridad y tecnologia en un solo dispositivo.", "7/07/2025"},
        {36, "Proyector", "Cristina Vargas", "Imagen nitida pero requiere una sala oscura.", "9/07/2025"},
        {37, "Switch Ethernet", "Mario Hernandez", "Buena velocidad de conexion; estable.", "11/07/2025"},
        {38, "Reloj Digital", "Sofia Ramirez", "Pantalla atractiva pero la bateria dura poco.", "13/07/2025"},
        {39, "Luces LED", "Andrea Gutierrez", "Buenas opciones de colores; buen diseno.", "15/07/2025"},
        {40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"},
        {41, "Cargador Inalambrico", "Patricia Lopez", "Carga rapido pero requiere posicionamiento preciso.", "19/07/2025"},
        {42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"},
        {43, "Microfono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"},
        {44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; util en casa.", "25/07/2025"},
        {45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la senal pero el rango es limitado.", "27/07/2025"},
        {46, "Climatizador", "Estefania Carrillo", "Enfria rapido pero es algo ruidoso.", "29/07/2025"},
        {47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electronicos y programacion.", "31/07/2025"},
        {48, "Capturadora", "Luisa Mejia", "Ideal para streaming y grabaciones en alta calidad.", "2/08/2025"},
        {49, "Smart Plug", "Victoria Torres", "Muy practico; facil de conectar y configurar.", "4/08/2025"},
        {50, "Timbre Inteligente", "Federico Montoya", "Buena camara; util para seguridad.", "6/08/2025"}
    };
}

bool iniciarSesion(const std::vector<Usuario>& usuarios, const std::string& correo,
                   const std::string& contrasena, Usuario& usuarioOut) {
    for (const auto& u : usuarios) {
        if (u.correoElectronico == correo && u.contrasena == contrasena) {
            usuarioOut = u;
            return true;
        }
    }
    return false;
}

std::vector<Producto> productosBajoStock(const std::vector<Producto>& productos, int umbral) {
    std::vector<Producto> productosBajos;
    for (const auto& p : productos) {
        if (p.stock < umbral) {
            productosBajos.push_back(p);
        }
    }
    return productosBajos;
}

std::vector<Comentario> comentariosDesde(const std::vector<Comentario>& comentarios, const std::string& fecha) {
    std::vector<Comentario> comentariosFiltrados;
    int fechaReferencia = parseFecha(fecha);
    if (fechaReferencia == -1) {
        return comentariosFiltrados;
    }

    for (const auto& c : comentarios) {
        int fechaComentario = parseFecha(c.fecha);
        if (fechaComentario != -1 && fechaComentario >= fechaReferencia) {
            comentariosFiltrados.push_back(c);
        }
    }
    return comentariosFiltrados;
}

std::vector<std::string> listarUsuariosFormateados(const std::vector<Usuario>& usuarios) {
    std::vector<std::string> resultado;
    for (const auto& u : usuarios) {
        std::string nombreMayus = u.nombre;
        for (char& c : nombreMayus) {
            if (c >= 'a' && c <= 'z') {
                c = std::toupper(c);
            }
        }
        std::string formato = std::to_string(u.idUsuario) + " | " + nombreMayus + " | " + 
                              u.correoElectronico + " | " + u.direccion + " | " + u.metodoDePago;
        resultado.push_back(formato);
    }
    return resultado;
}

int siguienteIdCarrito(const std::vector<CarritoDeCompras>& carritos) {
    if (carritos.empty()) return 1;
    return carritos.back().idCarrito + 1;
}

ResultadoCarrito agregarAlCarrito(std::vector<CarritoDeCompras>& carritos, std::vector<Producto>& productos,
                                  const Usuario& usuario, int idProducto) {
    Producto* productoSeleccionado = nullptr;
    for (auto& p : productos) {
        if (p.idProducto == idProducto) {
            productoSeleccionado = &p;
            break;
        }
    }
    if (!productoSeleccionado) return CARRITO_PRODUCTO_INVALIDO;
    if (productoSeleccionado->stock == 0) return CARRITO_SIN_STOCK;

    CarritoDeCompras* carritoUsuario = nullptr;
    for (auto& c : carritos) {
        if (c.usuario.idUsuario == usuario.idUsuario) {
            carritoUsuario = &c;
            break;
        }
    }
    
    if (!carritoUsuario) {
        CarritoDeCompras nuevoCarrito;
        nuevoCarrito.idCarrito = siguienteIdCarrito(carritos);
        nuevoCarrito.usuario = usuario;
        nuevoCarrito.subtotal = 0.0;
        nuevoCarrito.impuestos = 0.0;
        carritos.push_back(nuevoCarrito);
        carritoUsuario = &carritos.back();
    }

    productoSeleccionado->stock--;
    carritoUsuario->productos.push_back(*productoSeleccionado);
    carritoUsuario->subtotal += productoSeleccionado->precio;
    carritoUsuario->impuestos = carritoUsuario->subtotal * TASA_IVA;

    return CARRITO_OK;
}

std::vector<Producto> listarProductosCarrito(const std::vector<CarritoDeCompras>& carritos, int idCarrito) {
    for (const auto& c : carritos) {
        if (c.idCarrito == idCarrito) {
            return c.productos;
        }
    }
    return {};
}