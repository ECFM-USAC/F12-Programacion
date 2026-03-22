#include <iostream>
#include <vector>
using namespace std;
int busquedaDosEnDos(const vector<int>& lista, int objetivo) {
    int n = lista.size();
    for (int i = 0; i < n; i += 2) {
        if (lista[i] == objetivo) {
            return i;
        }
        if (i + 1 < n && lista[i + 1] == objetivo) {
            return i + 1;
        }
    }
    return -1; 
}
int main() {
    vector<int> lista;
    int n, x;
    cout << "ingrese la cantidad de elementos: ";
    cin >> n;
    cout << "ingrese los elementos:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        lista.push_back(x);
    }
    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        int objetivo;
        cout << "\ningrese el numero a buscar: ";
        cin >> objetivo;
        int resultado = busquedaDosEnDos(lista, objetivo);
        if (resultado != -1) {
            cout << "objetivo encontrado en : " << resultado << endl;
        } else {
            cout << "objetivo no existe" << endl;
        }

        cout << "\n desea buscar otro numero? (s/n): ";
        cin >> continuar;
    }
    return 0;
}