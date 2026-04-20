#include <iostream>
#include <vector>
#include <algorithm> 
void selection_sort(std::vector<int>& lista) {
    int n = lista.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;
            }
        }

        if (i != min_idx) {
            std::swap(lista[i], lista[min_idx]);
        }
    }
}

int main() {
    std::vector<int> lista = {64, 25, 12, 22, 11};

    selection_sort(lista);

    std::cout << "Lista ordenada: ";
    for (size_t i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << (i == lista.size() - 1 ? "" : ", ");
    }
    std::cout << std::endl;

    return 0;
}