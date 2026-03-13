// 09_strings.cpp
// Operaciones comunes con std::string: longitud, concatenacion,
// busqueda, subcadena y conversion entre mayusculas/minusculas.
//
// Compilar: g++ -std=c++17 -o strings 09_strings.cpp
// Ejecutar: ./strings

#include <iostream>
#include <string>
#include <algorithm>   // transform, toupper, tolower

int main() {
    std::string nombre = "Programacion";

    // ── Longitud ──────────────────────────────────────────────────────────────
    std::cout << "Cadena  : " << nombre << std::endl;
    std::cout << "Longitud: " << nombre.length() << " caracteres" << std::endl;

    // ── Concatenacion ─────────────────────────────────────────────────────────
    std::string curso = nombre + " 1 — ECFM";
    std::cout << "Concat  : " << curso << std::endl;

    // ── Acceso por indice ─────────────────────────────────────────────────────
    std::cout << "Primer caracter: " << nombre[0]             << std::endl;
    std::cout << "Ultimo caracter: " << nombre[nombre.size()-1] << std::endl;

    // ── Subcadena ─────────────────────────────────────────────────────────────
    // substr(inicio, longitud)
    std::cout << "Subcadena [0,6): " << nombre.substr(0, 6)  << std::endl;

    // ── Busqueda ──────────────────────────────────────────────────────────────
    // find() retorna la posicion o string::npos si no se encuentra
    std::size_t pos = nombre.find("cion");
    if (pos != std::string::npos) {
        std::cout << "\"cion\" encontrado en posicion: " << pos << std::endl;
    } else {
        std::cout << "Subcadena no encontrada" << std::endl;
    }

    // ── Mayusculas / minusculas ───────────────────────────────────────────────
    std::string copia = nombre;
    std::transform(copia.begin(), copia.end(), copia.begin(), ::toupper);
    std::cout << "Mayusculas: " << copia << std::endl;

    std::transform(copia.begin(), copia.end(), copia.begin(), ::tolower);
    std::cout << "Minusculas: " << copia << std::endl;

    // ── Leer una cadena con espacios ──────────────────────────────────────────
    std::cout << "\nEscribe tu nombre completo: ";
    std::string ingresado;
    std::getline(std::cin, ingresado);
    std::cout << "Hola, " << ingresado << "! (" << ingresado.length()
              << " caracteres)" << std::endl;

    return 0;
}
