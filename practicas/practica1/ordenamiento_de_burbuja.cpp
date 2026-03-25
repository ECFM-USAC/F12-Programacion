#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> lista;         
    int n;
    std::cin >> n; // Leer el número de elementos
    for (int i = 0; i < n; i++) {
        int elemento;
        std::cin >> elemento; // Leer cada elemento
        lista.push_back(elemento); // Agregar el elemento a la lista
    }
    std::sort(lista.begin(), lista.end()bubble_sort(lista, n);
    for (const auto& elemento : lista) {
        std::cout << elemento << " "; // Imprimir cada elemento ordenado);
    for (const auto& elemento : lista) {
        std::cout << elemento << " "; // Imprimir cada elemento ordenado
    }
    return 0;
}
}

