#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& lista) {
    if (lista.size() > 1) {
        int mid = lista.size() / 2;

        std::vector<int> L(lista.begin(), lista.begin() + mid);
        std::vector<int> R(lista.begin() + mid, lista.end());

        merge_sort(L);
        merge_sort(R);

        size_t i = 0, j = 0, k = 0;

        while (i < L.size() && j < R.size()) {
            if (L[i] < R[j]) {
                lista[k] = L[i];
                i++;
            } else {
                lista[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < L.size()) {
            lista[k] = L[i];
            i++;
            k++;
        }

        while (j < R.size()) {
            lista[k] = R[j];
            j++;
            k++;
        }
    }
}

int main() {
    std::vector<int> lista = {38, 27, 43, 3, 9, 82, 10};

    merge_sort(lista);

    std::cout << "Lista ordenada: ";
    for (int n : lista) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}