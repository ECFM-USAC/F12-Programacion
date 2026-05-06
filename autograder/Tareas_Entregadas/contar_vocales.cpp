#include <iostream>
#include <string>
#include <cctype> // Necesario para tolower()

int main() {
    std::string linea;
    // Usamos getline para leer toda la frase, incluyendo espacios
    if (!std::getline(std::cin, linea)) return 0;

    int contador = 0;

    // Recorremos la cadena carácter por carácter
    for (char c : linea) {
        // Convertimos a minúscula para comparar más fácil
        char letra = std::tolower(c);
        
        // Verificamos si es una vocal
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            contador++;
        }
    }

    // Imprimimos solo el número final
    std::cout << contador << std::endl;

    return 0;
}
