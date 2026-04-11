#include <iostream>
#include <cstdlib> 
using namespace std;
int main() {
    char continuar;
    do {
        int x, suma = 0;
        cout << " ingresa un numero entero: ";
        cin >> x;
        x = abs(x);
        while (x > 0) {
            suma += x % 10;
            x /= 10;
        }
        cout << "La suma de los digitos es: " << suma << endl;
        cout << "deseas volverlo a intentar? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
    cout << "programa terminado." << endl;
    return 0;
}