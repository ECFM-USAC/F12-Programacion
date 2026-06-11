#include <iostream>
using namespace std;
// bubble
void bubble(int arr[], int n) {
    for (int x = 0; x < n - 1; x++) {
        for (int y = 0; y < n - x - 1; y++) {
            if (arr[y] > arr[y + 1]) {
                swap(arr[y], arr[y + 1]);
            }
        }
    }
}
// seleccion
void Selection(int arr[], int n) {
    for (int x = 0; x < n - 1; x++) {
        int min = x;
        for (int y = x + 1; y < n; y++) {
            if (arr[y] < arr[min]) {
                min = y;
            }
        }
        swap(arr[x], arr[min]);
    }
}
// merge sort
void merge(int arr[], int start, int medium, int end) {
    int x = start, y = medium + 1, z = 0;
    int temp[100]; 
    while (x <= medium && y <= end) {
        if (arr[x] < arr[y]) {
            temp[z++] = arr[x++];
        } else {
            temp[z++] = arr[y++];
        }
    }
    while (x <= medium) {
        temp[z++] = arr[x++];
    }
    while (y <= end) {
        temp[z++] = arr[y++];
    }
    for (int x = start, y = 0; x <= end; x++, y++) {
        arr[x] = temp[y];
    }
}
void mergesort(int arr[], int start, int end) {
    if (start < end) {
        int medium = (start + end) / 2;
        mergesort(arr, start, medium);
        mergesort(arr, medium + 1, end);
        merge(arr, start, medium, end);
    }
}
// --------- MOSTRAR ---------
void mostrar(int arr[], int n) {
    for (int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }
    cout << endl;
}
// --------- MAIN ---------
int main() {
    int opcion, n;
    char repetir;
    do {
        cout << "\nCantidad de datos: ";
        cin >> n;
        int arr[1000];
        cout << "Ingrese los datos:\n";
        for (int x = 0; x < n; x++) {
            cin >> arr[x];
        }
        cout << "\nMetodos de ordenamiento:\n";
        cout << "1. bubble\n";
        cout << "2. Selection\n";
        cout << "3. Merge Sort\n";
        cout << "Elija una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                bubble(arr, n);
                break;
            case 2:
                Selection(arr, n);
                break;
            case 3:
                mergesort(arr, 0, n - 1);
                break;
            default:
                cout << "Opcion invalida\n";
                continue;
        }
        cout << "\nArreglo ordenado:\n";
        mostrar(arr, n);
        cout << "\nDesea repetir? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');
    return 0;
}