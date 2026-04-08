#include <iostream>
#include <vector>
#include <string>


//------- ORDENAMIENTO DE BURBUJA -------
void burbuja(std::vector<int>& lista, int n) {
    for (int i = 0; i < n-1; i++) {
        bool swap = false;
        for (int j = 0; j < n-1-i; j++) {
            if (lista[j] > lista[j+1]) {
                std::swap(lista[j], lista[j+1]);
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
    }
}

//------- ORDENAMIENTO POR SELECCION -------
void seleccion(std::vector<int>& lista, int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (lista[j] < lista[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(lista[i], lista[min_index]);
        }
    }
}

//------- ORDENAMIENTO POR FUSION -------
std::vector<int> mezclar(const std::vector<int>& izq, const std::vector<int>& der) {
    std::vector<int> resultado;
    int i = 0, j = 0;
    while (i < izq.size() && j < der.size()) {
        if (izq[i] < der[j]) {
            resultado.push_back(izq[i]);
            i++;
        } else {
            resultado.push_back(der[j]);
            j++;
        }
    }
    while (i < izq.size()) {
        resultado.push_back(izq[i]);
        i++;
    }
    while (j < der.size()) {
        resultado.push_back(der[j]);
        j++;
    }
    return resultado;
}

    std::vector<int> mergesort(const std::vector<int>& lista) {
        if (lista.size() <= 1) {
            return lista;
        }
        int medio = lista.size() / 2;
        std::vector<int> izq(lista.begin(), lista.begin() + medio);
        std::vector<int> der(lista.begin() + medio, lista.end());
        izq = mergesort(izq);
        der = mergesort(der);  

        return mezclar(izq, der);


}
        
//------- MAIN -------
int main() {
    std::string algoritmo;
    int n;
    std::cin >> algoritmo >> n;
    std::vector<int> lista(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }
    if (algoritmo == "burbuja") {
        burbuja(lista, n);
    } else if (algoritmo == "seleccion") {
        seleccion(lista, n);
    } else if (algoritmo == "mergesort") {
        lista = mergesort(lista);
    }
    for (int i = 0; i < n; i++) {
        std::cout << lista[i] << " ";
    }
    
}
