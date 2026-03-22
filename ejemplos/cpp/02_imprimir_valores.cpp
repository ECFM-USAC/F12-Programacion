// 02_imprimir_valores.cpp
// Declara variables de distintos tipos y las imprime en pantalla.
//
// Compilar: g++ -o imprimir_valores 02_imprimir_valores.cpp
// Ejecutar: ./imprimir_valores

#include <iostream>
#include <string>   // necesario para usar std::string

int main() {
    // --- Tipos de datos basicos ---
    int      entero    = 42;
    double   decimal   = 3.14159;
    char     caracter  = 'A';
    bool     verdadero = true;
    std::string texto  = "Fisica";

    // --- Imprimir cada variable ---
    std::cout << "Entero   : " << entero    << std::endl;
    std::cout << "Decimal  : " << decimal   << std::endl;
    std::cout << "Caracter : " << caracter  << std::endl;
    std::cout << "Booleano : " << verdadero << std::endl;   // imprime 1 (true) o 0 (false)
    std::cout << "Texto    : " << texto     << std::endl;

    // --- Operaciones aritmeticas basicas ---
    int a = 10, b = 3;
    std::cout << "\nOperaciones con a=" << a << " y b=" << b << ":" << std::endl;
    std::cout << "  Suma        : " << a + b << std::endl;
    std::cout << "  Resta       : " << a - b << std::endl;
    std::cout << "  Multiplicar : " << a * b << std::endl;
    std::cout << "  Division    : " << a / b << std::endl;   // division entera
    std::cout << "  Division    : " << 10 / 3.0 << std::endl; //Si necesitas decimales, al menos uno de los números debe ser decimal
    std::cout << "  Modulo      : " << a % b << std::endl;   // residuo

    return 0;
}
