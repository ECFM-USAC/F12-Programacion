#include <iostream>
using namespace std;

// --------- BUSQUEDA LINEAL ---------
int busquedaLineal(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i; // retorna la posición donde se encontró
        }
    }
    return -1; // no encontrado
}

// --------- MAIN ---------
int main() {
    int n, valor;
    char repetir;

    do {
        cout << "\nCantidad de datos: ";
        cin >> n;

        int arr[1000];

        cout << "Ingrese los datos:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "\nIngrese el valor a buscar: ";
        cin >> valor;

        int resultado = busquedaLineal(arr, n, valor);

        if (resultado != -1) {
            cout << "Valor encontrado en la posicion: " << resultado << endl;
        } else {
            cout << "Valor no encontrado.\n";
        }

        cout << "\nDesea repetir? (s/n): ";
        cin >> repetir;

    } while (repetir == 's' || repetir == 'S');

    return 0;
}