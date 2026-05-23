#include <iostream>
using namespace std;
bool esprimo(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int numero;
    char continuar;
    do {
        cout << "ingrese un numero: ";
        cin >> numero;
        if (esprimo(numero)) {
            cout << "primo" << endl;
        } else {
            cout << "no primo" << endl;
        }
        cout << "desea ingresar otro numero? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
    cout << "programa terminado." << endl;
    return 0;
}