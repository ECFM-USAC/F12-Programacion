// 03_leer_valores.cpp
// Lee diferentes tipos de datos desde el teclado con std::cin.
//
// Compilar: g++ -o leer_valores 03_leer_valores.cpp
// Ejecutar: ./leer_valores

#include <iostream>
#include <string>

int main() {
    // --- Leer un entero ---
    int edad;
    std::cout << "Ingresa tu edad: ";
    std::cin >> edad;

    // --- Leer un decimal ---
    double estatura;
    std::cout << "Ingresa tu estatura (metros): ";
    std::cin >> estatura;

    // --- Leer un caracter ---
    char inicial;
    std::cout << "Ingresa la inicial de tu nombre: ";
    std::cin >> inicial;

    // --- Leer una cadena de texto (sin espacios) ---
    std::string carrera;
    std::cout << "Ingresa tu carrera (sin espacios): ";
    std::cin >> carrera;

    // --- Leer una linea completa (con espacios) ---
    std::cin.ignore();   // descarta el salto de linea que quedo en el buffer
    std::string nombre;
    std::cout << "Ingresa tu nombre completo: ";
    std::get.line(std::cin, nombre);

    // --- Mostrar resumen ---
    std::cout << "\n--- Resumen ---" << std::endl;
    std::cout << "Nombre  : " << nombre   << std::endl;
    std::cout << "Inicial : " << inicial  << std::endl;
    std::cout << "Edad    : " << edad     << std::endl;
    std::cout << "Estatura: " << estatura << " m" << std::endl;
    std::cout << "Carrera : " << carrera  << std::endl;

    return 0;
}
