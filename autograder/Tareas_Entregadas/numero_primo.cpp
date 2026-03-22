#include <iostream>
#include <cmath>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    // Casos especiales
    if (n < 2) {
        std::cout << "no primo";
        return 0;
    }
    if (n == 2) {
        std::cout << "primo";
        return 0;
    }
    if (n % 2 == 0) {
        std::cout << "no primo";
        return 0;
    }

    // Algoritmo eficiente: revisar hasta la raíz de n
    bool es_primo = true;
    int limite = std::sqrt(n);
    
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            es_primo = false;
            break;
        }
    }

    if (es_primo) std::cout << "primo";
    else std::cout << "no primo";

    return 0;
}



