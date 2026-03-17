#include <iostream>

// Compilar: g++ -o suma_digitos suma_digitos.cpp
// Ejecutar: ./suma_digitos


int main() {
    int numero, suma = 0;
    std::cerr << "Ingrese un numero entero: ";
    std::cin >> numero;

    if (numero < 0) {
        std::cerr << "Por favor, ingrese un numero positivo." << std::endl;
        return 1; 
    }


    while (numero > 0) {
        int digito = numero % 10; 
        suma += digito;           
        numero /= 10;             
    }

    std::cerr << "La suma de los digitos es: " << std::endl; 
    std::cout << suma << std::endl;
    return 0; 
}