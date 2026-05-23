#include <iostream>
using namespace std;
int contarVocales(string texto) {
    int contar = 0;
    for (char x : texto) {
        x = tolower(x);
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            contar++;
        }
    }
    return contar;
}
int main() {
    string oracion;
    char continuar;
    do {
        cout << "ingrese una oracion: ";
        getline(cin, oracion);
        int total = contarVocales(oracion);
        cout << "total de vocales: " << total << endl;
        cout << "desea ingresar otra oracion? (s/n): ";
        cin >> continuar;
        cin.ignore(); 
    } while (continuar == 's' || continuar == 'S');
    cout << "programa terminado." << endl;
    return 0;
}