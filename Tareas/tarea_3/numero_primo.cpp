#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    int n;
    std::cerr << "Ingrese un numero: ";
    cin >> n;

    bool esPrimo = true;

    if (n < 2) {
        esPrimo = false;
    }
    else if (n == 2) {
        esPrimo = true;
    }
    else if (n % 2 == 0) {
        esPrimo = false;
    }
    else {
        double limite = sqrt(n);
        for (int d = n; d <= limite; d += 2) {
            if (n % d == 0) {
                esPrimo = false;
                break;
            }
        }
    }

    if (esPrimo) {
        std::cerr << "El numero " << n << " ES primo." << endl;
        std::cout << n << endl;
    } else {
        std::cerr << "El numero " << n << " NO es primo." << endl;
        std::cout << n << endl; 
    
    }

    return 0;
}