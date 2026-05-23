#include <iostream>

int main() {
    long long n;
    // Leer el número entero positivo
    if (!(std::cin >> n)) return 0;

    long long suma = 0;

    // Mientras n sea mayor a 0, seguimos extrayendo dígitos
    while (n > 0) {
        suma += (n % 10); // Sumamos el último dígito (el residuo de n/10)
        n = n / 10;       // Eliminamos el último dígito (división entera)
    }

    // Imprimimos el resultado final
    std::cout << suma << std::endl;

    return 0;
}
