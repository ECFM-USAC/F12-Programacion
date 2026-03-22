#include <iostream>
#include <vector>
#include <string>
using namespace std;

void burbuja(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool intercambiado = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) break;
    }
}

void seleccion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) swap(arr[i], arr[min_idx]);
    }
}

vector<int> mezclar(const vector<int>& izq, const vector<int>& der) {
    vector<int> resultado;
    resultado.reserve(izq.size() + der.size());
    int i = 0, j = 0;
    while (i < (int)izq.size() && j < (int)der.size()) {
        if (izq[i] <= der[j]) resultado.push_back(izq[i++]);
        else resultado.push_back(der[j++]);
    }
    while (i < (int)izq.size()) resultado.push_back(izq[i++]);
    while (j < (int)der.size()) resultado.push_back(der[j++]);
    return resultado;
}

vector<int> mergesort(const vector<int>& arr) {
    if ((int)arr.size() <= 1) return arr;
    int medio = arr.size() / 2;
    vector<int> izq = mergesort(vector<int>(arr.begin(), arr.begin() + medio));
    vector<int> der = mergesort(vector<int>(arr.begin() + medio, arr.end()));
    return mezclar(izq, der);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string algoritmo;
    int n;
    cin >> algoritmo >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> resultado;

    if (algoritmo == "burbuja") {
        burbuja(arr);
        resultado = arr;
    } else if (algoritmo == "seleccion") {
        seleccion(arr);
        resultado = arr;
    } else if (algoritmo == "mergesort") {
        resultado = mergesort(arr);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << resultado[i];
    }
    cout << '\n';
    return 0;
}
