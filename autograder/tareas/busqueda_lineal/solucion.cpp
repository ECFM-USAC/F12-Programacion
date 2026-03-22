#include <iostream>
#include <vector>
using namespace std;

int busqueda_lineal(const vector<int>& arr, int valor) {
    for (int i = 0; i < (int)arr.size(); i++) {    
        if (arr[i] == valor) return i;
    }
    return -1;
}

int main() {
    int n;
    cerr << "  ingrese  n: ";   // cerr -> stderr, el autograder lo ignora
    cin >> n;
    vector<int> arr(n);
    cerr << "  ingrese  la lista5: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int valor;  
    cin >> valor;

    cout << busqueda_lineal(arr, valor) << '\n';
    return 0;
}
