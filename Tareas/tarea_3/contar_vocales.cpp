#include <iostream>
// Compilar: g++ -o contar_vocales contar_vocales.cpp
// Ejecutar: ./contar_vocales

int main() {
    std::string texto;
    int contadorVocales = 0;

    std::cerr << "Ingrese un texto: ";
    std::getline(std::cin, texto);

    for (char c : texto) {
        char letra = std::tolower(c); 
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            contadorVocales++;
        }
    }

    std::cerr << "El numero de vocales en el texto es: " << std::endl;
    std::cout << contadorVocales << std::endl;

    return 0;
}