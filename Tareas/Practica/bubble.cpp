#include <iostream>
#include <vector>
#include <algorithm> // Para std::swap

void bubble_sort(std::vector<int>& lista) {
    int n = lista.size();

    for (int i = 0; i < n; i++) {
        bool swapped = false;

        // El último elemento i ya está en su lugar, por eso n - i - 1
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                // Intercambio de valores
                std::swap(lista[j], lista[j + 1]);
                swapped = true;
            }
        }

        // Si no hubo intercambios en el ciclo interno, la lista ya está ordenada
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> lista = {64, 34, 25, 12, 22, 11, 90};

    bubble_sort(lista);

    std::cout << "Lista ordenada: ";
    for (int x : lista) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}