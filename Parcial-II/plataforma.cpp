// =====================================================================
//  plataforma.cpp -- PLANTILLA. Implementen aqui TODAS las funciones de plataforma.h.
//  * No modifiquen plataforma.h.
//  * Aqui NO se usa cin/cout (eso va en main.cpp).
//  * Al DEFINIR productosBajoStock NO repitan el valor por defecto del parametro.
// =====================================================================
#include "plataforma.h"
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

std::vector<Usuario> cargarUsuarios() {
    std::vector<Usuario> usuarios;

    usuarios.push_back({1, "Juán Pérez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de Crédito"});

    usuarios.push_back({2, "Ana Gómez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "Paypal"});

    usuarios.push_back({3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia Bancaria"});

    usuarios.push_back({4, "Sofía Martínez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"});

    usuarios.push_back({5, "Diego Fernández", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta Débito"});

    return usuarios;
}

std::vector<Producto> cargarProductos() {
    std::vector<Producto> productos;

    productos.push_back({1, "Laptop", "Portatil con pantalla Full HD y SSD de 512GB", 89999, 10});
    productos.push_back({2, "Smartphone", "Telefono con camara de 108MP y carga rapida", 49950, 20});
    productos.push_back({3, "Tablet", "Dispositivo con pantalla tactil de 10 pulgadas", 29999, 15});
    productos.push_back({4, "Auriculares", "Audifonos inalambricos con cancelacion de ruido", 12999, 25});
    productos.push_back({5, "Teclado", "Teclado mecanico con iluminacion RGB", 8999, 30});
    productos.push_back({6, "Mouse", "Raton inalambrico con sensor optico de alta precision", 5999, 50});
    productos.push_back({7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12});
    productos.push_back({8, "Impresora", "Laser multifuncional con Wi-Fi", 17999, 18});
    productos.push_back({9, "Camara", "Camara digital con lente profesional", 79999, 8});
    productos.push_back({10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardiaco", 19999, 22});
    productos.push_back({11, "Silla Gamer", "Silla ergonomica ajustable con soporte lumbar", 29999, 14});
    productos.push_back({12, "Microondas", "Horno microondas con multiples funciones", 12999, 40});
    productos.push_back({13, "Refrigerador", "Frigorifico doble puerta con sistema No Frost", 119999, 5});
    productos.push_back({14, "Lavadora", "Lavadora automatica con capacidad de 10kg", 59999, 7});
    productos.push_back({15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35});
    productos.push_back({16, "Drone", "Drone con camara 4K y estabilizador", 69999, 9});
    productos.push_back({17, "Bocina Bluetooth", "Altavoz portatil con sonido envolvente", 8999, 33});
    productos.push_back({18, "Videocamara", "Videocamara profesional con grabacion en 4K", 99999, 6});
    productos.push_back({19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11});
    productos.push_back({20, "Bateria Externa", "Bateria de 20000mAh con carga rapida", 3999, 45});
    productos.push_back({21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28});
    productos.push_back({22, "Memoria USB", "Pendrive de 128GB", 2999, 60});
    productos.push_back({23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16});
    productos.push_back({24, "Joystick", "Control inalambrico para videojuegos", 7999, 20});
    productos.push_back({25, "Fuente de Poder", "Fuente de alimentacion para PC de 750W", 8999, 17});
    productos.push_back({26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32});
    productos.push_back({27, "Altavoces", "Par de bocinas estereo con subwoofer", 13999, 23});
    productos.push_back({28, "Webcam", "Camara web Full HD con microfono integrado", 6999, 37});
    productos.push_back({29, "Procesador", "CPU Intel i7 de ultima generacion", 34999, 9});
    productos.push_back({30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13});
    productos.push_back({31, "Memoria RAM", "Modulo de RAM DDR4 de 16GB", 7999, 41});
    productos.push_back({32, "Fuente Solar", "Panel solar portatil con bateria integrada", 24999, 4});
    productos.push_back({33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50});
    productos.push_back({34, "Termostato", "Termostato digital programable", 9999, 22});
    productos.push_back({35, "Smart Lock", "Cerradura electronica con huella digital", 19999, 6});
    productos.push_back({36, "Proyector", "Proyector LED con resolucion Full HD", 29999, 12});
    productos.push_back({37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38});
    productos.push_back({38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26});
    productos.push_back({39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55});
    productos.push_back({40, "Estabilizador", "Estabilizador de voltaje para dispositivos electronicos", 15999, 10});
    productos.push_back({41, "Cargador Inalambrico", "Base de carga inalambrica rapida", 4999, 30});
    productos.push_back({42, "HDD Externo", "Disco duro portatil de 4TB", 17999, 15});
    productos.push_back({43, "Microfono", "Microfono profesional para grabacion", 14999, 7});
    productos.push_back({44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20});
    productos.push_back({45, "Antena Wi-Fi", "Amplificador de señal inalambrico", 7999, 33});
    productos.push_back({46, "Climatizador", "Aire acondicionado portatil con control remoto", 29999, 5});
    productos.push_back({47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19});
    productos.push_back({48, "Capturadora", "Placa de captura de video en alta resolucion", 19999, 8});
    productos.push_back({49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42});
    productos.push_back({50, "Timbre Inteligente", "Timbre con camara y conexion a Wi-Fi", 14999, 10});

    return productos;
}

std::vector<Comentario> cargarComentarios() {
    std::vector<Comentario> comentarios;

    comentarios.push_back({1, "Laptop", "Juan Pérez", "Excelente rendimiento; muy rápida. ¡Me encanta!", "1/05/2025"});
    comentarios.push_back({2, "Smartphone", "Ana Gómez", "Buena cámara pero la batería dura poco.", "3/05/2025"});
    comentarios.push_back({3, "Tablet", "Carlos Ruiz", "No me gustó; pantalla de baja calidad.", "5/05/2025"});
    comentarios.push_back({4, "Auriculares", "Sofía Martínez", "Sonido aceptable pero el material parece frágil.", "6/05/2025"});
    comentarios.push_back({5, "Teclado", "Diego Fernández", "Muy buen teclado mecánico; excelente respuesta.", "8/05/2025"});
    comentarios.push_back({6, "Mouse", "Ana Gómez", "El sensor no es tan preciso como esperaba.", "10/05/2025"});
    comentarios.push_back({7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resolución. Muy satisfecho.", "12/05/2025"});
    comentarios.push_back({8, "Impresora", "Juan Pérez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"});
    comentarios.push_back({9, "Cámara", "Sofía Martínez", "Increíble calidad de imagen; fotos súper nítidas.", "15/05/2025"});
    comentarios.push_back({10, "Smartwatch", "Diego Fernández", "Buena batería; pero la pantalla no es muy brillante.", "18/05/2025"});
    comentarios.push_back({11, "Silla Gamer", "Lucía Rodríguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"});
    comentarios.push_back({12, "Microondas", "Andrés Ramírez", "Calienta bien pero hace mucho ruido.", "22/05/2025"});
    comentarios.push_back({13, "Refrigerador", "María García", "Espacioso y enfría rápido; muy recomendado.", "24/05/2025"});
    comentarios.push_back({14, "Lavadora", "Javier Martínez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"});
    comentarios.push_back({15, "Cafetera", "Carolina López", "Hace café delicioso; fácil de usar.", "28/05/2025"});
    comentarios.push_back({16, "Drone", "Daniel Castro", "Muy divertido pero la batería dura poco.", "30/05/2025"});
    comentarios.push_back({17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexión Bluetooth.", "1/06/2025"});
    comentarios.push_back({18, "Videocámara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "3/06/2025"});
    comentarios.push_back({19, "TV LED", "Fernanda Sánchez", "Imagen excelente pero el sonido podría mejorar.", "5/06/2025"});
    comentarios.push_back({20, "Batería Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "7/06/2025"});
    comentarios.push_back({21, "Disco Duro", "Gabriela Suárez", "Gran capacidad de almacenamiento; funciona rápido.", "9/06/2025"});
    comentarios.push_back({22, "Memoria USB", "Raúl Espinosa", "Buen tamaño pero la velocidad de transferencia es baja.", "11/06/2025"});
    comentarios.push_back({23, "Router", "Verónica Mendoza", "Señal potente; cubre toda la casa.", "13/06/2025"});
    comentarios.push_back({24, "Joystick", "Fabio Jiménez", "Cómodo y resistente; ideal para gaming.", "15/06/2025"});
    comentarios.push_back({25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"});
    comentarios.push_back({26, "SSD", "Silvia Gómez", "Velocidad increíble; mi PC va mucho más rápido ahora.", "19/06/2025"});
    comentarios.push_back({27, "Altavoces", "Martín Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"});
    comentarios.push_back({28, "Webcam", "Valentina Pérez", "Imagen clara pero el micrófono es deficiente.", "23/06/2025"});
    comentarios.push_back({29, "Procesador", "José Ramírez", "Rendimiento impecable; ideal para gaming y diseño.", "25/06/2025"});
    comentarios.push_back({30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalación fue complicada.", "27/06/2025"});
    comentarios.push_back({31, "Memoria RAM", "Julio Fernández", "Expande muy bien el rendimiento del sistema.", "29/06/2025"});
    comentarios.push_back({32, "Fuente Solar", "Amanda Castro", "Energía confiable pero la batería es pequeña.", "1/07/2025"});
    comentarios.push_back({33, "Control Remoto", "Pedro Duarte", "Fácil de usar; reconoce muchos dispositivos.", "3/07/2025"});
    comentarios.push_back({34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "5/07/2025"});
    comentarios.push_back({35, "Smart Lock", "Oscar Rodríguez", "Seguridad y tecnología en un solo dispositivo.", "7/07/2025"});
    comentarios.push_back({36, "Proyector", "Cristina Vargas", "Imagen nítida pero requiere una sala oscura.", "9/07/2025"});
    comentarios.push_back({37, "Switch Ethernet", "Mario Hernández", "Buena velocidad de conexión; estable.", "11/07/2025"});
    comentarios.push_back({38, "Reloj Digital", "Sofía Ramírez", "Pantalla atractiva pero la batería dura poco.", "13/07/2025"});
    comentarios.push_back({39, "Luces LED", "Andrea Gutiérrez", "Buenas opciones de colores; buen diseño.", "15/07/2025"});
    comentarios.push_back({40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"});
    comentarios.push_back({41, "Cargador Inalámbrico", "Patricia López", "Carga rápido pero requiere posicionamiento preciso.", "19/07/2025"});
    comentarios.push_back({42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"});
    comentarios.push_back({43, "Micrófono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"});
    comentarios.push_back({44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; útil en casa.", "25/07/2025"});
    comentarios.push_back({45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la señal pero el rango es limitado.", "27/07/2025"});
    comentarios.push_back({46, "Climatizador", "Estefanía Carrillo", "Enfría rápido pero es algo ruidoso.", "29/07/2025"});
    comentarios.push_back({47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electrónicos y programación.", "31/07/2025"});
    comentarios.push_back({48, "Capturadora", "Luisa Mejía", "Ideal para streaming y grabaciones en alta calidad.", "2/08/2025"});
    comentarios.push_back({49, "Smart Plug", "Victoria Torres", "Muy práctico; fácil de conectar y configurar.", "4/08/2025"});
    comentarios.push_back({50, "Timbre Inteligente", "Federico Montoya", "Buena cámara; útil para seguridad.", "6/08/2025"});

    return comentarios;
}

bool iniciarSesion(const std::vector<Usuario>& usuarios,
                   const std::string& correo,
                   const std::string& contrasena,
                   Usuario& usuarioOut) {
    for (const Usuario& usuario : usuarios) {
        if (usuario.correoElectronico == correo &&
            usuario.contrasena == contrasena) {
            usuarioOut = usuario;
            return true;
        }
    }

    return false;
}

std::vector<Producto> productosBajoStock(
    const std::vector<Producto>& productos, int umbral) {

    std::vector<Producto> resultado;

    for (const Producto& p : productos) {
        if (p.stock < umbral) {
            resultado.push_back(p);
        }
    }

    return resultado;
}

std::vector<Comentario> comentariosDesde(
    const std::vector<Comentario>& comentarios,
    const std::string& fecha) {

    std::vector<Comentario> resultado;

    int diaBase, mesBase, anioBase;
    char sep1, sep2;

    std::stringstream entrada(fecha);

    if (!(entrada >> diaBase >> sep1 >> mesBase >> sep2 >> anioBase) ||
        sep1 != '/' || sep2 != '/') {
        return resultado;
    }

    entrada >> std::ws;
    if (!entrada.eof()) {
        return resultado;
    }

    if (anioBase < 1 || mesBase < 1 || mesBase > 12) {
        return resultado;
    }

    int diasBase[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (anioBase % 400 == 0 ||
        (anioBase % 4 == 0 && anioBase % 100 != 0)) {
        diasBase[1] = 29;
    }

    if (diaBase < 1 || diaBase > diasBase[mesBase - 1]) {
        return resultado;
    }

    for (const Comentario& c : comentarios) {
        int dia, mes, anio;
        char s1, s2;

        std::stringstream flujo(c.fecha);

        if (!(flujo >> dia >> s1 >> mes >> s2 >> anio) ||
            s1 != '/' || s2 != '/') {
            continue;
        }

        flujo >> std::ws;
        if (!flujo.eof()) {
            continue;
        }

        if (anio < 1 || mes < 1 || mes > 12) {
            continue;
        }

        int diasMes[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        if (anio % 400 == 0 ||
            (anio % 4 == 0 && anio % 100 != 0)) {
            diasMes[1] = 29;
        }

        if (dia < 1 || dia > diasMes[mes - 1]) {
            continue;
        }

        if (anio > anioBase ||
            (anio == anioBase && mes > mesBase) ||
            (anio == anioBase && mes == mesBase &&
             dia >= diaBase)) {
            resultado.push_back(c);
        }
    }

    return resultado;
}

std::string convertirMayusculas(const std::string& texto) {
    std::string resultado = texto;

    for (char& letra : resultado) {
        letra = static_cast<char>(
            std::toupper(static_cast<unsigned char>(letra))
        );
    }

    return resultado;
}

std::vector<std::string> listarUsuariosFormateados(
    const std::vector<Usuario>& usuarios) {

    std::vector<std::string> resultado;

    for (const Usuario& u : usuarios) {
        std::string nombre = convertirMayusculas(u.nombre);

        std::string linea =
            std::to_string(u.idUsuario) + " | " +
            nombre + " | " +
            u.correoElectronico + " | " +
            u.direccion + " | " +
            u.metodoDePago;

        resultado.push_back(linea);
    }

    return resultado;
}

int siguienteIdCarrito(
    const std::vector<CarritoDeCompras>& carritos) {

    if (carritos.empty()) {
        return 1;
    }

    int mayorId = 0;

    for (const CarritoDeCompras& c : carritos) {
        if (c.idCarrito > mayorId) {
            mayorId = c.idCarrito;
        }
    }

    return mayorId + 1;
}

ResultadoCarrito agregarAlCarrito(
    std::vector<CarritoDeCompras>& carritos,
    std::vector<Producto>& productos,
    const Usuario& usuario,
    int idProducto) {

    auto producto = productos.end();

    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->idProducto == idProducto) {
            producto = it;
            break;
        }
    }

    if (producto == productos.end()) {
        return CARRITO_PRODUCTO_INVALIDO;
    }

    if (producto->stock <= 0) {
        return CARRITO_SIN_STOCK;
    }

    auto carrito = carritos.end();

    for (auto it = carritos.begin(); it != carritos.end(); ++it) {
        if (it->usuario.idUsuario == usuario.idUsuario) {
            carrito = it;
            break;
        }
    }

    if (carrito == carritos.end()) {
        CarritoDeCompras nuevo;
        nuevo.idCarrito = siguienteIdCarrito(carritos);
        nuevo.usuario = usuario;
        nuevo.subtotal = 0.0;
        nuevo.impuestos = 0.0;

        carritos.push_back(nuevo);
        carrito = carritos.end() - 1;
    }

    carrito->productos.push_back(*producto);

    carrito->subtotal += producto->precio;
    carrito->impuestos = carrito->subtotal * TASA_IVA;

    producto->stock--;

    return CARRITO_OK;
}

std::vector<Producto> listarProductosCarrito(
    const std::vector<CarritoDeCompras>& carritos,
    int idCarrito) {

    for (const CarritoDeCompras& carrito : carritos) {
        if (carrito.idCarrito == idCarrito) {
            return carrito.productos;
        }
    }

    return {};
}
